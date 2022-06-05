/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_custom_net;
    QAction *action_yolov3_net;
    QAction *action_yolov4_net;
    QAction *actionyolov4fastest;
    QAction *action_yolobile_net;
    QAction *actionuse_cuda;
    QAction *actionopen;
    QAction *actionsave;
    QAction *actionsave_as;
    QAction *action_IMG_path;
    QAction *action_Video_path;
    QAction *action_ZED_CAM;
    QWidget *centralwidget;
    QGridLayout *gridLayout_5;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_2;
    QWidget *widget;
    QGridLayout *gridLayout_3;
    QLabel *lb_compute_time;
    QLabel *lb_inference_time;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_4;
    QLabel *lb_max_fps;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer;
    QTextEdit *te_detect_res;
    QHBoxLayout *horizontalLayout;
    QPushButton *pb_start_detect;
    QPushButton *pb_pause_detect;
    QPushButton *pb_stop_detect;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout;
    QLabel *label_dispaly;
    QMenuBar *menubar;
    QMenu *menufile;
    QMenu *menunet;
    QMenu *menudetect;
    QMenu *menuTrack;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(966, 579);
        action_custom_net = new QAction(MainWindow);
        action_custom_net->setObjectName(QString::fromUtf8("action_custom_net"));
        action_yolov3_net = new QAction(MainWindow);
        action_yolov3_net->setObjectName(QString::fromUtf8("action_yolov3_net"));
        action_yolov3_net->setCheckable(true);
        action_yolov4_net = new QAction(MainWindow);
        action_yolov4_net->setObjectName(QString::fromUtf8("action_yolov4_net"));
        action_yolov4_net->setCheckable(true);
        actionyolov4fastest = new QAction(MainWindow);
        actionyolov4fastest->setObjectName(QString::fromUtf8("actionyolov4fastest"));
        actionyolov4fastest->setCheckable(true);
        action_yolobile_net = new QAction(MainWindow);
        action_yolobile_net->setObjectName(QString::fromUtf8("action_yolobile_net"));
        action_yolobile_net->setCheckable(true);
        actionuse_cuda = new QAction(MainWindow);
        actionuse_cuda->setObjectName(QString::fromUtf8("actionuse_cuda"));
        actionuse_cuda->setCheckable(true);
        actionuse_cuda->setChecked(true);
        actionopen = new QAction(MainWindow);
        actionopen->setObjectName(QString::fromUtf8("actionopen"));
        actionsave = new QAction(MainWindow);
        actionsave->setObjectName(QString::fromUtf8("actionsave"));
        actionsave_as = new QAction(MainWindow);
        actionsave_as->setObjectName(QString::fromUtf8("actionsave_as"));
        action_IMG_path = new QAction(MainWindow);
        action_IMG_path->setObjectName(QString::fromUtf8("action_IMG_path"));
        action_Video_path = new QAction(MainWindow);
        action_Video_path->setObjectName(QString::fromUtf8("action_Video_path"));
        action_ZED_CAM = new QAction(MainWindow);
        action_ZED_CAM->setObjectName(QString::fromUtf8("action_ZED_CAM"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_5 = new QGridLayout(centralwidget);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy);
        groupBox_4->setMinimumSize(QSize(400, 0));
        gridLayout_2 = new QGridLayout(groupBox_4);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        widget = new QWidget(groupBox_4);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        gridLayout_3 = new QGridLayout(widget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        lb_compute_time = new QLabel(widget);
        lb_compute_time->setObjectName(QString::fromUtf8("lb_compute_time"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lb_compute_time->sizePolicy().hasHeightForWidth());
        lb_compute_time->setSizePolicy(sizePolicy2);

        gridLayout_3->addWidget(lb_compute_time, 2, 1, 1, 1);

        lb_inference_time = new QLabel(widget);
        lb_inference_time->setObjectName(QString::fromUtf8("lb_inference_time"));
        sizePolicy2.setHeightForWidth(lb_inference_time->sizePolicy().hasHeightForWidth());
        lb_inference_time->setSizePolicy(sizePolicy2);

        gridLayout_3->addWidget(lb_inference_time, 0, 1, 1, 1);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_3->addWidget(label_5, 1, 0, 1, 1);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy3);

        gridLayout_3->addWidget(label_6, 2, 2, 1, 1);

        label_7 = new QLabel(widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_3->addWidget(label_7, 2, 0, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy3.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy3);

        gridLayout_3->addWidget(label_4, 0, 2, 1, 1);

        lb_max_fps = new QLabel(widget);
        lb_max_fps->setObjectName(QString::fromUtf8("lb_max_fps"));
        sizePolicy2.setHeightForWidth(lb_max_fps->sizePolicy().hasHeightForWidth());
        lb_max_fps->setSizePolicy(sizePolicy2);

        gridLayout_3->addWidget(lb_max_fps, 1, 1, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_3->addWidget(label_3, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 2, 3, 1, 1);


        gridLayout_2->addWidget(widget, 0, 0, 1, 1);

        te_detect_res = new QTextEdit(groupBox_4);
        te_detect_res->setObjectName(QString::fromUtf8("te_detect_res"));

        gridLayout_2->addWidget(te_detect_res, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pb_start_detect = new QPushButton(groupBox_4);
        pb_start_detect->setObjectName(QString::fromUtf8("pb_start_detect"));

        horizontalLayout->addWidget(pb_start_detect);

        pb_pause_detect = new QPushButton(groupBox_4);
        pb_pause_detect->setObjectName(QString::fromUtf8("pb_pause_detect"));

        horizontalLayout->addWidget(pb_pause_detect);

        pb_stop_detect = new QPushButton(groupBox_4);
        pb_stop_detect->setObjectName(QString::fromUtf8("pb_stop_detect"));

        horizontalLayout->addWidget(pb_stop_detect);


        gridLayout_2->addLayout(horizontalLayout, 2, 0, 1, 1);


        gridLayout_5->addWidget(groupBox_4, 0, 1, 1, 1);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        sizePolicy2.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy2);
        gridLayout = new QGridLayout(groupBox_3);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_dispaly = new QLabel(groupBox_3);
        label_dispaly->setObjectName(QString::fromUtf8("label_dispaly"));
        QSizePolicy sizePolicy4(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_dispaly->sizePolicy().hasHeightForWidth());
        label_dispaly->setSizePolicy(sizePolicy4);
        label_dispaly->setMinimumSize(QSize(100, 0));
        QFont font;
        font.setPointSize(72);
        font.setBold(false);
        label_dispaly->setFont(font);
        label_dispaly->setScaledContents(false);
        label_dispaly->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_dispaly, 0, 0, 1, 3);


        gridLayout_5->addWidget(groupBox_3, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 966, 22));
        menufile = new QMenu(menubar);
        menufile->setObjectName(QString::fromUtf8("menufile"));
        menunet = new QMenu(menubar);
        menunet->setObjectName(QString::fromUtf8("menunet"));
        menudetect = new QMenu(menubar);
        menudetect->setObjectName(QString::fromUtf8("menudetect"));
        menuTrack = new QMenu(menubar);
        menuTrack->setObjectName(QString::fromUtf8("menuTrack"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menufile->menuAction());
        menubar->addAction(menunet->menuAction());
        menubar->addAction(menudetect->menuAction());
        menubar->addAction(menuTrack->menuAction());
        menufile->addAction(actionopen);
        menufile->addAction(actionsave);
        menufile->addAction(actionsave_as);
        menunet->addAction(action_custom_net);
        menunet->addSeparator();
        menunet->addAction(action_yolov3_net);
        menunet->addAction(action_yolov4_net);
        menunet->addAction(actionyolov4fastest);
        menunet->addAction(action_yolobile_net);
        menunet->addSeparator();
        menunet->addAction(actionuse_cuda);
        menudetect->addSeparator();
        menudetect->addAction(action_IMG_path);
        menudetect->addAction(action_Video_path);
        menudetect->addAction(action_ZED_CAM);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        action_custom_net->setText(QApplication::translate("MainWindow", "custom", nullptr));
        action_yolov3_net->setText(QApplication::translate("MainWindow", "yolov3", nullptr));
        action_yolov4_net->setText(QApplication::translate("MainWindow", "yolov4", nullptr));
        actionyolov4fastest->setText(QApplication::translate("MainWindow", "yolov4_fastest_net", nullptr));
        action_yolobile_net->setText(QApplication::translate("MainWindow", "yolobile", nullptr));
        actionuse_cuda->setText(QApplication::translate("MainWindow", "use cuda", nullptr));
        actionopen->setText(QApplication::translate("MainWindow", "open", nullptr));
        actionsave->setText(QApplication::translate("MainWindow", "save", nullptr));
        actionsave_as->setText(QApplication::translate("MainWindow", "save as", nullptr));
        action_IMG_path->setText(QApplication::translate("MainWindow", "IMG", nullptr));
        action_Video_path->setText(QApplication::translate("MainWindow", "Video", nullptr));
        action_ZED_CAM->setText(QApplication::translate("MainWindow", "ZED CAM", nullptr));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Result", nullptr));
        lb_compute_time->setText(QApplication::translate("MainWindow", "120", nullptr));
        lb_inference_time->setText(QApplication::translate("MainWindow", "10", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Max FPS: ", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "ms", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "Compute Time: ", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "ms", nullptr));
        lb_max_fps->setText(QApplication::translate("MainWindow", "200", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Inference Time: ", nullptr));
        pb_start_detect->setText(QApplication::translate("MainWindow", "start", nullptr));
        pb_pause_detect->setText(QApplication::translate("MainWindow", "pause", nullptr));
        pb_stop_detect->setText(QApplication::translate("MainWindow", "stop", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Display", nullptr));
        label_dispaly->setText(QApplication::translate("MainWindow", "no signal", nullptr));
        menufile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        menunet->setTitle(QApplication::translate("MainWindow", "Net", nullptr));
        menudetect->setTitle(QApplication::translate("MainWindow", "Detect", nullptr));
        menuTrack->setTitle(QApplication::translate("MainWindow", "Track", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
