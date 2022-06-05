#ifndef DETECTOR_H
#define DETECTOR_H

#include <QDebug>
#include <QElapsedTimer>
#include <QObject>
#include <iostream>
#include <string>
#include <iomanip>

#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "yolo.h"

#include "Sort.h"

#include "FrameDraw.h"

using namespace cv;
using namespace std;

class DetTracker : public QObject {
Q_OBJECT
public:
    explicit DetTracker(YOLO *yolo, QObject *parent = nullptr);

    virtual ~DetTracker();

    virtual void Start() = 0;

    virtual void Pause() = 0;

    virtual void Stop() = 0;

    virtual void Process() = 0;

    void SetMediaPath(const String &pth);


signals:

    void SendDetectFrame(const cv::Mat &frame);

    void SendDetectRes(const vector<TrackingBox> resList);

    void SendProcessTime(float t);

    void SendPerfInfo(float inference_time, float compute_time);

    void SendStopDetect();

protected:
    QElapsedTimer elapsedTime;

    bool _isPause = false;
    bool _isStop = false;
    String _media_path;

    Mat _frame;

    YOLO *_yolo;

    Sort *sort = nullptr;
};

#endif // DETECTOR_H
