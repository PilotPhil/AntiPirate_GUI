#include "tools.h"

Tools::Tools(QObject *parent) : QObject(parent)
{

}

QImage Tools::CvMat2QImage(const cv::Mat &mat1)
{
        cv::Mat cvImg1;
        cv::cvtColor(mat1, cvImg1, cv::COLOR_RGBA2RGB);


        cv::Mat& mat=cvImg1;
        //show the resultImage in result area;
        cv::Mat rgb;
        QImage img;
        if(mat.channels() == 3)    // RGB image
        {
            cv::cvtColor(mat,rgb,cv::COLOR_BGR2RGB);
            img = QImage((const uchar*)(rgb.data),  //(const unsigned char*)
                         rgb.cols,rgb.rows,
                         rgb.cols*rgb.channels(),   //new add
                         QImage::Format_RGB888);
        }else                     // gray image
        {
            img = QImage((const uchar*)(mat.data),
                         mat.cols,mat.rows,
                         mat.cols*mat.channels(),    //new add
                         QImage::Format_Indexed8);
        }

        return img;

}
