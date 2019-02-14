#include "texturemapper.h"
#include "ui_texturemapper.h"

texturemapper::texturemapper(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::texturemapper)
{
    ui->setupUi(this);
}

texturemapper::~texturemapper()
{
    delete ui;
}
double* texturemapper::point1Settings(){
    static double point1[6];
    point1[0] = ui->_P1_Value->value();
    point1[1] = ui->_P1_R->value();
    point1[2] = ui->_P1_G->value();
    point1[3] = ui->_P1_B->value();
    point1[4] = ui->_P1_Opacity->value();
    point1[5] = ui->_P1_Gradient->value();
    return point1;
}
double* texturemapper::point2Settings(){
    static double point2[6];
    point2[0] = ui->_P2_Value->value();
    point2[1] = ui->_P2_R->value();
    point2[2] = ui->_P2_G->value();
    point2[3] = ui->_P2_B->value();
    point2[4] = ui->_P2_Opacity->value();
    point2[5] = ui->_P2_Gradient->value();
    return point2;
}
double* texturemapper::point3Settings(){
    static double point3[6];
    point3[0] = ui->_P3_Value->value();
    point3[1] = ui->_P3_R->value();
    point3[2] = ui->_P3_G->value();
    point3[3] = ui->_P3_B->value();
    point3[4] = ui->_P3_Opacity->value();
    point3[5] = ui->_P3_Gradient->value();
    return point3;
}
double *texturemapper::lightSettings(){
    static double light[3];
    light[0] = ui->_Ambient->value();
    light[1] = ui->_Diffuse->value();
    light[2] = ui->_Specular->value();
    return light;
}
void texturemapper::on__P1_R_valueChanged(int value)
{
    ui->R1->setText(QString::number(value));
}

void texturemapper::on__P1_G_valueChanged(int value)
{
    ui->G1->setText(QString::number(value));
}

void texturemapper::on__P1_B_valueChanged(int value)
{
    ui->B1->setText(QString::number(value));
}

void texturemapper::on__P2_R_valueChanged(int value)
{
    ui->R2->setText(QString::number(value));
}

void texturemapper::on__P2_G_valueChanged(int value)
{
    ui->G2->setText(QString::number(value));
}

void texturemapper::on__P2_B_valueChanged(int value)
{
    ui->B2->setText(QString::number(value));
}
void texturemapper::on__P3_R_valueChanged(int value)
{
    ui->R3->setText(QString::number(value));
}

void texturemapper::on__P3_G_valueChanged(int value)
{
    ui->G3->setText(QString::number(value));
}

void texturemapper::on__P3_B_valueChanged(int value)
{
    ui->B3->setText(QString::number(value));
}
double texturemapper::getSamplingDistant(){
    return ui->_distant->value();
}
bool texturemapper::getUseCompress(){
    return ui->_useCompress->isChecked();
}
