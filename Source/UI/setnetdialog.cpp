#include "setnetdialog.h"
#include "ui_setnetdialog.h"

SetNetDialog::SetNetDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::SetNetDialog) {
  ui->setupUi(this);

  this->setWindowTitle("Select Your Train Results");

  net = nullptr;
}

SetNetDialog::~SetNetDialog() {
  delete ui;
  delete net;
}

void SetNetDialog::on_cbx_choose_net_currentIndexChanged(int index) {

  double _confThreshold = 0.0;
  double _nmsThreshold = 0.0;
  int _inpWidth = 0;
  int _inpHeight = 0;

  switch (index) {
  case 0: {
    // yolov3 net
    _confThreshold = 0.5;
    _nmsThreshold = 0.4;
    _inpWidth = 416;
    _inpHeight = 416;
    break;
  }

  case 1: {
    // yolov4 net
    _confThreshold = 0.5;
    _nmsThreshold = 0.4;
    _inpWidth = 608;
    _inpHeight = 608;
    break;
  }

  case 2: {
    // yolov4-tiny net
    _confThreshold = 0.5;
    _nmsThreshold = 0.4;
    _inpWidth = 320;
    _inpHeight = 320;
    break;
  }

  case 3: {
    // yolovbile net
    _confThreshold = 0.5;
    _nmsThreshold = 0.4;
    _inpWidth = 320;
    _inpHeight = 320;
  }

  default:
    break;
  }

  ui->dsb_confidence_threshold->setValue(_confThreshold);
  ui->dsb_nonman_suppression_threshold->setValue(_nmsThreshold);
  ui->sb_width_new_input_img->setValue(_inpWidth);
  ui->sb_height_new_input_img->setValue(_inpHeight);
}

void SetNetDialog::on_btn_select_names_clicked() {
  QString pth = QFileDialog::getOpenFileName();
  ui->le_names_pth->setText(pth);
}

void SetNetDialog::on_btn_select_cfg_clicked() {
  QString pth = QFileDialog::getOpenFileName();
  ui->le_cfg_pth->setText(pth);
}

void SetNetDialog::on_btn_select_weights_clicked() {
  QString pth = QFileDialog::getOpenFileName();
  ui->le_weights_pth->setText(pth);
}

void SetNetDialog::on_buttonBox_accepted() {

  this->_use_cuda = ui->cb_use_cuda->isChecked();

  this->net = NetConfig::GetCustomNet(
      ui->dsb_confidence_threshold->value(),
      ui->dsb_nonman_suppression_threshold->value(),
      ui->sb_width_new_input_img->value(), ui->sb_height_new_input_img->value(),
      ui->le_names_pth->text().toStdString(),
      ui->le_cfg_pth->text().toStdString(),
      ui->le_weights_pth->text().toStdString(),
      ui->cbx_choose_net->currentText().toStdString());
}
