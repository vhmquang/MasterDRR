/********************************************************************************
** Form generated from reading UI file 'marchingcubes.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MARCHINGCUBES_H
#define UI_MARCHINGCUBES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_marchingcubes
{
public:
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QSpinBox *_Isovalue1;
    QSpinBox *_Isovalue2;
    QSpinBox *_Isovalue3;
    QSpinBox *_Isovalue4;
    QRadioButton *_UseValue;
    QRadioButton *_UseRange;
    QGroupBox *groupBox_2;
    QLabel *label_2;
    QLabel *label_3;
    QSpinBox *_MinimumValue;
    QSpinBox *_MaximumValue;
    QLabel *label;
    QSpinBox *_NumberOfContour;
    QGroupBox *groupBox_3;
    QCheckBox *_NormalOption;
    QCheckBox *_GradientOption;
    QCheckBox *_ColorOption;

    void setupUi(QDialog *marchingcubes)
    {
        if (marchingcubes->objectName().isEmpty())
            marchingcubes->setObjectName(QStringLiteral("marchingcubes"));
        marchingcubes->resize(537, 400);
        marchingcubes->setModal(true);
        buttonBox = new QDialogButtonBox(marchingcubes);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(180, 330, 161, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);
        groupBox = new QGroupBox(marchingcubes);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 30, 221, 151));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 20, 71, 21));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 50, 71, 21));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 80, 71, 21));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 110, 71, 21));
        _Isovalue1 = new QSpinBox(groupBox);
        _Isovalue1->setObjectName(QStringLiteral("_Isovalue1"));
        _Isovalue1->setGeometry(QRect(100, 20, 71, 22));
        _Isovalue1->setMaximum(4000);
        _Isovalue2 = new QSpinBox(groupBox);
        _Isovalue2->setObjectName(QStringLiteral("_Isovalue2"));
        _Isovalue2->setGeometry(QRect(100, 50, 71, 22));
        _Isovalue2->setMaximum(4000);
        _Isovalue3 = new QSpinBox(groupBox);
        _Isovalue3->setObjectName(QStringLiteral("_Isovalue3"));
        _Isovalue3->setGeometry(QRect(100, 80, 71, 22));
        _Isovalue3->setMaximum(4000);
        _Isovalue4 = new QSpinBox(groupBox);
        _Isovalue4->setObjectName(QStringLiteral("_Isovalue4"));
        _Isovalue4->setGeometry(QRect(100, 110, 71, 22));
        _Isovalue4->setMaximum(4000);
        _UseValue = new QRadioButton(marchingcubes);
        _UseValue->setObjectName(QStringLiteral("_UseValue"));
        _UseValue->setGeometry(QRect(20, 10, 181, 21));
        _UseValue->setChecked(true);
        _UseRange = new QRadioButton(marchingcubes);
        _UseRange->setObjectName(QStringLiteral("_UseRange"));
        _UseRange->setGeometry(QRect(290, 10, 151, 21));
        groupBox_2 = new QGroupBox(marchingcubes);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(280, 30, 231, 151));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 30, 111, 21));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 70, 111, 21));
        _MinimumValue = new QSpinBox(groupBox_2);
        _MinimumValue->setObjectName(QStringLiteral("_MinimumValue"));
        _MinimumValue->setGeometry(QRect(140, 30, 71, 22));
        _MinimumValue->setMaximum(4000);
        _MaximumValue = new QSpinBox(groupBox_2);
        _MaximumValue->setObjectName(QStringLiteral("_MaximumValue"));
        _MaximumValue->setGeometry(QRect(140, 70, 71, 22));
        _MaximumValue->setMaximum(4000);
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 110, 111, 21));
        _NumberOfContour = new QSpinBox(groupBox_2);
        _NumberOfContour->setObjectName(QStringLiteral("_NumberOfContour"));
        _NumberOfContour->setGeometry(QRect(140, 110, 71, 22));
        _NumberOfContour->setMinimum(1);
        _NumberOfContour->setMaximum(10);
        groupBox_3 = new QGroupBox(marchingcubes);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 210, 491, 101));
        _NormalOption = new QCheckBox(groupBox_3);
        _NormalOption->setObjectName(QStringLiteral("_NormalOption"));
        _NormalOption->setGeometry(QRect(20, 30, 181, 21));
        _NormalOption->setChecked(true);
        _GradientOption = new QCheckBox(groupBox_3);
        _GradientOption->setObjectName(QStringLiteral("_GradientOption"));
        _GradientOption->setGeometry(QRect(20, 70, 211, 21));
        _GradientOption->setChecked(true);
        _ColorOption = new QCheckBox(groupBox_3);
        _ColorOption->setObjectName(QStringLiteral("_ColorOption"));
        _ColorOption->setGeometry(QRect(230, 30, 181, 21));
        _ColorOption->setChecked(true);

        retranslateUi(marchingcubes);
        QObject::connect(buttonBox, SIGNAL(accepted()), marchingcubes, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), marchingcubes, SLOT(reject()));

        QMetaObject::connectSlotsByName(marchingcubes);
    } // setupUi

    void retranslateUi(QDialog *marchingcubes)
    {
        marchingcubes->setWindowTitle(QApplication::translate("marchingcubes", "Marching Cubes Settings", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("marchingcubes", "Value input", Q_NULLPTR));
        label_4->setText(QApplication::translate("marchingcubes", "Iso-value 1", Q_NULLPTR));
        label_5->setText(QApplication::translate("marchingcubes", "Iso-value 2", Q_NULLPTR));
        label_6->setText(QApplication::translate("marchingcubes", "Iso-value 3", Q_NULLPTR));
        label_7->setText(QApplication::translate("marchingcubes", "Iso-value 4", Q_NULLPTR));
        _UseValue->setText(QApplication::translate("marchingcubes", "Use Specific iso-value", Q_NULLPTR));
        _UseRange->setText(QApplication::translate("marchingcubes", "Use Range", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("marchingcubes", "Range input", Q_NULLPTR));
        label_2->setText(QApplication::translate("marchingcubes", "Minimum Iso-value:", Q_NULLPTR));
        label_3->setText(QApplication::translate("marchingcubes", "Maximum Iso-value:", Q_NULLPTR));
        label->setText(QApplication::translate("marchingcubes", "Number of Iso-values:", Q_NULLPTR));
        _NumberOfContour->setSuffix(QString());
        groupBox_3->setTitle(QApplication::translate("marchingcubes", "Other Settings", Q_NULLPTR));
        _NormalOption->setText(QApplication::translate("marchingcubes", "Use Normal", Q_NULLPTR));
        _GradientOption->setText(QApplication::translate("marchingcubes", "Use Gradient", Q_NULLPTR));
        _ColorOption->setText(QApplication::translate("marchingcubes", "Use Automatic Color", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class marchingcubes: public Ui_marchingcubes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MARCHINGCUBES_H
