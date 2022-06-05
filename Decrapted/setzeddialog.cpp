#include "setzeddialog.h"
#include "ui_setzeddialog.h"

SetZEDDialog::SetZEDDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetZEDDialog)
{
    ui->setupUi(this);
}

SetZEDDialog::~SetZEDDialog()
{
    delete ui;
}
