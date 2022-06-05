#ifndef SETZEDCAMDIALOG_H
#define SETZEDCAMDIALOG_H

#include <QDialog>

#include <string>

#include <sl/Camera.hpp>
#include <opencv2/dnn.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

namespace Ui {
class SetZedCamDialog;
}

class SetZedCamDialog : public QDialog {
    Q_OBJECT

public:
    explicit SetZedCamDialog(QWidget* parent = nullptr);
    ~SetZedCamDialog();

    sl::InitParameters GetCamInitParams() const { return this->_init_params; }

private slots:
    void on_cbx_resolution_setting_currentTextChanged(const QString& arg1);

    void on_cbx_depth_mode_setting_currentTextChanged(const QString& arg1);

    void on_cbx_unit_setting_currentTextChanged(const QString& arg1);

    void on_cbx_fps_setting_currentTextChanged(const QString& arg1);

private:
    Ui::SetZedCamDialog* ui;

    sl::InitParameters _init_params;
};

#endif // SETZEDCAMDIALOG_H
