/********************************************************************************
** Form generated from reading UI file 'ballpivot.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BALLPIVOT_H
#define UI_BALLPIVOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_ballpivot
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QDoubleSpinBox *radius;
    QDoubleSpinBox *cluster;
    QDoubleSpinBox *angle;

    void setupUi(QDialog *ballpivot)
    {
        if (ballpivot->objectName().isEmpty())
            ballpivot->setObjectName(QStringLiteral("ballpivot"));
        ballpivot->resize(339, 160);
        buttonBox = new QDialogButtonBox(ballpivot);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(-90, 110, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(ballpivot);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 181, 16));
        label_2 = new QLabel(ballpivot);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 50, 141, 16));
        label_3 = new QLabel(ballpivot);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 80, 141, 16));
        radius = new QDoubleSpinBox(ballpivot);
        radius->setObjectName(QStringLiteral("radius"));
        radius->setGeometry(QRect(200, 20, 101, 22));
        cluster = new QDoubleSpinBox(ballpivot);
        cluster->setObjectName(QStringLiteral("cluster"));
        cluster->setGeometry(QRect(200, 50, 101, 22));
        cluster->setMaximum(100);
        cluster->setValue(20);
        angle = new QDoubleSpinBox(ballpivot);
        angle->setObjectName(QStringLiteral("angle"));
        angle->setGeometry(QRect(200, 80, 101, 22));
        angle->setMaximum(360);
        angle->setValue(90);

        retranslateUi(ballpivot);
        QObject::connect(buttonBox, SIGNAL(accepted()), ballpivot, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ballpivot, SLOT(reject()));

        QMetaObject::connectSlotsByName(ballpivot);
    } // setupUi

    void retranslateUi(QDialog *ballpivot)
    {
        ballpivot->setWindowTitle(QApplication::translate("ballpivot", "Ball Pivot Settings", Q_NULLPTR));
        label->setText(QApplication::translate("ballpivot", "Ball radius ( 0 for auto guess)", Q_NULLPTR));
        label_2->setText(QApplication::translate("ballpivot", "Clustering radius (%)", Q_NULLPTR));
        label_3->setText(QApplication::translate("ballpivot", "Angle threshold (degree)", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ballpivot: public Ui_ballpivot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BALLPIVOT_H
