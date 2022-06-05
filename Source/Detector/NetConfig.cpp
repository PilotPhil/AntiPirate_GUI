#include "NetConfig.h"

string NetConfig::prefix="/home/dwb/Documents/Project/TestWeights/";

NetConfig::NetConfig(const float _confThreshold, const float _nmsThreshold,
                     const int _inpWidth, const int _inpHeight,
                     const string &_classesFile,
                     const string &_modelConfiguration,
                     const string &_modelWeights, const string &_netname)
    : confThreshold(_confThreshold), nmsThreshold(_nmsThreshold),
      inpWidth(_inpWidth), inpHeight(_inpHeight), classesFile(_classesFile),
      modelConfiguration(_modelConfiguration), modelWeights(_modelWeights),
      netname(_netname) {}

NetConfig NetConfig::GetYolov3Net() {
  float confThreshold = 0.5;
  float nmsThreshold = 0.4;
  int inpWidth = 416;
  int inpHeight = 416;
  string classesFile = prefix+"yolov3/coco.names";
  string modelConfiguration = prefix+"yolov3/yolov3.cfg";
  string modelWeights = prefix+"yolov3/yolov3.weights";
  string netname = "yolov3";

  NetConfig net(confThreshold, nmsThreshold, inpWidth, inpHeight, classesFile,
                modelConfiguration, modelWeights, netname);

  return net;
}

NetConfig NetConfig::GetYolov4Net() {
  float confThreshold = 0.5;
  float nmsThreshold = 0.4;
  int inpWidth = 608;
  int inpHeight = 608;
  string classesFile = prefix+"yolov4/coco.names";
  string modelConfiguration = prefix+"yolov4/yolov4.cfg";
  string modelWeights = prefix+"yolov4/yolov4.weights";
  string netname = "yolov4";

  NetConfig net(confThreshold, nmsThreshold, inpWidth, inpHeight, classesFile,
                modelConfiguration, modelWeights, netname);

  return net;
}

NetConfig NetConfig::GetYolov4TinyNet() {
  float confThreshold = 0.5;
  float nmsThreshold = 0.4;
  int inpWidth = 416;
  int inpHeight = 416;
  string classesFile = prefix+"yolov4-tiny/coco.names";
  string modelConfiguration = prefix+"yolov4-tiny/yolov4-tiny.cfg";
  string modelWeights = prefix+"yolov4-tiny/yolov4-tiny.weights";
  string netname = "yolov4";

  NetConfig net(confThreshold, nmsThreshold, inpWidth, inpHeight, classesFile,
                modelConfiguration, modelWeights, netname);

  return net;
}

NetConfig NetConfig::GetYoloFastestNet() {
  float confThreshold = 0.5;
  float nmsThreshold = 0.4;
  int inpWidth = 320;
  int inpHeight = 320;
  string classesFile = prefix+"yolo-fastest/coco.names";
  string modelConfiguration = prefix+"yolo-fastest/yolo-fastest-xl.cfg";
  string modelWeights = prefix+"yolo-fastest/yolo-fastest-xl.weights";
  string netname = "yolo-fastest";

  NetConfig net(confThreshold, nmsThreshold, inpWidth, inpHeight, classesFile,
                modelConfiguration, modelWeights, netname);

  return net;
}

NetConfig NetConfig::GetYolobileNet() {
  float confThreshold = 0.5;
  float nmsThreshold = 0.4;
  int inpWidth = 320;
  int inpHeight = 320;
  string classesFile = prefix+"yolobile/coco.names";
  string modelConfiguration = prefix+"yolobile/csdarknet53s-panet-spp.cfg";
  string modelWeights = prefix+"yolobile/yolobile.weights";
  string netname = "yolobile";

  NetConfig net(confThreshold, nmsThreshold, inpWidth, inpHeight, classesFile,
                modelConfiguration, modelWeights, netname);

  return net;
}

NetConfig* NetConfig::GetCustomNet(const float _confThreshold,
                                   const float _nmsThreshold,
                                   const int _inpWidth, const int _inpHeight,
                                   const string &_classesFile,
                                   const string &_modelConfiguration,
                                   const string &_modelWeights,
                                   const string &_netname) {
  NetConfig *net =
      new NetConfig(_confThreshold, _nmsThreshold, _inpWidth, _inpHeight,
                    _classesFile, _modelConfiguration, _modelWeights, _netname);
  return net;
}

// NetConfig yolo_nets[4] =
//{
//    {0.5, 0.4, 416, 416,"coco.names",
//    "yolov3/yolov3.cfg","yolov3/yolov3.weights", "yolov3"},

//    {0.5, 0.4, 608, 608,"coco.names","yolov4/yolov4.cfg",
//    "yolov4/yolov4.weights", "yolov4"},

//    {0.5, 0.4, 320,320,"coco.names",
//    "yolo-fastest/yolo-fastest-xl.cfg","yolo-fastest/yolo-fastest-xl.weights",
//    "yolo-fastest"},

//    {0.5, 0.4, 320,320,"coco.names",
//    "yolobile/csdarknet53s-panet-spp.cfg","yolobile/yolobile.weights",
//    "yolobile"}
//};
