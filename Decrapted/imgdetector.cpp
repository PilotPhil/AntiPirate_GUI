#include "imgdetector.h"

ImgDetector::ImgDetector(YOLO* yolo, QObject* parent)
    : Detector { yolo, parent }
{
}

void ImgDetector::Start() { this->Process(); }

void ImgDetector::Pause() { }

void ImgDetector::Stop() { }

void ImgDetector::Process()
{
    elapsedTime.restart();
    this->_frame = cv::imread(this->_media_path);
    float inference_time = this->_yolo->detect(this->_frame);
    float compute_time = elapsedTime.elapsed();

    emit SendPerfInfo(inference_time, compute_time);
    emit SendDetectFrame(this->_frame);
    emit SendDetectRes(this->_yolo->_resList);
}
