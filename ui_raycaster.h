/********************************************************************************
** Form generated from reading UI file 'raycaster.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RAYCASTER_H
#define UI_RAYCASTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Raycaster
{
public:
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox_3;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QSlider *_P3_R;
    QSlider *_P3_G;
    QSlider *_P3_B;
    QLabel *label_23;
    QDoubleSpinBox *_P3_Opacity;
    QSpinBox *_P3_Value;
    QLabel *label_24;
    QDoubleSpinBox *_P3_Gradient;
    QLineEdit *R3;
    QLineEdit *G3;
    QLineEdit *B3;
    QGroupBox *groupBox_2;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QSlider *_P2_R;
    QSlider *_P2_G;
    QSlider *_P2_B;
    QLabel *label_17;
    QDoubleSpinBox *_P2_Opacity;
    QSpinBox *_P2_Value;
    QLabel *label_18;
    QDoubleSpinBox *_P2_Gradient;
    QLineEdit *R2;
    QLineEdit *G2;
    QLineEdit *B2;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_5;
    QSlider *_P1_R;
    QSlider *_P1_G;
    QSlider *_P1_B;
    QLabel *label_3;
    QDoubleSpinBox *_P1_Opacity;
    QSpinBox *_P1_Value;
    QLabel *label_6;
    QDoubleSpinBox *_P1_Gradient;
    QLineEdit *R1;
    QLineEdit *G1;
    QLineEdit *B1;
    QGroupBox *groupBox_4;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QDoubleSpinBox *_Ambient;
    QDoubleSpinBox *_Diffuse;
    QDoubleSpinBox *_Specular;
    QGroupBox *groupBox_5;
    QRadioButton *_blendMode_addictive;
    QRadioButton *_blendMode_composite;
    QRadioButton *_blendMode_maxip;
    QRadioButton *_blendMode_minip;

    void setupUi(QDialog *Raycaster)
    {
        if (Raycaster->objectName().isEmpty())
            Raycaster->setObjectName(QStringLiteral("Raycaster"));
        Raycaster->resize(561, 721);
        Raycaster->setModal(true);
        buttonBox = new QDialogButtonBox(Raycaster);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(180, 680, 161, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);
        groupBox_3 = new QGroupBox(Raycaster);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 430, 531, 151));
        label_19 = new QLabel(groupBox_3);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(20, 20, 111, 21));
        label_19->setAlignment(Qt::AlignCenter);
        label_20 = new QLabel(groupBox_3);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(30, 60, 91, 16));
        QFont font;
        font.setPointSize(12);
        label_20->setFont(font);
        label_20->setTextFormat(Qt::AutoText);
        label_21 = new QLabel(groupBox_3);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(30, 90, 91, 16));
        label_21->setFont(font);
        label_21->setTextFormat(Qt::AutoText);
        label_22 = new QLabel(groupBox_3);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(30, 120, 91, 16));
        label_22->setFont(font);
        label_22->setTextFormat(Qt::AutoText);
        _P3_R = new QSlider(groupBox_3);
        _P3_R->setObjectName(QStringLiteral("_P3_R"));
        _P3_R->setGeometry(QRect(50, 60, 160, 19));
        _P3_R->setMaximum(255);
        _P3_R->setOrientation(Qt::Horizontal);
        _P3_G = new QSlider(groupBox_3);
        _P3_G->setObjectName(QStringLiteral("_P3_G"));
        _P3_G->setGeometry(QRect(50, 90, 160, 19));
        _P3_G->setMaximum(255);
        _P3_G->setOrientation(Qt::Horizontal);
        _P3_B = new QSlider(groupBox_3);
        _P3_B->setObjectName(QStringLiteral("_P3_B"));
        _P3_B->setGeometry(QRect(50, 120, 160, 19));
        _P3_B->setMaximum(255);
        _P3_B->setOrientation(Qt::Horizontal);
        label_23 = new QLabel(groupBox_3);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(250, 60, 111, 21));
        label_23->setAlignment(Qt::AlignCenter);
        _P3_Opacity = new QDoubleSpinBox(groupBox_3);
        _P3_Opacity->setObjectName(QStringLiteral("_P3_Opacity"));
        _P3_Opacity->setGeometry(QRect(340, 60, 81, 22));
        _P3_Opacity->setMaximum(1);
        _P3_Opacity->setSingleStep(0.1);
        _P3_Value = new QSpinBox(groupBox_3);
        _P3_Value->setObjectName(QStringLiteral("_P3_Value"));
        _P3_Value->setGeometry(QRect(140, 20, 61, 22));
        _P3_Value->setMaximum(10000);
        _P3_Value->setSingleStep(50);
        label_24 = new QLabel(groupBox_3);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(260, 100, 81, 21));
        label_24->setAlignment(Qt::AlignCenter);
        _P3_Gradient = new QDoubleSpinBox(groupBox_3);
        _P3_Gradient->setObjectName(QStringLiteral("_P3_Gradient"));
        _P3_Gradient->setGeometry(QRect(340, 100, 81, 22));
        _P3_Gradient->setMaximum(1);
        _P3_Gradient->setSingleStep(0.1);
        R3 = new QLineEdit(groupBox_3);
        R3->setObjectName(QStringLiteral("R3"));
        R3->setGeometry(QRect(220, 60, 41, 16));
        R3->setReadOnly(true);
        G3 = new QLineEdit(groupBox_3);
        G3->setObjectName(QStringLiteral("G3"));
        G3->setGeometry(QRect(220, 90, 41, 16));
        G3->setReadOnly(true);
        B3 = new QLineEdit(groupBox_3);
        B3->setObjectName(QStringLiteral("B3"));
        B3->setGeometry(QRect(220, 120, 41, 16));
        B3->setReadOnly(true);
        groupBox_2 = new QGroupBox(Raycaster);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 270, 531, 151));
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(20, 20, 111, 21));
        label_13->setAlignment(Qt::AlignCenter);
        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(30, 60, 91, 16));
        label_14->setFont(font);
        label_14->setTextFormat(Qt::AutoText);
        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(30, 90, 91, 16));
        label_15->setFont(font);
        label_15->setTextFormat(Qt::AutoText);
        label_16 = new QLabel(groupBox_2);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(30, 120, 91, 16));
        label_16->setFont(font);
        label_16->setTextFormat(Qt::AutoText);
        _P2_R = new QSlider(groupBox_2);
        _P2_R->setObjectName(QStringLiteral("_P2_R"));
        _P2_R->setGeometry(QRect(50, 60, 160, 19));
        _P2_R->setMaximum(255);
        _P2_R->setOrientation(Qt::Horizontal);
        _P2_G = new QSlider(groupBox_2);
        _P2_G->setObjectName(QStringLiteral("_P2_G"));
        _P2_G->setGeometry(QRect(50, 90, 160, 19));
        _P2_G->setMaximum(255);
        _P2_G->setOrientation(Qt::Horizontal);
        _P2_B = new QSlider(groupBox_2);
        _P2_B->setObjectName(QStringLiteral("_P2_B"));
        _P2_B->setGeometry(QRect(50, 120, 160, 19));
        _P2_B->setMaximum(255);
        _P2_B->setOrientation(Qt::Horizontal);
        label_17 = new QLabel(groupBox_2);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(250, 60, 111, 21));
        label_17->setAlignment(Qt::AlignCenter);
        _P2_Opacity = new QDoubleSpinBox(groupBox_2);
        _P2_Opacity->setObjectName(QStringLiteral("_P2_Opacity"));
        _P2_Opacity->setGeometry(QRect(340, 60, 81, 22));
        _P2_Opacity->setMaximum(1);
        _P2_Opacity->setSingleStep(0.1);
        _P2_Value = new QSpinBox(groupBox_2);
        _P2_Value->setObjectName(QStringLiteral("_P2_Value"));
        _P2_Value->setGeometry(QRect(140, 20, 61, 22));
        _P2_Value->setMaximum(10000);
        _P2_Value->setSingleStep(50);
        label_18 = new QLabel(groupBox_2);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(260, 100, 81, 21));
        label_18->setAlignment(Qt::AlignCenter);
        _P2_Gradient = new QDoubleSpinBox(groupBox_2);
        _P2_Gradient->setObjectName(QStringLiteral("_P2_Gradient"));
        _P2_Gradient->setGeometry(QRect(340, 100, 81, 22));
        _P2_Gradient->setMaximum(1);
        _P2_Gradient->setSingleStep(0.1);
        R2 = new QLineEdit(groupBox_2);
        R2->setObjectName(QStringLiteral("R2"));
        R2->setGeometry(QRect(220, 60, 41, 16));
        R2->setReadOnly(true);
        G2 = new QLineEdit(groupBox_2);
        G2->setObjectName(QStringLiteral("G2"));
        G2->setGeometry(QRect(220, 90, 41, 16));
        G2->setReadOnly(true);
        B2 = new QLineEdit(groupBox_2);
        B2->setObjectName(QStringLiteral("B2"));
        B2->setGeometry(QRect(220, 120, 41, 16));
        B2->setReadOnly(true);
        groupBox = new QGroupBox(Raycaster);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 110, 531, 151));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 111, 21));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 60, 91, 16));
        label_2->setFont(font);
        label_2->setTextFormat(Qt::AutoText);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 90, 91, 16));
        label_4->setFont(font);
        label_4->setTextFormat(Qt::AutoText);
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(30, 120, 91, 16));
        label_5->setFont(font);
        label_5->setTextFormat(Qt::AutoText);
        _P1_R = new QSlider(groupBox);
        _P1_R->setObjectName(QStringLiteral("_P1_R"));
        _P1_R->setGeometry(QRect(50, 60, 160, 19));
        _P1_R->setMaximum(255);
        _P1_R->setOrientation(Qt::Horizontal);
        _P1_G = new QSlider(groupBox);
        _P1_G->setObjectName(QStringLiteral("_P1_G"));
        _P1_G->setGeometry(QRect(50, 90, 160, 19));
        _P1_G->setMaximum(255);
        _P1_G->setOrientation(Qt::Horizontal);
        _P1_B = new QSlider(groupBox);
        _P1_B->setObjectName(QStringLiteral("_P1_B"));
        _P1_B->setGeometry(QRect(50, 120, 160, 19));
        _P1_B->setMaximum(255);
        _P1_B->setOrientation(Qt::Horizontal);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(250, 60, 111, 21));
        label_3->setAlignment(Qt::AlignCenter);
        _P1_Opacity = new QDoubleSpinBox(groupBox);
        _P1_Opacity->setObjectName(QStringLiteral("_P1_Opacity"));
        _P1_Opacity->setGeometry(QRect(340, 60, 81, 22));
        _P1_Opacity->setMaximum(1);
        _P1_Opacity->setSingleStep(0.1);
        _P1_Value = new QSpinBox(groupBox);
        _P1_Value->setObjectName(QStringLiteral("_P1_Value"));
        _P1_Value->setGeometry(QRect(140, 20, 61, 22));
        _P1_Value->setMinimum(-10000);
        _P1_Value->setMaximum(10000);
        _P1_Value->setSingleStep(50);
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(260, 100, 81, 21));
        label_6->setAlignment(Qt::AlignCenter);
        _P1_Gradient = new QDoubleSpinBox(groupBox);
        _P1_Gradient->setObjectName(QStringLiteral("_P1_Gradient"));
        _P1_Gradient->setGeometry(QRect(340, 100, 81, 22));
        _P1_Gradient->setMaximum(1);
        _P1_Gradient->setSingleStep(0.1);
        R1 = new QLineEdit(groupBox);
        R1->setObjectName(QStringLiteral("R1"));
        R1->setGeometry(QRect(220, 60, 41, 16));
        R1->setReadOnly(true);
        G1 = new QLineEdit(groupBox);
        G1->setObjectName(QStringLiteral("G1"));
        G1->setGeometry(QRect(220, 90, 41, 16));
        G1->setReadOnly(true);
        B1 = new QLineEdit(groupBox);
        B1->setObjectName(QStringLiteral("B1"));
        B1->setGeometry(QRect(220, 120, 41, 16));
        B1->setReadOnly(true);
        groupBox_4 = new QGroupBox(Raycaster);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 590, 531, 80));
        label_7 = new QLabel(groupBox_4);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(0, 40, 61, 21));
        QFont font1;
        font1.setPointSize(10);
        label_7->setFont(font1);
        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(170, 40, 51, 21));
        label_8->setFont(font1);
        label_9 = new QLabel(groupBox_4);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(330, 40, 61, 21));
        label_9->setFont(font1);
        _Ambient = new QDoubleSpinBox(groupBox_4);
        _Ambient->setObjectName(QStringLiteral("_Ambient"));
        _Ambient->setGeometry(QRect(60, 40, 81, 22));
        _Ambient->setMaximum(1);
        _Ambient->setSingleStep(0.1);
        _Ambient->setValue(0.4);
        _Diffuse = new QDoubleSpinBox(groupBox_4);
        _Diffuse->setObjectName(QStringLiteral("_Diffuse"));
        _Diffuse->setGeometry(QRect(220, 40, 81, 22));
        _Diffuse->setMaximum(1);
        _Diffuse->setSingleStep(0.1);
        _Diffuse->setValue(0.6);
        _Specular = new QDoubleSpinBox(groupBox_4);
        _Specular->setObjectName(QStringLiteral("_Specular"));
        _Specular->setGeometry(QRect(390, 40, 81, 22));
        _Specular->setMaximum(1);
        _Specular->setSingleStep(0.1);
        _Specular->setValue(0.2);
        groupBox_5 = new QGroupBox(Raycaster);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(10, 10, 531, 80));
        _blendMode_addictive = new QRadioButton(groupBox_5);
        _blendMode_addictive->setObjectName(QStringLiteral("_blendMode_addictive"));
        _blendMode_addictive->setGeometry(QRect(20, 30, 101, 31));
        _blendMode_addictive->setChecked(true);
        _blendMode_composite = new QRadioButton(groupBox_5);
        _blendMode_composite->setObjectName(QStringLiteral("_blendMode_composite"));
        _blendMode_composite->setGeometry(QRect(110, 30, 101, 31));
        _blendMode_maxip = new QRadioButton(groupBox_5);
        _blendMode_maxip->setObjectName(QStringLiteral("_blendMode_maxip"));
        _blendMode_maxip->setGeometry(QRect(230, 30, 121, 31));
        _blendMode_minip = new QRadioButton(groupBox_5);
        _blendMode_minip->setObjectName(QStringLiteral("_blendMode_minip"));
        _blendMode_minip->setGeometry(QRect(370, 30, 131, 31));

        retranslateUi(Raycaster);
        QObject::connect(buttonBox, SIGNAL(accepted()), Raycaster, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Raycaster, SLOT(reject()));

        QMetaObject::connectSlotsByName(Raycaster);
    } // setupUi

    void retranslateUi(QDialog *Raycaster)
    {
        Raycaster->setWindowTitle(QApplication::translate("Raycaster", "Ray Casting Settings", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("Raycaster", "Point 3", Q_NULLPTR));
        label_19->setText(QApplication::translate("Raycaster", "Control Point Value :", Q_NULLPTR));
        label_20->setText(QApplication::translate("Raycaster", "R", Q_NULLPTR));
        label_21->setText(QApplication::translate("Raycaster", "G", Q_NULLPTR));
        label_22->setText(QApplication::translate("Raycaster", "B", Q_NULLPTR));
        label_23->setText(QApplication::translate("Raycaster", "Opacity :", Q_NULLPTR));
        label_24->setText(QApplication::translate("Raycaster", "Gradient :", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("Raycaster", "Point 2", Q_NULLPTR));
        label_13->setText(QApplication::translate("Raycaster", "Control Point Value :", Q_NULLPTR));
        label_14->setText(QApplication::translate("Raycaster", "R", Q_NULLPTR));
        label_15->setText(QApplication::translate("Raycaster", "G", Q_NULLPTR));
        label_16->setText(QApplication::translate("Raycaster", "B", Q_NULLPTR));
        label_17->setText(QApplication::translate("Raycaster", "Opacity :", Q_NULLPTR));
        label_18->setText(QApplication::translate("Raycaster", "Gradient :", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Raycaster", "Point 1", Q_NULLPTR));
        label->setText(QApplication::translate("Raycaster", "Control Point Value :", Q_NULLPTR));
        label_2->setText(QApplication::translate("Raycaster", "R", Q_NULLPTR));
        label_4->setText(QApplication::translate("Raycaster", "G", Q_NULLPTR));
        label_5->setText(QApplication::translate("Raycaster", "B", Q_NULLPTR));
        label_3->setText(QApplication::translate("Raycaster", "Opacity :", Q_NULLPTR));
        label_6->setText(QApplication::translate("Raycaster", "Gradient :", Q_NULLPTR));
        R1->setText(QApplication::translate("Raycaster", "0", Q_NULLPTR));
        G1->setText(QApplication::translate("Raycaster", "0", Q_NULLPTR));
        B1->setText(QApplication::translate("Raycaster", "0", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("Raycaster", "Light Settings", Q_NULLPTR));
        label_7->setText(QApplication::translate("Raycaster", "Ambient :", Q_NULLPTR));
        label_8->setText(QApplication::translate("Raycaster", "Diffuse:", Q_NULLPTR));
        label_9->setText(QApplication::translate("Raycaster", "Specular:", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("Raycaster", "Blend Mode", Q_NULLPTR));
        _blendMode_addictive->setText(QApplication::translate("Raycaster", "Addictive", Q_NULLPTR));
        _blendMode_composite->setText(QApplication::translate("Raycaster", "Composite", Q_NULLPTR));
        _blendMode_maxip->setText(QApplication::translate("Raycaster", "Maximum Intensity", Q_NULLPTR));
        _blendMode_minip->setText(QApplication::translate("Raycaster", "Minimum Intensity", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Raycaster: public Ui_Raycaster {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RAYCASTER_H
