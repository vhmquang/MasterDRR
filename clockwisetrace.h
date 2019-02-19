#ifndef CLOCKWISETRACE_H
#define CLOCKWISETRACE_H

#include <QDialog>

namespace Ui {
class ClockWiseTrace;
}

class ClockWiseTrace : public QDialog
{
    Q_OBJECT

public:
    explicit ClockWiseTrace(QWidget *parent = 0);
    int maxDistance;
    int retryTimes;
    int lower;
    int upper;
    int step;
    int points;
    ~ClockWiseTrace();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::ClockWiseTrace *ui;
};

#endif // CLOCKWISETRACE_H
