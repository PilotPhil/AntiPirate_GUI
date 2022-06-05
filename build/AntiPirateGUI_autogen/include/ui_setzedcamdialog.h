/********************************************************************************
** Form generated from reading UI file 'setzedcamdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETZEDCAMDIALOG_H
#define UI_SETZEDCAMDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SetZedCamDialog
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QLabel *label_11;
    QComboBox *cbx_resolution_setting;
    QLabel *label_12;
    QComboBox *cbx_fps_setting;
    QLabel *label_13;
    QComboBox *cbx_depth_mode_setting;
    QLabel *label_14;
    QComboBox *cbx_unit_setting;
    QWidget *widget;
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;
    QSpacerItem *horizontalSpacer_5;

    void setupUi(QDialog *SetZedCamDialog)
    {
        if (SetZedCamDialog->objectName().isEmpty())
            SetZedCamDialog->setObjectName(QString::fromUtf8("SetZedCamDialog"));
        SetZedCamDialog->resize(373, 242);
        gridLayout_3 = new QGridLayout(SetZedCamDialog);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBox_2 = new QGroupBox(SetZedCamDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_2->addWidget(label_11, 0, 0, 1, 1);

        cbx_resolution_setting = new QComboBox(groupBox_2);
        cbx_resolution_setting->addItem(QString());
        cbx_resolution_setting->addItem(QString());
        cbx_resolution_setting->addItem(QString());
        cbx_resolution_setting->addItem(QString());
        cbx_resolution_setting->setObjectName(QString::fromUtf8("cbx_resolution_setting"));

        gridLayout_2->addWidget(cbx_resolution_setting, 0, 1, 1, 1);

        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_2->addWidget(label_12, 1, 0, 1, 1);

        cbx_fps_setting = new QComboBox(groupBox_2);
        cbx_fps_setting->addItem(QString());
        cbx_fps_setting->addItem(QString());
        cbx_fps_setting->addItem(QString());
        cbx_fps_setting->setObjectName(QString::fromUtf8("cbx_fps_setting"));

        gridLayout_2->addWidget(cbx_fps_setting, 1, 1, 1, 1);

        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_2->addWidget(label_13, 2, 0, 1, 1);

        cbx_depth_mode_setting = new QComboBox(groupBox_2);
        cbx_depth_mode_setting->addItem(QString());
        cbx_depth_mode_setting->addItem(QString());
        cbx_depth_mode_setting->addItem(QString());
        cbx_depth_mode_setting->setObjectName(QString::fromUtf8("cbx_depth_mode_setting"));

        gridLayout_2->addWidget(cbx_depth_mode_setting, 2, 1, 1, 1);

        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_2->addWidget(label_14, 3, 0, 1, 1);

        cbx_unit_setting = new QComboBox(groupBox_2);
        cbx_unit_setting->addItem(QString());
        cbx_unit_setting->addItem(QString());
        cbx_unit_setting->addItem(QString());
        cbx_unit_setting->addItem(QString());
        cbx_unit_setting->addItem(QString());
        cbx_unit_setting->addItem(QString());
        cbx_unit_setting->setObjectName(QString::fromUtf8("cbx_unit_setting"));

        gridLayout_2->addWidget(cbx_unit_setting, 3, 1, 1, 1);


        gridLayout_3->addWidget(groupBox_2, 0, 0, 1, 1);

        widget = new QWidget(SetZedCamDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        buttonBox = new QDialogButtonBox(widget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 0, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(162, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 0, 0, 1, 1);


        gridLayout_3->addWidget(widget, 1, 0, 1, 1);


        retranslateUi(SetZedCamDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), SetZedCamDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SetZedCamDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SetZedCamDialog);
    } // setupUi

    void retranslateUi(QDialog *SetZedCamDialog)
    {
        SetZedCamDialog->setWindowTitle(QApplication::translate("SetZedCamDialog", "Dialog", nullptr));
        groupBox_2->setTitle(QApplication::translate("SetZedCamDialog", "Setting", nullptr));
        label_11->setText(QApplication::translate("SetZedCamDialog", "Resolution", nullptr));
        cbx_resolution_setting->setItemText(0, QApplication::translate("SetZedCamDialog", "HD720", nullptr));
        cbx_resolution_setting->setItemText(1, QApplication::translate("SetZedCamDialog", "HD1080", nullptr));
        cbx_resolution_setting->setItemText(2, QApplication::translate("SetZedCamDialog", "HD2K", nullptr));
        cbx_resolution_setting->setItemText(3, QApplication::translate("SetZedCamDialog", "VGA", nullptr));

        label_12->setText(QApplication::translate("SetZedCamDialog", "FPS", nullptr));
        cbx_fps_setting->setItemText(0, QApplication::translate("SetZedCamDialog", "15", nullptr));
        cbx_fps_setting->setItemText(1, QApplication::translate("SetZedCamDialog", "30", nullptr));
        cbx_fps_setting->setItemText(2, QApplication::translate("SetZedCamDialog", "60", nullptr));

        label_13->setText(QApplication::translate("SetZedCamDialog", "Depth mode", nullptr));
        cbx_depth_mode_setting->setItemText(0, QApplication::translate("SetZedCamDialog", "PERFORMANCE", nullptr));
        cbx_depth_mode_setting->setItemText(1, QApplication::translate("SetZedCamDialog", "QUALITY", nullptr));
        cbx_depth_mode_setting->setItemText(2, QApplication::translate("SetZedCamDialog", "ULTRA", nullptr));

        label_14->setText(QApplication::translate("SetZedCamDialog", "Unit", nullptr));
        cbx_unit_setting->setItemText(0, QApplication::translate("SetZedCamDialog", "MILLIMETER", nullptr));
        cbx_unit_setting->setItemText(1, QApplication::translate("SetZedCamDialog", "CENTIMETER", nullptr));
        cbx_unit_setting->setItemText(2, QApplication::translate("SetZedCamDialog", "METER", nullptr));
        cbx_unit_setting->setItemText(3, QApplication::translate("SetZedCamDialog", "New Item", nullptr));
        cbx_unit_setting->setItemText(4, QApplication::translate("SetZedCamDialog", "INCH", nullptr));
        cbx_unit_setting->setItemText(5, QApplication::translate("SetZedCamDialog", "FOOT", nullptr));

    } // retranslateUi

};

namespace Ui {
    class SetZedCamDialog: public Ui_SetZedCamDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETZEDCAMDIALOG_H
