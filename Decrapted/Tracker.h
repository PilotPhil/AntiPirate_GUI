//
// Created by dwb on 2022/2/10.
//

#ifndef ANTIPIRATEGUI_TRACKER_H
#define ANTIPIRATEGUI_TRACKER_H

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

class Tracker: public QObject {
Q_OBJECT
public:
    explicit Tracker(YOLO *yolo, QObject *parent = nullptr);
    virtual ~Tracker();

    virtual void Start() = 0;
    virtual void Pause() = 0;
    virtual void Stop() = 0;
    virtual void Process() = 0;
};


#endif //ANTIPIRATEGUI_TRACKER_H
