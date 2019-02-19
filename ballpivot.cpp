#include "ballpivot.h"
#include "ui_ballpivot.h"

ballpivot::ballpivot(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ballpivot)
{
    ui->setupUi(this);
}

ballpivot::~ballpivot()
{
    delete ui;
}

void ballpivot::on_buttonBox_accepted()
{
    angle = ui->angle->value();
    radius = ui->radius->value();
    cluster = ui->cluster->value();
}
