#ifndef YOLO_H
#define YOLO_H

#include <QObject>
#include <fstream>
#include <iostream>
#include <opencv2/dnn.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <QList>
#include <sstream>

#include "NetConfig.h"
#include "TrackBox.h"

using namespace cv;
using namespace dnn;
using namespace std;

class YOLO : public QObject {
  Q_OBJECT
public:
  YOLO(NetConfig config, bool use_cuda = false,QObject *parent = nullptr);
  float detect(Mat &frame);

  vector<TrackingBox> _resList;

private:
  float confThreshold;
  float nmsThreshold;
  int inpWidth;
  int inpHeight;
  char netname[20];
  vector<string> classes;
  Net net;
  void postprocess(Mat &frame, const vector<Mat> &outs);

signals:
  void SendDetectResult(vector<TrackingBox> res);
};

#endif
