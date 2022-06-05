    #ifndef SETNETDIALOG_H
#define SETNETDIALOG_H

#include <QDialog>
#include <QFileDialog>

#include "NetConfig.h"

namespace Ui {
class SetNetDialog;
}

class SetNetDialog : public QDialog {
  Q_OBJECT

public:
  explicit SetNetDialog(QWidget *parent = nullptr);
  ~SetNetDialog();

  NetConfig Net() const { return *net; }
  bool UseCuda() const { return _use_cuda; }

private slots:
  void on_cbx_choose_net_currentIndexChanged(int index);

  void on_btn_select_names_clicked();

  void on_btn_select_cfg_clicked();

  void on_btn_select_weights_clicked();

  void on_buttonBox_accepted();

private:
  Ui::SetNetDialog *ui;

  NetConfig *net;

  bool _use_cuda = false;
};

#endif // SETNETDIALOG_H
