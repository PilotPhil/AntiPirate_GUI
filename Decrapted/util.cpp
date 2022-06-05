#include "util.h"

Mat DetectImg(YOLO& yolo_model, string& img_src, bool is_show_opencv_window)
{
    Mat mat=imread(img_src);
    yolo_model.detect(mat);

    if(is_show_opencv_window==true)
    {
            static const string kWinName = "Deep learning object detection in OpenCV";
            namedWindow(kWinName, WINDOW_AUTOSIZE);

            imshow(kWinName,mat);

            waitKey(0);
            destroyAllWindows();
    }

    return mat;
}

Mat DetectVideo(YOLO& yolo_model,string& video_src)
{
        static const string kWinName = "Deep learning object detection in OpenCV";
        namedWindow(kWinName,WINDOW_AUTOSIZE);
        VideoCapture cap(video_src);

        Mat frame;

        while(waitKey(1)<0)
        {
            cap>>frame;

            if(frame.empty())
            {
                break;
            }

            yolo_model.detect(frame);
            imshow(kWinName,frame);
        }
        cap.release();
        destroyAllWindows();
}

void ShowImg2Label(QLabel& label,Mat& mat)
{
    Mat &img=mat;
    cv::cvtColor(img,img,COLOR_BGR2RGB); //Qt reads in RGB whereas CV in BGR
    QImage imdisplay((uchar*)img.data, img.cols, img.rows, img.step, QImage::Format_RGB888);

    QPixmap pix=QPixmap::fromImage(imdisplay);
    pix.scaled(QSize(481,481),Qt::KeepAspectRatio);

    label.setPixmap(pix);
    label.setScaledContents(true);
}
