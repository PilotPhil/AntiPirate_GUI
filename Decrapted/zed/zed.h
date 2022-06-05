#ifndef ZED_H
#define ZED_H

#include <QDebug>
#include <QObject>
#include <QString>

#include <iostream>
#include <string>

#include <sl/Camera.hpp>

#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

class ZED : public QObject {
    Q_OBJECT
public:
    explicit ZED(QObject* parent = nullptr);

    void OpenCam();
    void CloseCam();

    void CaptureImg();
    void CaptureVideo();

    void SetResolution(const string& resolution);
    void SetFPS(const string& fps);
    void SetDepthMode(const string& depthMode);
    void SetUnits(const string& unit);

    sl::Mat ZedFrame() const { return this->_zedFrame; }
    cv::Mat ZedCvFrame() const { return this->_cvMat; }
    bool IsCamOpen() { return this->_cam.isOpened(); }
    bool IsOnCapture() const { return this->_isOnCapture; }
    void StartCapture() { this->_isOnCapture = true; }
    QString SerialNumber() const { return this->_serialNumber; }

private:
    cv::Mat slMat2cvMat(const sl::Mat& input);
    int getOCVtype(sl::MAT_TYPE type);

signals:
    void SendZedCamFrame();

private:
    sl::Camera _cam;
    sl::InitParameters _initParameters;

    sl::Mat _zedFrame;
    cv::Mat _cvMat;

    QString _serialNumber;
    bool _isOnCapture = false;
};

#endif // ZED_H
