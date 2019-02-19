#ifndef BALLPIVOT_H
#define BALLPIVOT_H

#include <QDialog>

namespace Ui {
class ballpivot;
}

class ballpivot : public QDialog
{
    Q_OBJECT

public:
    explicit ballpivot(QWidget *parent = 0);
    double angle;
    double radius;
    double cluster;
    ~ballpivot();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::ballpivot *ui;
};

#endif // BALLPIVOT_H
