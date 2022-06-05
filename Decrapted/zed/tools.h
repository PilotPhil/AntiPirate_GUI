#ifndef TOOLS_H
#define TOOLS_H

#include <QImage>
#include <QObject>
#include <opencv2/opencv.hpp>

class Tools : public QObject
{
    Q_OBJECT
public:
    explicit Tools(QObject *parent = nullptr);

    QImage CvMat2QImage(const cv::Mat& mat1);//opencv的mat转换为QImage


signals:


};

#endif // TOOLS_H
