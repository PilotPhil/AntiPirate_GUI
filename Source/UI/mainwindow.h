#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QFileDialog>
#include <QDebug>
#include <QList>

#include <iostream>
#include <string>

#include "setnetdialog.h"
#include "setzedcamdialog.h"

#include <sl/Camera.hpp>

#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"


#include "DetTracker.h"
#include "VideoDetTracker.h"
#include "ZedDetTracker.h"

#include "Sort.h"

using namespace std;
using namespace cv;


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

    void ShowImg2Label(const cv::Mat &img);

    void DisplayDetectRes(const vector<TrackingBox> reslist);

    void DisplayPerfInfo(float inferencr_time, float compute_time);

private slots:

    void on_action_custom_net_triggered();

    void on_action_yolov3_net_triggered();

    void on_action_yolov4_net_triggered();

    void on_actionyolov4fastest_triggered();

    void on_action_yolobile_net_triggered();

private:
    Ui::MainWindow *ui;

    SetNetDialog s;//dialog to set net
    SetZedCamDialog s2;//dialog to set zed cam


    String _media_path;//the path of the media to be detect,like image,videos

    DetTracker *_detector = nullptr;
    YOLO *yolo_model = nullptr;
    QThread *thread_detect = nullptr;

    sl::InitParameters _zed_init_params;
};

#endif // MAINWINDOW_H
