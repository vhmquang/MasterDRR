#include "marchingcubes.h"
#include "ui_marchingcubes.h"
#include <qdebug.h>
marchingcubes::marchingcubes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::marchingcubes)
{
    ui->setupUi(this);
}

marchingcubes::~marchingcubes()
{
    delete ui;
}

void marchingcubes::on_marchingcubes_accepted()
{   qDebug() << "Accept";
    if (ui->_UseValue->isChecked()){
    marchingCubes = "value";
    contourValues.insert(0,ui->_Isovalue1->value());
    contourValues.insert(1,ui->_Isovalue2->value());
    contourValues.insert(2,ui->_Isovalue3->value());
    contourValues.insert(3,ui->_Isovalue4->value());
    }
    else{
    marchingCubes = "range";
    numberOfContour = ui->_NumberOfContour->value();
    max = ui->_MaximumValue->value();
    min = ui->_MinimumValue->value();
    }
    normals = ui->_NormalOption->isChecked();
    gradient = ui->_GradientOption->isChecked();
    color = ui->_ColorOption->isChecked();
}
QString marchingcubes::getMarchingCubes(){
    return marchingCubes;
}
QList<int> marchingcubes::getContourValues(){
    return contourValues;
}
int marchingcubes::getMax(){
    return max;
}
int marchingcubes::getMin(){
    return min;
}
int marchingcubes::getNumberOfContour(){
    return numberOfContour;
}
bool marchingcubes::getNormals(){
    return normals;
}
bool marchingcubes::getGradient(){
    return gradient;
}
bool marchingcubes::getColor(){
    return color;
}
