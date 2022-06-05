#include "ZedDetTracker.h"

ZedDetTracker::ZedDetTracker(YOLO *yolo, sl::InitParameters initParams, QObject *parent)
        : DetTracker{yolo, parent}, _init_params(initParams) {

    this->sort = new Sort(this);
}

void ZedDetTracker::Start() {
    this->Process();
}

void ZedDetTracker::Pause() {
    this->_isPause = !this->_isPause;
}

void ZedDetTracker::Stop() {
    this->_isStop = true;

    this->_cam.close();

    emit SendStopDetect();
}

void ZedDetTracker::Process() {
    if (this->_cam.open(this->_init_params) != sl::ERROR_CODE::SUCCESS) {
        qDebug() << "ZedDetTracker: cam open failed";
        this->_cam.close();
        return;
    }

    while (this->_isStop == false) {
        // if pause, pause the loop
        if (this->_isPause == true) {
            continue;
        }

        if (this->_cam.grab() == sl::ERROR_CODE::SUCCESS) {
            elapsedTime.restart();

            this->_cam.retrieveImage(this->_zed_frame, sl::VIEW::LEFT);
            this->_cam.retrieveMeasure(this->_point_cloud, sl::MEASURE::XYZABGR);
            this->_frame = this->slMat2cvMat(this->_zed_frame);

            //detect
            float inference_time = this->_yolo->detect(this->_frame);

            auto sort_res = sort->process(this->_yolo->_resList);

            for (int i = 0; i < sort_res.size(); i++) {
                TrackingBox& r=sort_res[i];

                auto dis = this->getDistance(r.box);
                r.distance = dis;

                if (dis> 0)
                {
                    FrameDraw::DrawFireBox(r, this->_frame);
                    FrameDraw::DrawDetectInfo(r, this->_frame, true);
                }
            }


            float compute_time = elapsedTime.elapsed();

            emit SendPerfInfo(inference_time, compute_time);
            emit SendDetectFrame(this->_frame);
            emit SendDetectRes(sort_res);
        }
    }
}

cv::Mat ZedDetTracker::slMat2cvMat(sl::Mat &input) {
    auto temp = cv::Mat(input.getHeight(), input.getWidth(), getOCVtype(input.getDataType()),
                        input.getPtr<sl::uchar1>(sl::MEM::CPU), input.getStepBytes(sl::MEM::CPU));

    cv::Mat res;

    cv::cvtColor(temp, res, cv::COLOR_RGBA2RGB);

    return res;
}

int ZedDetTracker::getOCVtype(sl::MAT_TYPE type) {
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

float ZedDetTracker::getDistance(int x, int y) {
    float distance;

    sl::float4 pointCloudValue;
    this->_point_cloud.getValue(x, y, &pointCloudValue);

    if (std::isfinite(pointCloudValue.z) == true) {
        distance = sqrt(pointCloudValue.x * pointCloudValue.x + pointCloudValue.y * pointCloudValue.y +
                        pointCloudValue.z * pointCloudValue.z);
    } else {
        qDebug() << "can not compute distance!";
        distance = -1.0;
    }

    return distance;
}

float ZedDetTracker::getDistance(const cv::Rect_<float> &bbox) {
    int c_x = bbox.x + bbox.width / 2;
    int c_y = bbox.y + bbox.height / 2;

    return this->getDistance(c_x, c_y);
}
