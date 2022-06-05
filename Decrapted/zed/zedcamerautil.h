#ifndef ZEDCAMERAUTIL_H
#define ZEDCAMERAUTIL_H

#include <QObject>
#include <sl/Camera.hpp>
#include <opencv2/opencv.hpp>
#include <QImage>

#include "tools.h"

class ZedCameraUtil : public QObject
{
    Q_OBJECT
public:
    explicit ZedCameraUtil(QObject *parent = nullptr);
    explicit ZedCameraUtil(sl::Camera* zed_cam,QObject *parent = nullptr);
    ~ZedCameraUtil();

    bool OpenZedCamera();//开启摄像机
    void CloseZedCamera();//关闭摄像机
    bool IsCamOpen() const{return isCamOpen;}//

    QImage GetCamImgLef();
    QImage GetCamImgRight();

    float GetDistance(int x,int y);//(x,y)坐标处 测距

signals:
    void SendDistanceSignal(float distance);    //发送测得的距离信号
    void SendCamImgLeft(QImage img);            //发送获取的相机画面信号
    void SendCamImgRight(QImage img);           //发送获取的相机画面信号

private:
    sl::Camera* cam;        //相机对象
    bool isCamOpen=false;   //相机是否开启

    Tools *tools;

};

#endif // ZEDCAMERAUTIL_H
