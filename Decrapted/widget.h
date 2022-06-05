#ifndef WIDGET_H
#define WIDGET_H

#include <QThread>
#include <QWidget>

#include "detectutil.h"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include "setnetdialog.h"

using namespace cv;

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget {
  Q_OBJECT

public:
  Widget(QWidget *parent = nullptr);
  ~Widget();

public slots:
  void ShowImg2Label(cv::Mat img);

private slots:
  void on_pushButton_clicked();

private:
  Ui::Widget *ui;
  SetNetDialog s;

  YOLO *yolo_model;
  DetectUtil *detectUtil;

  QThread *thread_detect;

  void AllConnects();
};
#endif // WIDGET_H
