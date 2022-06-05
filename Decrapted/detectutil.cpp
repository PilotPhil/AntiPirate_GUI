#include "detectutil.h"

#include <QThread>

DetectUtil::DetectUtil(YOLO *_yolo_model, QObject *parent)
    : yolo_model(_yolo_model), QObject(parent) {
  connect(yolo_model, &YOLO::SendDetectResult, this,
          &DetectUtil::SendDetectResult);
}

void DetectUtil::SetSrc(const QString &src) { this->src = src; }

void DetectUtil::DetectImg(const QString &img_src, bool is_show_opencv_window) {
  Mat mat = imread(img_src.toStdString());
  this->yolo_model->detect(mat);

  if (is_show_opencv_window == true) {
    static const string kWinName = "Deep learning object detection in OpenCV";
    namedWindow(kWinName, WINDOW_AUTOSIZE);

    imshow(kWinName, mat);

    waitKey(0);
    destroyAllWindows();
  }

  emit SendDetetFrameRes(mat);
}

void DetectUtil::DetectVideo() // const QString &video_src, bool
                               // is_show_opencv_window
{
  VideoCapture cap(src.toStdString());

  _isStop = false;

  Mat frame;

  _fps = cap.get(CAP_PROP_FPS);
  _interval = 1000.0 / _fps;

  QElapsedTimer time;

  while (_isStop == false) {
    if (_isPause == false) {

      time.restart();

      cap >> frame;

      if (frame.empty()) {
        break;
      }

      //      QString fpsStr = "FPS: " + QString::number(_fps);
      //      putText(frame, fpsStr.toStdString(), Point(0, 30),
      //      FONT_HERSHEY_SIMPLEX,
      //              1, Scalar(0, 0, 255), 2);


      yolo_model->detect(frame);

      emit SendDetetFrameRes(frame);

      double compute_time = time.elapsed();

      emit SendPerfIndicator(_fps, 10, compute_time);

      if (compute_time < _interval) {
        QThread::usleep(1000.0*(_interval - compute_time));
      }
    }
  }
  cap.release();
}
