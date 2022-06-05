#include "VideoDetTracker.h"

#include <QElapsedTimer>

VideoDetTracker::VideoDetTracker(YOLO *yolo, QObject *parent)
        : DetTracker{yolo, parent} { this->sort = new Sort(this); }

void
VideoDetTracker::Start() {
    this->Process();
}

void
VideoDetTracker::Pause() {
    this->_isPause = !this->_isPause;
}

void
VideoDetTracker::Stop() {
    this->_isStop = true;
    emit SendStopDetect();
}

void
VideoDetTracker::Process() {
    // capture video
    cv::VideoCapture cap(this->_media_path);

    // get fps of the video
    auto fps = cap.get(cv::CAP_PROP_FPS);
    auto itv = 1000.0 / fps; // time between 2 frames

    // detect in a while loop
    while (this->_isStop == false) {
        // if pause, pause the loop
        if (this->_isPause == true) {
            continue;
        }

        elapsedTime.restart();
        cap >> this->_frame;

        if (this->_frame.empty() == true) {
            break;
        }

        float inference_time = this->_yolo->detect(this->_frame);

        auto sort_res = sort->process(this->_yolo->_resList);


        for (int i = 0; i < sort_res.size(); i++) {
            FrameDraw::DrawFireBox(sort_res[i], this->_frame);
            FrameDraw::DrawDetectInfo(sort_res[i], this->_frame, false);
        }

        float compute_time = elapsedTime.elapsed();
        if (compute_time < itv) {
            QThread::usleep(1000.0 * (itv - compute_time));
        }


        emit SendDetectFrame(this->_frame);
        emit SendDetectRes(sort_res);
        emit SendPerfInfo(inference_time, compute_time);
    }
}
