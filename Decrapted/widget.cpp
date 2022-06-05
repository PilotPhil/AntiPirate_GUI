#include "widget.h"

#include "./ui_widget.h"

#include <QDialog>

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
  ui->setupUi(this);
}

Widget::~Widget() { delete ui; }

void Widget::AllConnects() {

  thread_detect = new QThread;
  detectUtil->moveToThread(thread_detect);

  connect(detectUtil, &DetectUtil::SendDetetFrameRes, this,
          &Widget::ShowImg2Label, Qt::DirectConnection);

  connect(thread_detect, &QThread::started, detectUtil,
          &DetectUtil::DetectVideo);

  // btn_detect_img_start
  connect(ui->btn_detect_img_start, &QPushButton::clicked, this,
          [=]() { detectUtil->DetectImg(ui->lineEdit_path->text()); });

  // btn_detect_video_start
  connect(ui->btn_detect_video_start, &QPushButton::clicked, this, [=]() {
    detectUtil->SetSrc(ui->lineEdit_path_video->text());
    thread_detect->start();
  });

  // btn_detect_video_stop
  connect(ui->btn_detect_video_stop, &QPushButton::clicked, this, [=]() {
    if (thread_detect->isRunning() == true) {
      detectUtil->StopDetect();
      thread_detect->quit();
      thread_detect->wait();
    }
  });

  // btn_detect_video_pause
  connect(ui->btn_detect_video_pause, &QPushButton::clicked, this,
          [=]() { detectUtil->PauseDetect(); });
}

void Widget::ShowImg2Label(Mat img) {
  cv::cvtColor(img, img, COLOR_BGR2RGB); // Qt reads in RGB whereas CV in BGR
  QImage imdisplay((uchar *)img.data, img.cols, img.rows, img.step,
                   QImage::Format_RGB888);
  QPixmap pix = QPixmap::fromImage(imdisplay);
  auto res = pix.scaled(ui->label_dispaly->size(), Qt::KeepAspectRatio,
                        Qt::FastTransformation);

  ui->label_dispaly->setPixmap(res);
}

void Widget::on_pushButton_clicked() {


}
