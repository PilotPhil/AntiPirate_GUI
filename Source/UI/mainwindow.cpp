#include "mainwindow.h"

#include <QList>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // init tread or detect
    thread_detect = new QThread;

    // init video detector
    connect(ui->action_Video_path, &QAction::triggered, this, [=]() {
        // set the path of the video to detect
        this->_media_path = QFileDialog::getOpenFileName().toStdString();

        // init detector for video
        this->_detector = new VideoDetTracker(this->yolo_model);

        // set media path
        this->_detector->SetMediaPath(this->_media_path);

        this->_detector->moveToThread(this->thread_detect);


        // thread start ---> detector start
        connect(this->thread_detect,
                &QThread::started,
                this->_detector,
                &DetTracker::Start);

        // btn start ---> thread start
        connect(ui->pb_start_detect, &QPushButton::clicked, this, [=]() {
            this->thread_detect->start();
        });

        // detector sendframe ---> lable showframe
        connect(this->_detector,
                &DetTracker::SendDetectFrame,
                this,
                &MainWindow::ShowImg2Label,
                Qt::DirectConnection);

        connect(this->_detector,
                &DetTracker::SendDetectRes,
                this,
                &MainWindow::DisplayDetectRes);

        connect(this->_detector,
                &DetTracker::SendPerfInfo,
                this,
                &MainWindow::DisplayPerfInfo);

        connect(this->_detector,
                &DetTracker::SendStopDetect,
                this, [=]() { ui->label_dispaly->setText("no signal"); });

        // btn pause ---> detector pause
        connect(ui->pb_pause_detect, &QPushButton::clicked, this, [=]() {
            this->_detector->Pause();
        });

        // btn stop ---> detector stop
        connect(ui->pb_stop_detect, &QPushButton::clicked, this, [=]() {
            this->_detector->Stop();
            thread_detect->quit();
            thread_detect->wait();
        });
    });

    // init zed cam detector
    connect(ui->action_ZED_CAM, &QAction::triggered, this, [=]() {
        int ret = s2.exec();

        if (ret == QDialog::Accepted) {
            auto init_params = s2.GetCamInitParams();

            // init detector for zed camera
            this->_detector = new ZedDetTracker(this->yolo_model, init_params);

            this->_detector->moveToThread(this->thread_detect);

            // thread start ---> detector start
            connect(this->thread_detect,
                    &QThread::started,
                    this->_detector,
                    &DetTracker::Start);

            // btn start ---> thread start
            connect(ui->pb_start_detect, &QPushButton::clicked, this, [=]() {
                this->thread_detect->start();
            });

            // detector sendframe ---> lable showframe
            connect(this->_detector,
                    &DetTracker::SendDetectFrame,
                    this,
                    &MainWindow::ShowImg2Label,
                    Qt::DirectConnection);

            connect(this->_detector,
                    &DetTracker::SendDetectRes,
                    this,
                    &MainWindow::DisplayDetectRes);

            connect(this->_detector,
                    &DetTracker::SendPerfInfo,
                    this,
                    &MainWindow::DisplayPerfInfo);

            connect(this->_detector,
                    &DetTracker::SendStopDetect,
                    this, [=]() { ui->label_dispaly->setText("no signal"); });

            // btn pause ---> detector pause
            connect(ui->pb_pause_detect, &QPushButton::clicked, this, [=]() {
                this->_detector->Pause();
            });

            // btn stop ---> detector stop
            connect(ui->pb_stop_detect, &QPushButton::clicked, this, [=]() {
                this->_detector->Stop();
                thread_detect->quit();
                thread_detect->wait();
            });
        } else {
            return;
        }
    });

}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::ShowImg2Label(const Mat &img) {
    cv::cvtColor(img, img, COLOR_BGR2RGB); // Qt reads in RGB whereas CV in BGR
    QImage imdisplay(
            (uchar *) img.data, img.cols, img.rows, img.step, QImage::Format_RGB888);
    QPixmap pix = QPixmap::fromImage(imdisplay);
    auto res = pix.scaled(
            ui->label_dispaly->size(), Qt::KeepAspectRatio, Qt::FastTransformation);

    ui->label_dispaly->setPixmap(res);
}

void MainWindow::DisplayDetectRes(const vector<TrackingBox> reslist) {
    ui->te_detect_res->clear();
            foreach (auto res, reslist) {
            QString s;
            s = QString::number(res.id) + " " + QString::number(res.confidence) + " " +
                QString::number(res.distance);
            ui->te_detect_res->append(s);
        }
}

void MainWindow::DisplayPerfInfo(float inferencr_time, float compute_time) {
    ui->lb_inference_time->setText(QString::number(inferencr_time));
    ui->lb_max_fps->setText(QString::number(1000.0 / inferencr_time));
    ui->lb_compute_time->setText(QString::number(compute_time));
}

void MainWindow::on_action_custom_net_triggered() {
    int ret = s.exec();

    if (ret == QDialog::Accepted) {
        auto net = s.Net();
        auto use_cuda = s.UseCuda();

        if (yolo_model != nullptr) {
            delete yolo_model;
        }
        this->yolo_model = new YOLO(net, use_cuda);

    } else {
        return;
    }
}

void MainWindow::on_action_yolov3_net_triggered() {
    auto net = NetConfig::GetYolov3Net();
    if (yolo_model != nullptr) {
        delete yolo_model;
    }

    auto use_cuda = ui->actionuse_cuda->isChecked();
    this->yolo_model = new YOLO(net, use_cuda);
}

void MainWindow::on_action_yolov4_net_triggered() {
    auto net = NetConfig::GetYolov4Net();
    if (yolo_model != nullptr) {
        delete yolo_model;
    }
    auto use_cuda = ui->actionuse_cuda->isChecked();
    this->yolo_model = new YOLO(net, use_cuda);
}

void MainWindow::on_actionyolov4fastest_triggered() {
    auto net = NetConfig::GetYoloFastestNet();
    if (yolo_model != nullptr) {
        delete yolo_model;
    }
    auto use_cuda = ui->actionuse_cuda->isChecked();
    this->yolo_model = new YOLO(net, use_cuda);
}

void MainWindow::on_action_yolobile_net_triggered() {
    auto net = NetConfig::GetYolobileNet();
    if (yolo_model != nullptr) {
        delete yolo_model;
    }
    auto use_cuda = ui->actionuse_cuda->isChecked();
    this->yolo_model = new YOLO(net, use_cuda);
}
