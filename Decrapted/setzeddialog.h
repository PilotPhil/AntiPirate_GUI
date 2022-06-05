#ifndef SETZEDDIALOG_H
#define SETZEDDIALOG_H

#include <QDialog>

namespace Ui {
class SetZEDDialog;
}

class SetZEDDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SetZEDDialog(QWidget *parent = nullptr);
    ~SetZEDDialog();

private:
    Ui::SetZEDDialog *ui;
};

#endif // SETZEDDIALOG_H
