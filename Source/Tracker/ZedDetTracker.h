#ifndef ZEDCAMDETECTOR_H
#define ZEDCAMDETECTOR_H

#include "DetTracker.h"
#include <sl/Camera.hpp>


class ZedDetTracker : public DetTracker {
public:
    explicit ZedDetTracker(YOLO* yolo, sl::InitParameters initParams, QObject* parent = nullptr);

    virtual void Start();
    virtual void Pause();
    virtual void Stop();
    virtual void Process();

private:
    sl::Camera _cam;
    sl::InitParameters _init_params;

    sl::Mat _zed_frame;
    sl::Mat _point_cloud;


    cv::Mat slMat2cvMat(sl::Mat& input);
    int getOCVtype(sl::MAT_TYPE type);

    float getDistance(int x, int y);
    float getDistance(const cv::Rect_<float>& bbox);
};

#endif // ZEDCAMDETECTOR_H
