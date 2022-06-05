/********************************************************************************
** Form generated from reading UI file 'setnetdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETNETDIALOG_H
#define UI_SETNETDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_SetNetDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label_8;
    QComboBox *cbx_choose_net;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label;
    QDoubleSpinBox *dsb_confidence_threshold;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QDoubleSpinBox *dsb_nonman_suppression_threshold;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_3;
    QSpinBox *sb_width_new_input_img;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_4;
    QSpinBox *sb_height_new_input_img;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_5;
    QLineEdit *le_names_pth;
    QPushButton *btn_select_names;
    QLabel *label_6;
    QLineEdit *le_cfg_pth;
    QPushButton *btn_select_cfg;
    QLabel *label_7;
    QLineEdit *le_weights_pth;
    QPushButton *btn_select_weights;
    QHBoxLayout *horizontalLayout;
    QCheckBox *cb_use_cuda;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SetNetDialog)
    {
        if (SetNetDialog->objectName().isEmpty())
            SetNetDialog->setObjectName(QString::fromUtf8("SetNetDialog"));
        SetNetDialog->resize(410, 481);
        gridLayout = new QGridLayout(SetNetDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_8 = new QLabel(SetNetDialog);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 0, 0, 1, 1);

        cbx_choose_net = new QComboBox(SetNetDialog);
        cbx_choose_net->addItem(QString());
        cbx_choose_net->addItem(QString());
        cbx_choose_net->addItem(QString());
        cbx_choose_net->addItem(QString());
        cbx_choose_net->setObjectName(QString::fromUtf8("cbx_choose_net"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cbx_choose_net->sizePolicy().hasHeightForWidth());
        cbx_choose_net->setSizePolicy(sizePolicy);
        cbx_choose_net->setMinimumSize(QSize(300, 0));

        gridLayout->addWidget(cbx_choose_net, 1, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(77, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 1, 1, 1, 1);

        label = new QLabel(SetNetDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 2, 0, 1, 1);

        dsb_confidence_threshold = new QDoubleSpinBox(SetNetDialog);
        dsb_confidence_threshold->setObjectName(QString::fromUtf8("dsb_confidence_threshold"));
        sizePolicy.setHeightForWidth(dsb_confidence_threshold->sizePolicy().hasHeightForWidth());
        dsb_confidence_threshold->setSizePolicy(sizePolicy);
        dsb_confidence_threshold->setMinimumSize(QSize(300, 0));
        dsb_confidence_threshold->setDecimals(2);
        dsb_confidence_threshold->setMaximum(1.000000000000000);
        dsb_confidence_threshold->setSingleStep(0.010000000000000);
        dsb_confidence_threshold->setValue(0.500000000000000);

        gridLayout->addWidget(dsb_confidence_threshold, 3, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(83, 19, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 1, 1, 1);

        label_2 = new QLabel(SetNetDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 4, 0, 1, 1);

        dsb_nonman_suppression_threshold = new QDoubleSpinBox(SetNetDialog);
        dsb_nonman_suppression_threshold->setObjectName(QString::fromUtf8("dsb_nonman_suppression_threshold"));
        dsb_nonman_suppression_threshold->setMinimumSize(QSize(300, 0));
        dsb_nonman_suppression_threshold->setMaximum(1.000000000000000);
        dsb_nonman_suppression_threshold->setSingleStep(0.010000000000000);
        dsb_nonman_suppression_threshold->setValue(0.400000000000000);

        gridLayout->addWidget(dsb_nonman_suppression_threshold, 5, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(83, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 5, 1, 1, 1);

        label_3 = new QLabel(SetNetDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 6, 0, 1, 1);

        sb_width_new_input_img = new QSpinBox(SetNetDialog);
        sb_width_new_input_img->setObjectName(QString::fromUtf8("sb_width_new_input_img"));
        sb_width_new_input_img->setMinimumSize(QSize(300, 0));
        sb_width_new_input_img->setMaximum(1024);
        sb_width_new_input_img->setValue(416);

        gridLayout->addWidget(sb_width_new_input_img, 7, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(83, 19, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 7, 1, 1, 1);

        label_4 = new QLabel(SetNetDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 8, 0, 1, 1);

        sb_height_new_input_img = new QSpinBox(SetNetDialog);
        sb_height_new_input_img->setObjectName(QString::fromUtf8("sb_height_new_input_img"));
        sb_height_new_input_img->setMinimumSize(QSize(300, 0));
        sb_height_new_input_img->setMaximum(1024);
        sb_height_new_input_img->setValue(416);

        gridLayout->addWidget(sb_height_new_input_img, 9, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(83, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 9, 1, 1, 1);

        label_5 = new QLabel(SetNetDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 10, 0, 1, 1);

        le_names_pth = new QLineEdit(SetNetDialog);
        le_names_pth->setObjectName(QString::fromUtf8("le_names_pth"));
        le_names_pth->setMinimumSize(QSize(300, 0));

        gridLayout->addWidget(le_names_pth, 11, 0, 1, 1);

        btn_select_names = new QPushButton(SetNetDialog);
        btn_select_names->setObjectName(QString::fromUtf8("btn_select_names"));

        gridLayout->addWidget(btn_select_names, 11, 1, 1, 1);

        label_6 = new QLabel(SetNetDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 12, 0, 1, 1);

        le_cfg_pth = new QLineEdit(SetNetDialog);
        le_cfg_pth->setObjectName(QString::fromUtf8("le_cfg_pth"));
        le_cfg_pth->setMinimumSize(QSize(300, 0));

        gridLayout->addWidget(le_cfg_pth, 13, 0, 1, 1);

        btn_select_cfg = new QPushButton(SetNetDialog);
        btn_select_cfg->setObjectName(QString::fromUtf8("btn_select_cfg"));

        gridLayout->addWidget(btn_select_cfg, 13, 1, 1, 1);

        label_7 = new QLabel(SetNetDialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 14, 0, 1, 1);

        le_weights_pth = new QLineEdit(SetNetDialog);
        le_weights_pth->setObjectName(QString::fromUtf8("le_weights_pth"));
        le_weights_pth->setMinimumSize(QSize(300, 0));

        gridLayout->addWidget(le_weights_pth, 15, 0, 1, 1);

        btn_select_weights = new QPushButton(SetNetDialog);
        btn_select_weights->setObjectName(QString::fromUtf8("btn_select_weights"));

        gridLayout->addWidget(btn_select_weights, 15, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        cb_use_cuda = new QCheckBox(SetNetDialog);
        cb_use_cuda->setObjectName(QString::fromUtf8("cb_use_cuda"));
        cb_use_cuda->setChecked(true);

        horizontalLayout->addWidget(cb_use_cuda);

        buttonBox = new QDialogButtonBox(SetNetDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);


        gridLayout->addLayout(horizontalLayout, 16, 0, 1, 2);


        retranslateUi(SetNetDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), SetNetDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SetNetDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SetNetDialog);
    } // setupUi

    void retranslateUi(QDialog *SetNetDialog)
    {
        SetNetDialog->setWindowTitle(QApplication::translate("SetNetDialog", "Dialog", nullptr));
        label_8->setText(QApplication::translate("SetNetDialog", "Netname", nullptr));
        cbx_choose_net->setItemText(0, QApplication::translate("SetNetDialog", "yolov3", nullptr));
        cbx_choose_net->setItemText(1, QApplication::translate("SetNetDialog", "yolov4", nullptr));
        cbx_choose_net->setItemText(2, QApplication::translate("SetNetDialog", "yolov4-fastest", nullptr));
        cbx_choose_net->setItemText(3, QApplication::translate("SetNetDialog", "yolobile", nullptr));

        label->setText(QApplication::translate("SetNetDialog", "Confidence threshold", nullptr));
        label_2->setText(QApplication::translate("SetNetDialog", "Non-maximum suppression threshold", nullptr));
        label_3->setText(QApplication::translate("SetNetDialog", "Width of network's input image", nullptr));
        label_4->setText(QApplication::translate("SetNetDialog", "Height of network's input image", nullptr));
        label_5->setText(QApplication::translate("SetNetDialog", "ClassesFile---.names", nullptr));
        btn_select_names->setText(QApplication::translate("SetNetDialog", "select", nullptr));
        label_6->setText(QApplication::translate("SetNetDialog", "ModelConfiguration---.cfg", nullptr));
        btn_select_cfg->setText(QApplication::translate("SetNetDialog", "select", nullptr));
        label_7->setText(QApplication::translate("SetNetDialog", "ModelWeights---.weights", nullptr));
        btn_select_weights->setText(QApplication::translate("SetNetDialog", "select", nullptr));
        cb_use_cuda->setText(QApplication::translate("SetNetDialog", "Use CUDA", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SetNetDialog: public Ui_SetNetDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETNETDIALOG_H
