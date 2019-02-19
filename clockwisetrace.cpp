#include "clockwisetrace.h"
#include "ui_clockwisetrace.h"

ClockWiseTrace::ClockWiseTrace(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClockWiseTrace)
{
    ui->setupUi(this);
}

ClockWiseTrace::~ClockWiseTrace()
{
    delete ui;
}

void ClockWiseTrace::on_buttonBox_accepted()
{
     maxDistance = ui->maxDistance->value();
     retryTimes = ui->retryTimes->value();
     lower = ui->lower->value();
     upper = ui->upper->value();
     step = ui->steps->value();
     points = ui->requiredPoints->value();
}
