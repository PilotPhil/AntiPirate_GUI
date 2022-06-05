#include "yolo.h"

YOLO::YOLO(Net_config config) {
    cout << "Net use " << config.netname << endl;
    this->confThreshold = config.confThreshold;				// ��ʼ�����Ŷ�����
    this->nmsThreshold = config.nmsThreshold;				// ��ʼ��nms����
    this->inpWidth = config.inpWidth;						// ��ʼ������ͼ����
    this->inpHeight = config.inpHeight;						// ��ʼ������ͼ��߶�
    strcpy(this->netname, config.netname.c_str());	// ��ʼ����������

    ifstream ifs(config.classesFile.c_str());
    string line;
    while (getline(ifs, line)) this->classes.push_back(line);		// ��coco.name�����������

    //this->net = readNetFromONNX(config.modelConfiguration);		// ���������ļ���Ȩ���ļ�
    this->net = readNetFromDarknet(config.modelConfiguration);		// ���������ļ���Ȩ���ļ�
    this->net.setPreferableBackend(DNN_BACKEND_OPENCV);		 // ���ݼ�������������ü��ٷ�����֧��cpu��cuda��fpga��������Կ�Դ��
    this->net.setPreferableTarget(DNN_TARGET_CPU);
}


void YOLO::setcapSize(int width, int height) {
    this->capHeight = height;
    this->capWidth = width;
    this->scaleHeight = float(this->capHeight) / this->inpHeight;
    this->scaleWidth = float(this->capWidth) / this->inpWidth;
}


void YOLO::postprocess(Mat& frame, const vector<Mat>& outs)   // Remove the bounding boxes with low confidence using non-maxima suppression
{
    vector<int> classIds;
    vector<float> confidences;
    vector<float> scores;
    vector<Rect> boxes;

    for (size_t i = 0; i < outs.size(); ++i) {
        // Scan through all the bounding boxes output from the network and keep only the
        // ones with high confidence scores. Assign the box's class label as the class
        // with the highest score for the box.
        float* data = (float*)outs[i].data;
        for (int j = 0; j < outs[i].rows; ++j, data += outs[i].cols) {
            Mat score = outs[i].row(j).colRange(5, outs[i].cols);		// ʹ��80�����ĸ�����Ϊscore
            Point classIdPoint;
            double max_score;
            // Get the value and location of the maximum score
            minMaxLoc(score, 0, &max_score, 0, &classIdPoint);		// ��ѯscore������Ԫ�ؼ���λ��
            if (data[4] > this->confThreshold) {		// data[4]�����Ŷ�
                int centerX = (int)(data[0] * this->scaleWidth);		// yolo�����λ���������ģ������ͼ���С��
                int centerY = (int)(data[1] * this->scaleHeight);		// �����Ҫ���м򵥵�����
                int width = (int)(data[2] * this->scaleWidth);
                int height = (int)(data[3] * this->scaleHeight);
                int left = centerX - width / 2;
                int top = centerY - height / 2;

                classIds.push_back(classIdPoint.x);
                confidences.push_back(data[classIdPoint.x+5]);
                scores.push_back(max_score*data[4]);
                boxes.push_back(Rect(left, top, width, height));
            }
        }
    }

    // Perform non maximum suppression to eliminate redundant overlapping boxes with
    // lower confidences
    vector<int> indices;
    NMSBoxes(boxes, scores, this->confThreshold, this->nmsThreshold, indices);  // ʹ��opencv�Դ���nms
    for (size_t i = 0; i < indices.size(); ++i) {
        int idx = indices[i];
        Rect box = boxes[idx];
        this->drawPred(classIds[idx], confidences[idx], box.x, box.y,
            box.x + box.width, box.y + box.height, frame);
    }
}

void YOLO::drawPred(int classId, float conf, int left, int top, int right, int bottom, Mat& frame)   // Draw the predicted bounding box
{
    //Draw a rectangle displaying the bounding box
    rectangle(frame, Point(left, top), Point(right, bottom), Scalar(0, 0, 255), 3);

    //Get the label for the class name and its confidence
    string label = format("%.2f", conf);
    if (!this->classes.empty()) {
        CV_Assert(classId < (int)this->classes.size());
        label = this->classes[classId] + ":" + label;
    }

    //Display the label at the top of the bounding box
    int baseLine;
    Size labelSize = getTextSize(label, FONT_HERSHEY_SIMPLEX, 0.5, 1, &baseLine);
    top = max(top, labelSize.height);
    // rectangle(frame, Point(left, top - int(1.5 * labelSize.height)), Point(left + int(1.5 * labelSize.width), top + baseLine), Scalar(0, 255, 0), FILLED);
    putText(frame, label, Point(left, top), FONT_HERSHEY_SIMPLEX, 0.75, Scalar(0, 255, 0), 2);
}

void YOLO::detect(Mat& frame) {
    Mat blob;
    blobFromImage(frame, blob, double(1 / 255.0), Size(this->inpWidth, this->inpHeight), Scalar(0, 0, 0), true, false);
    // blobFromImage����Ԥ������һ����resize����ȥ��ֵ��������ɫ����ɫͨ���������вü�
    this->net.setInput(blob);		// ����ģ��
    vector<Mat> outs_blob;
    vector<Mat> outs;
    vector<String> names = this->net.getUnconnectedOutLayersNames();		// ��ȡ�����������Ϣ
    this->net.forward(outs_blob, names);		// ģ�͵�����������outs_blob���������ǵ�yoloģ��������yolo�㣬������������
    int i = 0;
    for (i = 0; i < outs_blob.size(); i++) {
        vector<Mat> out;
        // ���ǵ�onnx�������һ��ά��Ϊ num_samples*1*(num_anchors*grid*grid)*6 ��4ά�Ⱦ�������һ��blob����
        // �����Ҫʹ��imagesFromBlob��blobתΪmat��һ��blob���ܶ�Ӧ���mat��������Ϊnum_samples
        // ��������ֻ��һ����������������ֻ��out[0]
        // ����yolo��ֱ����һ��blob
        imagesFromBlob(outs_blob[i], out);
        outs.push_back(out[0]);
    }
    this->postprocess(frame, outs);			// ����

    vector<double> layersTimes;
    double freq = getTickFrequency() / 1000;   // ���ڷ���CPU��Ƶ�ʡ�get Tick Frequency������ĵ�λ����
    double t = net.getPerfProfile(layersTimes) / freq;		// getPerfProfile �����������   ����/Ƶ��=ʱ��
    string label = format("%s Inference time : %.2f ms", this->netname, t);
    putText(frame, label, Point(0, 30), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255), 2);
    //imwrite(format("%s_out.jpg", this->netname), frame);
}
