#include "zed.h"

ZED::ZED(QObject* parent)
    : QObject { parent }
{
    this->_initParameters.camera_resolution = sl::RESOLUTION::HD720;
    this->_initParameters.camera_fps = 15;
    this->_initParameters.depth_mode = sl::DEPTH_MODE::PERFORMANCE;
    this->_initParameters.coordinate_units = sl::UNIT::MILLIMETER;
}

void ZED::SetResolution(const string& resolution)
{
    if (resolution == "HD720") {
        this->_initParameters.camera_resolution = sl::RESOLUTION::HD720;
    } else if (resolution == "HD1080") {
        this->_initParameters.camera_resolution = sl::RESOLUTION::HD1080;
    } else if (resolution == "HD2K") {
        this->_initParameters.camera_resolution = sl::RESOLUTION::HD2K;
    } else if (resolution == "VGA") {
        this->_initParameters.camera_resolution = sl::RESOLUTION::VGA;
    } else {
        this->_initParameters.camera_resolution = sl::RESOLUTION::HD720;
    }
}

void ZED::SetFPS(const string& fps)
{
    if (fps == "15") {
        this->_initParameters.camera_fps = 15;
    } else if (fps == "30") {
        this->_initParameters.camera_fps = 30;
    } else if (fps == "60") {
        this->_initParameters.camera_fps = 60;
    } else {
        this->_initParameters.camera_fps = 15;
    }
}

void ZED::SetDepthMode(const string& depthMode)
{
    if (depthMode == "PERFORMANCE") {
        this->_initParameters.depth_mode = sl::DEPTH_MODE::PERFORMANCE;
    } else if (depthMode == "QUALITY") {
        this->_initParameters.depth_mode = sl::DEPTH_MODE::QUALITY;
    } else if (depthMode == "ULTRA") {
        this->_initParameters.depth_mode = sl::DEPTH_MODE::ULTRA;
    } else {
        this->_initParameters.depth_mode = sl::DEPTH_MODE::PERFORMANCE;
    }
}

void ZED::SetUnits(const string& unit)
{
    if (unit == "MILLIMETER") {
        this->_initParameters.coordinate_units = sl::UNIT::MILLIMETER;
    } else if (unit == "CENTIMETER") {
        this->_initParameters.coordinate_units = sl::UNIT::CENTIMETER;
    } else if (unit == "METER") {
        this->_initParameters.coordinate_units = sl::UNIT::METER;
    } else if (unit == "INCH") {
        this->_initParameters.coordinate_units = sl::UNIT::INCH;
    } else if (unit == "FOOT") {
        this->_initParameters.coordinate_units = sl::UNIT::FOOT;
    } else {
        this->_initParameters.coordinate_units = sl::UNIT::MILLIMETER;
    }
}

void ZED::OpenCam()
{
    if (this->_cam.isOpened() == true) {
        this->_cam.close();
    }

    if (this->_cam.open(this->_initParameters) != sl::ERROR_CODE::SUCCESS) {
        qDebug() << "cam open failed";
        this->_cam.close();
    }

    this->_serialNumber = QString::number(this->_cam.getCameraInformation().serial_number);
}

void ZED::CloseCam()
{
    this->_cam.close();
    this->_isOnCapture = false;
    qDebug() << "cam closed";
}

void ZED::CaptureImg()
{
    if (this->_cam.isOpened() == false) {
        return;
    }

    while (true) {
        if (this->_cam.grab() == sl::ERROR_CODE::SUCCESS) {
            this->_cam.retrieveImage(this->_zedFrame, sl::VIEW::LEFT);
            this->_cvMat = slMat2cvMat(this->_zedFrame);

            emit SendZedCamFrame();
            break;
        }
    }
}

void ZED::CaptureVideo()
{
    if (this->_cam.isOpened() == false) {
        return;
    }

    while (this->_isOnCapture == true) {
        if (this->_cam.grab() == sl::ERROR_CODE::SUCCESS) {
            this->_cam.retrieveImage(this->_zedFrame, sl::VIEW::LEFT);
            this->_cvMat = slMat2cvMat(this->_zedFrame);

            auto a=this->_cvMat.channels();

            emit SendZedCamFrame();
        }
    }
}

cv::Mat ZED::slMat2cvMat(const sl::Mat& input)
{
    auto temp= cv::Mat(input.getHeight(), input.getWidth(), getOCVtype(input.getDataType()), input.getPtr<sl::uchar1>(sl::MEM::CPU), input.getStepBytes(sl::MEM::CPU));
    cv::Mat res;
    cv::cvtColor(temp, res, cv::COLOR_RGBA2BGR);
    return res;
}

int ZED::getOCVtype(sl::MAT_TYPE type)
{
    int cv_type = -1;
    switch (type) {
    case sl::MAT_TYPE::F32_C1:
        cv_type = CV_32FC1;
        break;
    case sl::MAT_TYPE::F32_C2:
        cv_type = CV_32FC2;
        break;
    case sl::MAT_TYPE::F32_C3:
        cv_type = CV_32FC3;
        break;
    case sl::MAT_TYPE::F32_C4:
        cv_type = CV_32FC4;
        break;
    case sl::MAT_TYPE::U8_C1:
        cv_type = CV_8UC1;
        break;
    case sl::MAT_TYPE::U8_C2:
        cv_type = CV_8UC2;
        break;
    case sl::MAT_TYPE::U8_C3:
        cv_type = CV_8UC3;
        break;
    case sl::MAT_TYPE::U8_C4:
        cv_type = CV_8UC4;
        break;
    default:
        break;
    }
    return cv_type;
}
