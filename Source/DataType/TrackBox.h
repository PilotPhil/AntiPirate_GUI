//
// Created by dwb on 2022/2/9.
//

#ifndef ANTIPIRATEGUI_TRACKBOX_H
#define ANTIPIRATEGUI_TRACKBOX_H

#include <iostream>
#include <string>
#include <opencv2/core.hpp>

using namespace std;

typedef struct TrackingBox {
    int id;
    float confidence;
    string className;
    float distance;
    cv::Rect_<float> box;
} TrackingBox;


#endif //ANTIPIRATEGUI_TRACKBOX_H
