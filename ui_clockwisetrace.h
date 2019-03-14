/********************************************************************************
** Form generated from reading UI file 'clockwisetrace.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLOCKWISETRACE_H
#define UI_CLOCKWISETRACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_ClockWiseTrace
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QSpinBox *maxDistance;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QSpinBox *retryTimes;
    QSpinBox *requiredPoints;
    QSpinBox *lower;
    QSpinBox *upper;
    QSpinBox *steps;

    void setupUi(QDialog *ClockWiseTrace)
    {
        if (ClockWiseTrace->objectName().isEmpty())
            ClockWiseTrace->setObjectName(QStringLiteral("ClockWiseTrace"));
        ClockWiseTrace->resize(337, 247);
        buttonBox = new QDialogButtonBox(ClockWiseTrace);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(-90, 200, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(ClockWiseTrace);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 111, 21));
        maxDistance = new QSpinBox(ClockWiseTrace);
        maxDistance->setObjectName(QStringLiteral("maxDistance"));
        maxDistance->setGeometry(QRect(140, 10, 111, 22));
        maxDistance->setMaximum(10);
        maxDistance->setValue(3);
        label_2 = new QLabel(ClockWiseTrace);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 40, 111, 21));
        label_3 = new QLabel(ClockWiseTrace);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 70, 111, 21));
        label_4 = new QLabel(ClockWiseTrace);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 100, 111, 21));
        label_5 = new QLabel(ClockWiseTrace);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 130, 111, 21));
        label_6 = new QLabel(ClockWiseTrace);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 160, 111, 21));
        retryTimes = new QSpinBox(ClockWiseTrace);
        retryTimes->setObjectName(QStringLiteral("retryTimes"));
        retryTimes->setGeometry(QRect(140, 40, 111, 22));
        retryTimes->setValue(3);
        requiredPoints = new QSpinBox(ClockWiseTrace);
        requiredPoints->setObjectName(QStringLiteral("requiredPoints"));
        requiredPoints->setGeometry(QRect(140, 70, 111, 22));
        requiredPoints->setValue(35);
        lower = new QSpinBox(ClockWiseTrace);
        lower->setObjectName(QStringLiteral("lower"));
        lower->setGeometry(QRect(140, 100, 111, 22));
        lower->setMinimum(-10000);
        lower->setMaximum(10000);
        lower->setValue(250);
        upper = new QSpinBox(ClockWiseTrace);
        upper->setObjectName(QStringLiteral("upper"));
        upper->setGeometry(QRect(140, 130, 111, 22));
        upper->setMinimum(-10000);
        upper->setMaximum(10000);
        upper->setValue(2500);
        steps = new QSpinBox(ClockWiseTrace);
        steps->setObjectName(QStringLiteral("steps"));
        steps->setGeometry(QRect(140, 160, 111, 22));
        steps->setMaximum(10000);
        steps->setValue(200);

        retranslateUi(ClockWiseTrace);
        QObject::connect(buttonBox, SIGNAL(accepted()), ClockWiseTrace, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ClockWiseTrace, SLOT(reject()));

        QMetaObject::connectSlotsByName(ClockWiseTrace);
    } // setupUi

    void retranslateUi(QDialog *ClockWiseTrace)
    {
        ClockWiseTrace->setWindowTitle(QApplication::translate("ClockWiseTrace", "ClockWiseTrace Settings", Q_NULLPTR));
        label->setText(QApplication::translate("ClockWiseTrace", "Max distance", Q_NULLPTR));
        label_2->setText(QApplication::translate("ClockWiseTrace", "Retry times", Q_NULLPTR));
        label_3->setText(QApplication::translate("ClockWiseTrace", "Required points", Q_NULLPTR));
        label_4->setText(QApplication::translate("ClockWiseTrace", "Lower bound", Q_NULLPTR));
        label_5->setText(QApplication::translate("ClockWiseTrace", "Upper bound", Q_NULLPTR));
        label_6->setText(QApplication::translate("ClockWiseTrace", "Step bound", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ClockWiseTrace: public Ui_ClockWiseTrace {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLOCKWISETRACE_H
