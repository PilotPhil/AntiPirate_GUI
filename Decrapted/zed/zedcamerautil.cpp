#include "zedcamerautil.h"

//ctor
ZedCameraUtil::ZedCameraUtil(QObject* parent)
    : QObject(parent)
{
    cam = new sl::Camera();
    tools = new Tools();
}

ZedCameraUtil::ZedCameraUtil(sl::Camera* zed_cam, QObject* parent)
    : QObject(parent)
    , cam(zed_cam)
{
    if (zed_cam == nullptr) {
        cam = new sl::Camera();
    }
    tools = new Tools();
}

//dtor
ZedCameraUtil::~ZedCameraUtil()
{
    delete cam;
}

//open camera
bool ZedCameraUtil::OpenZedCamera()
{
    //setting
    sl::InitParameters init_params;
    init_params.depth_mode = sl::DEPTH_MODE::PERFORMANCE; //性能模式
    init_params.coordinate_units = sl::UNIT::MILLIMETER; //毫米单位

    //open
    if (cam->open(init_params) != sl::ERROR_CODE::SUCCESS) //打开摄像头失败
    {
        std::cout << "Camera open failed" << std::endl;
        cam->close();
        return isCamOpen = false;
    }

    //print
    auto camera_infos = cam->getCameraInformation();
    std::cout << "Camera open Success" << std::endl;
    std::cout << "Serial number: " << camera_infos.serial_number << std::endl; //打印序列号
    return isCamOpen = true;
}

//close camera
void ZedCameraUtil::CloseZedCamera()
{
    cam->close();
    this->isCamOpen = false;
    std::cout << "zed camera closed!" << std::endl;
}

//get distance in (x,y)
float ZedCameraUtil::GetDistance(int x, int y)
{
    if (this->isCamOpen == false) {
        std::cout << "camera not open!!" << std::endl;
        return -1;
    }

    sl::Mat image, depth, point_cloud;

    sl::RuntimeParameters runtime_params;
    runtime_params.sensing_mode = sl::SENSING_MODE::STANDARD; //标准传感模式

    if (cam->grab(runtime_params) != sl::ERROR_CODE::SUCCESS) {
        return 0.0; //抓取不成功就返回
    }

    cam->retrieveImage(image, sl::VIEW::LEFT); // Retrieve the left image
    cam->retrieveMeasure(depth, sl::MEASURE::DEPTH); //����depth
    cam->retrieveMeasure(point_cloud, sl::MEASURE::XYZABGR);

    if (x <= 0 || y <= 0) {
        x = image.getWidth() / 2;
        y = image.getHeight() / 2;
    }

    sl::float4 point_cloud_value;
    point_cloud.getValue(x, y, &point_cloud_value);

    float distance = 0.0;

    if (std::isfinite(point_cloud_value.z) == true) //���벻������Զ
    {
        distance = sqrt(point_cloud_value.x * point_cloud_value.x + point_cloud_value.y * point_cloud_value.y + point_cloud_value.z * point_cloud_value.z);
        std::cout << "Distance at " << x << ", " << y << "is " << distance << std::endl;
    } else {
        std::cout << "can not compute distance!" << std::endl;
        distance = -1.0;
    }

    SendDistanceSignal(distance);
    return distance;
}

//get cam left image
QImage ZedCameraUtil::GetCamImgLef()
{
    if (this->isCamOpen == false) {
        std::cout << "camera not open!!" << std::endl;
        QImage nullImg;
        return nullImg;
    }

    sl::Mat sl_mat;
    cam->retrieveImage(sl_mat, sl::VIEW::LEFT); //获取 zed mat

    //zed mat 转换为 cv mat
    cv::Mat cv_mat = cv::Mat((int)sl_mat.getHeight(),
        (int)sl_mat.getWidth(),
        CV_8UC4,
        sl_mat.getPtr<sl::uchar1>(sl::MEM::CPU));

    //四通道转三通道
    cv::Mat cv_mat1;
    cv::cvtColor(cv_mat, cv_mat1, cv::COLOR_RGBA2RGB);

    cv::Mat& mat = cv_mat1;
    //show the resultImage in result area;
    cv::Mat rgb;
    QImage img;
    if (mat.channels() == 3) // RGB image
    {
        cv::cvtColor(cv_mat1, rgb, cv::COLOR_BGR2RGB);
        img = QImage((const uchar*)(rgb.data), //(const unsigned char*)
            rgb.cols, rgb.rows,
            rgb.cols * rgb.channels(), //new add
            QImage::Format_RGB888);
    } else // gray image
    {
        img = QImage((const uchar*)(cv_mat1.data),
            cv_mat1.cols, cv_mat1.rows,
            cv_mat1.cols * cv_mat1.channels(), //new add
            QImage::Format_Indexed8);
    }

    SendCamImgLeft(img);
    return img;
}

//get cam right image
QImage ZedCameraUtil::GetCamImgRight()
{
    if (this->isCamOpen == false) {
        std::cout << "camera not open!!" << std::endl;
        QImage nullImg;
        return nullImg;
    }

    sl::Mat image;
    cam->retrieveImage(image, sl::VIEW::RIGHT);

    cv::Mat cvImg = cv::Mat((int)image.getHeight(),
        (int)image.getWidth(),
        CV_8UC4,
        image.getPtr<sl::uchar1>(sl::MEM::CPU));

    cv::Mat cvImg1;
    cv::cvtColor(cvImg, cvImg1, cv::COLOR_RGBA2RGB);

    std::cout << "channels:  " << cvImg.channels() << std::endl;

    cv::Mat& mat = cvImg1;
    //show the resultImage in result area;
    cv::Mat rgb;
    QImage img;
    if (mat.channels() == 3) // RGB image
    {
        cv::cvtColor(mat, rgb, cv::COLOR_BGR2RGB);
        img = QImage((const uchar*)(rgb.data), //(const unsigned char*)
            rgb.cols, rgb.rows,
            rgb.cols * rgb.channels(), //new add
            QImage::Format_RGB888);
    } else // gray image
    {
        img = QImage((const uchar*)(mat.data),
            mat.cols, mat.rows,
            mat.cols * mat.channels(), //new add
            QImage::Format_Indexed8);
    }

    SendCamImgRight(img);
    return img;
}
