#include "yolo.h"

YOLO::YOLO(NetConfig config, bool use_cuda, QObject *parent) {
  cout << "Net use " << config.netname << endl;
  this->confThreshold = config.confThreshold;
  this->nmsThreshold = config.nmsThreshold;
  this->inpWidth = config.inpWidth;
  this->inpHeight = config.inpHeight;
  strcpy(this->netname, config.netname.c_str());

  ifstream ifs(config.classesFile.c_str());
  string line;
  while (getline(ifs, line))
    this->classes.push_back(line);

  this->net =
      readNetFromDarknet(config.modelConfiguration, config.modelWeights);

  if (use_cuda == true) {
    this->net.setPreferableBackend(DNN_BACKEND_CUDA);
    this->net.setPreferableTarget(DNN_TARGET_CUDA);
  } else {
    this->net.setPreferableBackend(DNN_BACKEND_OPENCV);
    this->net.setPreferableTarget(DNN_TARGET_CPU);
  }
}

void YOLO::postprocess(
    Mat &frame,
    const vector<Mat> &outs) // Remove the bounding boxes with low confidence
                             // using non-maxima suppression
{
  vector<int> classIds;
  vector<float> confidences;
  vector<Rect> boxes;

  for (size_t i = 0; i < outs.size(); ++i) {
    // Scan through all the bounding boxes output from the network and keep only
    // the ones with high confidence scores. Assign the box's class label as the
    // class with the highest score for the box.
    float *data = (float *)outs[i].data;
    for (int j = 0; j < outs[i].rows; ++j, data += outs[i].cols) {
      Mat scores = outs[i].row(j).colRange(5, outs[i].cols);
      Point classIdPoint;
      double confidence;
      // Get the value and location of the maximum score
      minMaxLoc(scores, 0, &confidence, 0, &classIdPoint);
      if (confidence > this->confThreshold) {
        int centerX = (int)(data[0] * frame.cols);
        int centerY = (int)(data[1] * frame.rows);
        int width = (int)(data[2] * frame.cols);
        int height = (int)(data[3] * frame.rows);
        int left = centerX - width / 2;
        int top = centerY - height / 2;

        classIds.push_back(classIdPoint.x);
        confidences.push_back((float)confidence);
        boxes.push_back(Rect(left, top, width, height));
      }
    }
  }

  // Perform non maximum suppression to eliminate redundant overlapping boxes
  // with lower confidences
  vector<int> indices;
  NMSBoxes(boxes, confidences, this->confThreshold, this->nmsThreshold,
           indices);

  this->_resList.clear();

  for (size_t i = 0; i < indices.size(); ++i) {
    int idx = indices[i];

    TrackingBox tb;
    tb.className=classes[classIds[idx]];
    tb.id=-1;
    tb.distance=-1;
    tb.confidence=confidences[idx];
    tb.box=boxes[idx];

    this->_resList.push_back(tb);
  }
}


float YOLO::detect(Mat &frame) {
  Mat blob;
  blobFromImage(frame, blob, 1 / 255.0, Size(this->inpWidth, this->inpHeight),
                Scalar(0, 0, 0), true, false);
  this->net.setInput(blob);
  vector<Mat> outs;
  this->net.forward(outs, this->net.getUnconnectedOutLayersNames());
  this->postprocess(frame, outs);

  vector<double> layersTimes;
  double freq = getTickFrequency() / 1000;
  double t = net.getPerfProfile(layersTimes) / freq;
  //  string label = format("IFT : %.2f ms", t);
  //  putText(frame, label, Point(0, 60), FONT_HERSHEY_SIMPLEX, 1,
  //          Scalar(0, 0, 255), 2);

  //  label=format("RFPS : %.2f", 1000.0/t);
  //  putText(frame, label, Point(0, 90), FONT_HERSHEY_SIMPLEX, 1,
  //          Scalar(0, 0, 255), 2);
  // imwrite(format("%s_out.jpg", this->netname), frame);

  return t;
}
