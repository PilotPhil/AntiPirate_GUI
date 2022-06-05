#ifndef DETECTUTIL_H
#define DETECTUTIL_H

#include <QList>
#include <QObject>
#include <QString>
#include <QTimer>
#include <QElapsedTimer>

#include "NetConfig.h"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "yolo.h"

using namespace cv;

class DetectUtil : public QObject {
  Q_OBJECT
public:
  DetectUtil(YOLO *_yolo_model, QObject *parent = nullptr);

  void SetSrc(const QString &src);

  void StopDetect() { _isStop = true; }
  void PauseDetect() { _isPause = !_isPause; }

public slots:
  void DetectImg(const QString &img_src, bool is_show_opencv_window = false);
  void
  DetectVideo(); // const QString& video_src,bool is_show_opencv_window=false


signals:
  void SendDetetFrameRes(cv::Mat frame);
  void SendDetectResult(QList<DetectRes> res);
  void SendPerfIndicator(float video_fps,float inferenct_time,float all_compute_time);

private:
  volatile bool _isStop = false;
  volatile bool _isPause = false;

  YOLO *yolo_model;
  QString src;

  QTimer timer;
  Mat frame;
  VideoCapture video;

  float _fps;
  float _interval;
};

#endif // DETECTUTIL_H
