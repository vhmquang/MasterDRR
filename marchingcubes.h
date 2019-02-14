#ifndef MARCHINGCUBES_H
#define MARCHINGCUBES_H

#include <QDialog>
#include <QStringList>
namespace Ui {
class marchingcubes;
}

class marchingcubes : public QDialog
{
    Q_OBJECT

public:
    explicit marchingcubes(QWidget *parent = 0);
    ~marchingcubes();
    QString getMarchingCubes();
    QList<int> getContourValues();
    int getMax();
    int getMin();
    int getNumberOfContour();
    bool getNormals();
    bool getGradient();
    bool getColor();
private slots:

    void on_marchingcubes_accepted();

private:
    Ui::marchingcubes *ui;
    QString marchingCubes ;
    QList<int> contourValues;
    int max;
    int min;
    int numberOfContour;
    bool normals;
    bool gradient;
    bool color;
};

#endif // MARCHINGCUBES_H
