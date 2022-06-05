#include "setzedcamdialog.h"
#include "ui_setzedcamdialog.h"

SetZedCamDialog::SetZedCamDialog(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::SetZedCamDialog)
{
    ui->setupUi(this);

    this->setWindowTitle("ZED Camera Config");
}

SetZedCamDialog::~SetZedCamDialog()
{
    delete ui;
}

void SetZedCamDialog::on_cbx_resolution_setting_currentTextChanged(const QString& arg1)
{
    string resolution = arg1.toStdString();

    if (resolution == "HD720") {
        this->_init_params.camera_resolution = sl::RESOLUTION::HD720;
        ui->cbx_fps_setting->clear();
        QStringList fpslist;
        fpslist << "15"
                << "30"
                << "60";
        ui->cbx_fps_setting->addItems(fpslist);
    } else if (resolution == "HD1080") {
        this->_init_params.camera_resolution = sl::RESOLUTION::HD1080;
        ui->cbx_fps_setting->clear();
        QStringList fpslist;
        fpslist << "15"
                << "30";
        ui->cbx_fps_setting->addItems(fpslist);
    } else if (resolution == "HD2K") {
        ui->cbx_fps_setting->clear();
        QStringList fpslist;
        fpslist << "15";
        ui->cbx_fps_setting->addItems(fpslist);
        this->_init_params.camera_resolution = sl::RESOLUTION::HD2K;
    } else if (resolution == "VGA") {
        ui->cbx_fps_setting->clear();
        QStringList fpslist;
        fpslist << "15"
                << "30"
                << "60"
                << "100";
        ui->cbx_fps_setting->addItems(fpslist);
        this->_init_params.camera_resolution = sl::RESOLUTION::VGA;
    } else {
        this->_init_params.camera_resolution = sl::RESOLUTION::HD720;
        ui->cbx_fps_setting->clear();
        QStringList fpslist;
        fpslist << "15"
                << "30"
                << "60";
        ui->cbx_fps_setting->addItems(fpslist);
    }
}

void SetZedCamDialog::on_cbx_depth_mode_setting_currentTextChanged(const QString& arg1)
{
    string depth_mode = arg1.toStdString();

    if (depth_mode == "PERFORMANCE") {
        this->_init_params.depth_mode = sl::DEPTH_MODE::PERFORMANCE;
    } else if (depth_mode == "QUALITY") {
        this->_init_params.depth_mode = sl::DEPTH_MODE::QUALITY;
    } else if (depth_mode == "ULTRA") {
        this->_init_params.depth_mode = sl::DEPTH_MODE::ULTRA;
    } else {
        this->_init_params.depth_mode = sl::DEPTH_MODE::PERFORMANCE;
    }
}

void SetZedCamDialog::on_cbx_unit_setting_currentTextChanged(const QString& arg1)
{
    string unit = arg1.toStdString();

    if (unit == "MILLIMETER") {
        this->_init_params.coordinate_units = sl::UNIT::MILLIMETER;
    } else if (unit == "CENTIMETER") {
        this->_init_params.coordinate_units = sl::UNIT::CENTIMETER;
    } else if (unit == "METER") {
        this->_init_params.coordinate_units = sl::UNIT::METER;
    } else if (unit == "INCH") {
        this->_init_params.coordinate_units = sl::UNIT::INCH;
    } else if (unit == "FOOT") {
        this->_init_params.coordinate_units = sl::UNIT::FOOT;
    } else {
        this->_init_params.coordinate_units = sl::UNIT::MILLIMETER;
    }
}

void SetZedCamDialog::on_cbx_fps_setting_currentTextChanged(const QString& arg1)
{
    string fps = arg1.toStdString();

    if (fps == "15") {
        this->_init_params.camera_fps = 15;
    } else if (fps == "30") {
        this->_init_params.camera_fps = 30;
    } else if (fps == "60") {
        this->_init_params.camera_fps = 60;
    } else {
        this->_init_params.camera_fps = 15;
    }
}
