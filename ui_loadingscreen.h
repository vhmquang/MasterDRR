/********************************************************************************
** Form generated from reading UI file 'loadingscreen.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADINGSCREEN_H
#define UI_LOADINGSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_loadingscreen
{
public:
    QLineEdit *lineEdit;

    void setupUi(QDialog *loadingscreen)
    {
        if (loadingscreen->objectName().isEmpty())
            loadingscreen->setObjectName(QStringLiteral("loadingscreen"));
        loadingscreen->setWindowModality(Qt::WindowModal);
        loadingscreen->resize(220, 103);
        QFont font;
        font.setPointSize(11);
        loadingscreen->setFont(font);
        loadingscreen->setModal(true);
        lineEdit = new QLineEdit(loadingscreen);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setEnabled(true);
        lineEdit->setGeometry(QRect(20, 10, 191, 61));
        QFont font1;
        font1.setPointSize(17);
        font1.setBold(true);
        font1.setWeight(75);
        lineEdit->setFont(font1);
        lineEdit->setReadOnly(true);

        retranslateUi(loadingscreen);

        QMetaObject::connectSlotsByName(loadingscreen);
    } // setupUi

    void retranslateUi(QDialog *loadingscreen)
    {
        loadingscreen->setWindowTitle(QApplication::translate("loadingscreen", "Loading", Q_NULLPTR));
        lineEdit->setText(QApplication::translate("loadingscreen", "Loading Data", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class loadingscreen: public Ui_loadingscreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADINGSCREEN_H
