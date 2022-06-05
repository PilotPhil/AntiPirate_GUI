#ifndef NETCONFIG_H
#define NETCONFIG_H

#include <iostream>
#include <string>

using namespace std;

class NetConfig {
public:
  float confThreshold; // Confidence threshold
  float nmsThreshold;  // Non-maximum suppression threshold
  int inpWidth;        // Width of network's input image
  int inpHeight;       // Height of network's input image
  string classesFile;
  string modelConfiguration;
  string modelWeights;
  string netname;



private:
  NetConfig(const float _confThreshold, const float _nmsThreshold,
            const int _inpWidth, const int _inpHeight,
            const string &_classesFile, const string &_modelConfiguration,
            const string &_modelWeights, const string &_netname);

public:
  static string prefix;

  static NetConfig GetYolov3Net();
  static NetConfig GetYolov4Net();
  static NetConfig GetYolov4TinyNet();
  static NetConfig GetYoloFastestNet();
  static NetConfig GetYolobileNet();
  static NetConfig*
  GetCustomNet(const float _confThreshold, const float _nmsThreshold,
               const int _inpWidth, const int _inpHeight,
               const string &_classesFile, const string &_modelConfiguration,
               const string &_modelWeights, const string &_netname);
};

#endif
