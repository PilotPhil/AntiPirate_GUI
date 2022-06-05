//
// Created by dwb on 2022/2/10.
//

#ifndef ANTIPIRATEGUI_FRAMEDRAW_H
#define ANTIPIRATEGUI_FRAMEDRAW_H

#include <iostream>
#include <opencv2/core.hpp>
#include "TrackBox.h"

using namespace std;
using namespace cv;

class FrameDraw {
public:
    /**
     * draw a fire box with a center cross, 4 borders,like:...
     * ??       ??
     * |          |
     *      +
     * |          |
     * ??       ??
     * @param tb
     * @param frame
     */
    static void DrawFireBox(const TrackingBox &tb, const cv::Mat &frame);

    /**
     * draw detect info,id class distance optional display
     * @param tb
     * @param frame
     */
    static void DrawDetectInfo(const TrackingBox &tb, const cv::Mat &frame, bool showDistance = true);

};


#endif //ANTIPIRATEGUI_FRAMEDRAW_H
