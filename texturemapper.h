#ifndef TEXTUREMAPPER_H
#define TEXTUREMAPPER_H

#include <QDialog>

namespace Ui {
class texturemapper;
}

class texturemapper : public QDialog
{
    Q_OBJECT

public:
    explicit texturemapper(QWidget *parent = 0);
    ~texturemapper();
    double *point1Settings();
    double *point2Settings();
    double *point3Settings();
    double *lightSettings();
    double getSamplingDistant();
    bool getUseCompress();
private slots:

    void on__P1_R_valueChanged(int value);

    void on__P1_G_valueChanged(int value);

    void on__P1_B_valueChanged(int value);

    void on__P2_R_valueChanged(int value);

    void on__P2_G_valueChanged(int value);

    void on__P2_B_valueChanged(int value);

    void on__P3_R_valueChanged(int value);

    void on__P3_G_valueChanged(int value);

    void on__P3_B_valueChanged(int value);


private:
    Ui::texturemapper *ui;
};

#endif // TEXTUREMAPPER_H
