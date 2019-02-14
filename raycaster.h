#ifndef raycaster
#define raycaster
#include <QDialog>
#include <QWidget>
#include <QString>
namespace Ui {
class Raycaster;
}
class Raycaster : public QDialog{
    Q_OBJECT
public:
    explicit Raycaster(QWidget *parent = 0);
    ~Raycaster();
    double *point1Settings();
    double *point2Settings();
    double *point3Settings();
    double *lightSettings();
    QString getBlendMode();
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

    void on_Raycaster_accepted();

private:
    Ui::Raycaster *dui;
    QString blendMode;
};

#endif

