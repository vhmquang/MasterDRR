/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen_DICOM_Image;
    QAction *actionOpen_DICOM_Folder;
    QAction *actionHelp;
    QAction *actionExit;
    QAction *actionMarching_Cubes_Settings;
    QAction *actionRay_Casting_Settings;
    QAction *actionSave;
    QAction *actionTexture_Mapper;
    QAction *actionManual;
    QAction *actionAbout_3DF2D;
    QAction *actionContact_Author;
    QAction *actionSave_as_xyz_file;
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QTabWidget *tabWidget;
    QWidget *Image2D;
    QGridLayout *gridLayout_2;
    QVTKWidget *_2D_Image_Renderer;
    QGroupBox *_2D_InformationBox;
    QGridLayout *gridLayout;
    QLineEdit *_2D_Information_Location;
    QLineEdit *_2D_Information_Location_out;
    QLineEdit *_2D_Information_Width;
    QLineEdit *_2D_Information_Width_out;
    QLineEdit *_2D_Information_Height;
    QLineEdit *_2D_Information_Height_out;
    QLineEdit *_2D_Information_Name;
    QLineEdit *_2D_Information_Name_out;
    QLineEdit *_2D_Information_ID;
    QLineEdit *_2D_Information_ID_out;
    QLineEdit *_2D_Information_DesName;
    QLineEdit *_2D_Information_DesName_out;
    QPushButton *_2D_Image_ResetCamera;
    QPushButton *_2D_Image_AutoPlay;
    QPlainTextEdit *_2D_Text;
    QSlider *_2D_Image_Slicer;
    QSpinBox *_2D_FPS;
    QWidget *Image3D;
    QGridLayout *gridLayout_5;
    QToolButton *_3D_Model_Left;
    QToolButton *_3D_Model_Up;
    QToolButton *_3D_Model_Right;
    QPlainTextEdit *_3D_Label_Rotate;
    QSpinBox *_3D_InformationBox_RotateValue;
    QPushButton *_3D_Model_Generate;
    QToolButton *_3D_Model_Down;
    QPlainTextEdit *_3D_Label_Zoom;
    QSpinBox *_3D_InformationBox_ZoomValue;
    QPushButton *_3D_Model_ZoomIn;
    QPushButton *_3D_Model_ZoomOut;
    QVTKWidget *_3D_Model_Renderer;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuAlgorithm;
    QMenu *menuHelp;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1013, 587);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        actionOpen_DICOM_Image = new QAction(MainWindow);
        actionOpen_DICOM_Image->setObjectName(QStringLiteral("actionOpen_DICOM_Image"));
        actionOpen_DICOM_Image->setShortcutContext(Qt::ApplicationShortcut);
        actionOpen_DICOM_Folder = new QAction(MainWindow);
        actionOpen_DICOM_Folder->setObjectName(QStringLiteral("actionOpen_DICOM_Folder"));
        actionOpen_DICOM_Folder->setCheckable(false);
        actionOpen_DICOM_Folder->setShortcutContext(Qt::ApplicationShortcut);
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        actionHelp->setShortcutContext(Qt::ApplicationShortcut);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionExit->setShortcutContext(Qt::ApplicationShortcut);
        actionMarching_Cubes_Settings = new QAction(MainWindow);
        actionMarching_Cubes_Settings->setObjectName(QStringLiteral("actionMarching_Cubes_Settings"));
        actionRay_Casting_Settings = new QAction(MainWindow);
        actionRay_Casting_Settings->setObjectName(QStringLiteral("actionRay_Casting_Settings"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionTexture_Mapper = new QAction(MainWindow);
        actionTexture_Mapper->setObjectName(QStringLiteral("actionTexture_Mapper"));
        actionManual = new QAction(MainWindow);
        actionManual->setObjectName(QStringLiteral("actionManual"));
        actionAbout_3DF2D = new QAction(MainWindow);
        actionAbout_3DF2D->setObjectName(QStringLiteral("actionAbout_3DF2D"));
        actionContact_Author = new QAction(MainWindow);
        actionContact_Author->setObjectName(QStringLiteral("actionContact_Author"));
        actionSave_as_xyz_file = new QAction(MainWindow);
        actionSave_as_xyz_file->setObjectName(QStringLiteral("actionSave_as_xyz_file"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(5);
        sizePolicy1.setVerticalStretch(5);
        sizePolicy1.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy1);
        centralWidget->setAutoFillBackground(true);
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy2);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setTabBarAutoHide(false);
        Image2D = new QWidget();
        Image2D->setObjectName(QStringLiteral("Image2D"));
        Image2D->setEnabled(true);
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(5);
        sizePolicy3.setVerticalStretch(5);
        sizePolicy3.setHeightForWidth(Image2D->sizePolicy().hasHeightForWidth());
        Image2D->setSizePolicy(sizePolicy3);
        gridLayout_2 = new QGridLayout(Image2D);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        _2D_Image_Renderer = new QVTKWidget(Image2D);
        _2D_Image_Renderer->setObjectName(QStringLiteral("_2D_Image_Renderer"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(_2D_Image_Renderer->sizePolicy().hasHeightForWidth());
        _2D_Image_Renderer->setSizePolicy(sizePolicy4);
        _2D_Image_Renderer->setMinimumSize(QSize(531, 401));
        _2D_Image_Renderer->setCursor(QCursor(Qt::CrossCursor));
        _2D_Image_Renderer->setMouseTracking(true);
        _2D_Image_Renderer->setAutoFillBackground(false);

        gridLayout_2->addWidget(_2D_Image_Renderer, 0, 0, 1, 1);

        _2D_InformationBox = new QGroupBox(Image2D);
        _2D_InformationBox->setObjectName(QStringLiteral("_2D_InformationBox"));
        sizePolicy2.setHeightForWidth(_2D_InformationBox->sizePolicy().hasHeightForWidth());
        _2D_InformationBox->setSizePolicy(sizePolicy2);
        _2D_InformationBox->setMinimumSize(QSize(301, 401));
        QFont font;
        font.setPointSize(12);
        _2D_InformationBox->setFont(font);
        _2D_InformationBox->setFocusPolicy(Qt::NoFocus);
        _2D_InformationBox->setAutoFillBackground(false);
        gridLayout = new QGridLayout(_2D_InformationBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        _2D_Information_Location = new QLineEdit(_2D_InformationBox);
        _2D_Information_Location->setObjectName(QStringLiteral("_2D_Information_Location"));
        sizePolicy2.setHeightForWidth(_2D_Information_Location->sizePolicy().hasHeightForWidth());
        _2D_Information_Location->setSizePolicy(sizePolicy2);
        _2D_Information_Location->setMaximumSize(QSize(16777215, 55));
        _2D_Information_Location->setFrame(false);
        _2D_Information_Location->setAlignment(Qt::AlignCenter);
        _2D_Information_Location->setReadOnly(true);

        gridLayout->addWidget(_2D_Information_Location, 0, 0, 1, 1);

        _2D_Information_Location_out = new QLineEdit(_2D_InformationBox);
        _2D_Information_Location_out->setObjectName(QStringLiteral("_2D_Information_Location_out"));
        sizePolicy2.setHeightForWidth(_2D_Information_Location_out->sizePolicy().hasHeightForWidth());
        _2D_Information_Location_out->setSizePolicy(sizePolicy2);
        _2D_Information_Location_out->setMaximumSize(QSize(16777215, 55));
        _2D_Information_Location_out->setReadOnly(true);
        _2D_Information_Location_out->setClearButtonEnabled(false);

        gridLayout->addWidget(_2D_Information_Location_out, 0, 1, 1, 1);

        _2D_Information_Width = new QLineEdit(_2D_InformationBox);
        _2D_Information_Width->setObjectName(QStringLiteral("_2D_Information_Width"));
        sizePolicy2.setHeightForWidth(_2D_Information_Width->sizePolicy().hasHeightForWidth());
        _2D_Information_Width->setSizePolicy(sizePolicy2);
        _2D_Information_Width->setMaximumSize(QSize(16777215, 56));
        _2D_Information_Width->setFrame(false);
        _2D_Information_Width->setAlignment(Qt::AlignCenter);
        _2D_Information_Width->setReadOnly(true);

        gridLayout->addWidget(_2D_Information_Width, 1, 0, 1, 1);

        _2D_Information_Width_out = new QLineEdit(_2D_InformationBox);
        _2D_Information_Width_out->setObjectName(QStringLiteral("_2D_Information_Width_out"));
        sizePolicy2.setHeightForWidth(_2D_Information_Width_out->sizePolicy().hasHeightForWidth());
        _2D_Information_Width_out->setSizePolicy(sizePolicy2);
        _2D_Information_Width_out->setMaximumSize(QSize(16777215, 56));
        _2D_Information_Width_out->setReadOnly(true);

        gridLayout->addWidget(_2D_Information_Width_out, 1, 1, 1, 1);

        _2D_Information_Height = new QLineEdit(_2D_InformationBox);
        _2D_Information_Height->setObjectName(QStringLiteral("_2D_Information_Height"));
        sizePolicy2.setHeightForWidth(_2D_Information_Height->sizePolicy().hasHeightForWidth());
        _2D_Information_Height->setSizePolicy(sizePolicy2);
        _2D_Information_Height->setMaximumSize(QSize(16777215, 55));
        _2D_Information_Height->setFrame(false);
        _2D_Information_Height->setAlignment(Qt::AlignCenter);
        _2D_Information_Height->setReadOnly(true);

        gridLayout->addWidget(_2D_Information_Height, 2, 0, 1, 1);

        _2D_Information_Height_out = new QLineEdit(_2D_InformationBox);
        _2D_Information_Height_out->setObjectName(QStringLiteral("_2D_Information_Height_out"));
        sizePolicy2.setHeightForWidth(_2D_Information_Height_out->sizePolicy().hasHeightForWidth());
        _2D_Information_Height_out->setSizePolicy(sizePolicy2);
        _2D_Information_Height_out->setMaximumSize(QSize(16777215, 55));
        _2D_Information_Height_out->setReadOnly(true);

        gridLayout->addWidget(_2D_Information_Height_out, 2, 1, 1, 1);

        _2D_Information_Name = new QLineEdit(_2D_InformationBox);
        _2D_Information_Name->setObjectName(QStringLiteral("_2D_Information_Name"));
        sizePolicy2.setHeightForWidth(_2D_Information_Name->sizePolicy().hasHeightForWidth());
        _2D_Information_Name->setSizePolicy(sizePolicy2);
        _2D_Information_Name->setMaximumSize(QSize(16777215, 55));
        _2D_Information_Name->setFrame(false);
        _2D_Information_Name->setAlignment(Qt::AlignCenter);
        _2D_Information_Name->setReadOnly(true);

        gridLayout->addWidget(_2D_Information_Name, 3, 0, 1, 1);

        _2D_Information_Name_out = new QLineEdit(_2D_InformationBox);
        _2D_Information_Name_out->setObjectName(QStringLiteral("_2D_Information_Name_out"));
        sizePolicy2.setHeightForWidth(_2D_Information_Name_out->sizePolicy().hasHeightForWidth());
        _2D_Information_Name_out->setSizePolicy(sizePolicy2);
        _2D_Information_Name_out->setMaximumSize(QSize(16777215, 55));
        _2D_Information_Name_out->setReadOnly(true);

        gridLayout->addWidget(_2D_Information_Name_out, 3, 1, 1, 1);

        _2D_Information_ID = new QLineEdit(_2D_InformationBox);
        _2D_Information_ID->setObjectName(QStringLiteral("_2D_Information_ID"));
        sizePolicy2.setHeightForWidth(_2D_Information_ID->sizePolicy().hasHeightForWidth());
        _2D_Information_ID->setSizePolicy(sizePolicy2);
        _2D_Information_ID->setMaximumSize(QSize(16777215, 56));
        _2D_Information_ID->setFrame(false);
        _2D_Information_ID->setAlignment(Qt::AlignCenter);
        _2D_Information_ID->setReadOnly(true);

        gridLayout->addWidget(_2D_Information_ID, 4, 0, 1, 1);

        _2D_Information_ID_out = new QLineEdit(_2D_InformationBox);
        _2D_Information_ID_out->setObjectName(QStringLiteral("_2D_Information_ID_out"));
        sizePolicy2.setHeightForWidth(_2D_Information_ID_out->sizePolicy().hasHeightForWidth());
        _2D_Information_ID_out->setSizePolicy(sizePolicy2);
        _2D_Information_ID_out->setMaximumSize(QSize(16777215, 56));
        _2D_Information_ID_out->setReadOnly(true);

        gridLayout->addWidget(_2D_Information_ID_out, 4, 1, 1, 1);

        _2D_Information_DesName = new QLineEdit(_2D_InformationBox);
        _2D_Information_DesName->setObjectName(QStringLiteral("_2D_Information_DesName"));
        sizePolicy2.setHeightForWidth(_2D_Information_DesName->sizePolicy().hasHeightForWidth());
        _2D_Information_DesName->setSizePolicy(sizePolicy2);
        _2D_Information_DesName->setMaximumSize(QSize(16777215, 55));
        _2D_Information_DesName->setFrame(false);
        _2D_Information_DesName->setAlignment(Qt::AlignCenter);
        _2D_Information_DesName->setReadOnly(true);

        gridLayout->addWidget(_2D_Information_DesName, 5, 0, 1, 1);

        _2D_Information_DesName_out = new QLineEdit(_2D_InformationBox);
        _2D_Information_DesName_out->setObjectName(QStringLiteral("_2D_Information_DesName_out"));
        sizePolicy2.setHeightForWidth(_2D_Information_DesName_out->sizePolicy().hasHeightForWidth());
        _2D_Information_DesName_out->setSizePolicy(sizePolicy2);
        _2D_Information_DesName_out->setMaximumSize(QSize(16777215, 55));
        _2D_Information_DesName_out->setReadOnly(true);

        gridLayout->addWidget(_2D_Information_DesName_out, 5, 1, 1, 1);


        gridLayout_2->addWidget(_2D_InformationBox, 0, 1, 1, 3);

        _2D_Image_ResetCamera = new QPushButton(Image2D);
        _2D_Image_ResetCamera->setObjectName(QStringLiteral("_2D_Image_ResetCamera"));
        sizePolicy2.setHeightForWidth(_2D_Image_ResetCamera->sizePolicy().hasHeightForWidth());
        _2D_Image_ResetCamera->setSizePolicy(sizePolicy2);
        _2D_Image_ResetCamera->setMinimumSize(QSize(211, 41));
        _2D_Image_ResetCamera->setMaximumSize(QSize(16777215, 60));
        _2D_Image_ResetCamera->setAutoFillBackground(false);

        gridLayout_2->addWidget(_2D_Image_ResetCamera, 1, 1, 2, 1);

        _2D_Image_AutoPlay = new QPushButton(Image2D);
        _2D_Image_AutoPlay->setObjectName(QStringLiteral("_2D_Image_AutoPlay"));
        sizePolicy2.setHeightForWidth(_2D_Image_AutoPlay->sizePolicy().hasHeightForWidth());
        _2D_Image_AutoPlay->setSizePolicy(sizePolicy2);
        _2D_Image_AutoPlay->setMinimumSize(QSize(131, 41));
        _2D_Image_AutoPlay->setMaximumSize(QSize(16777215, 60));
        _2D_Image_AutoPlay->setAutoFillBackground(false);

        gridLayout_2->addWidget(_2D_Image_AutoPlay, 1, 2, 2, 1);

        _2D_Text = new QPlainTextEdit(Image2D);
        _2D_Text->setObjectName(QStringLiteral("_2D_Text"));
        _2D_Text->setEnabled(true);
        sizePolicy2.setHeightForWidth(_2D_Text->sizePolicy().hasHeightForWidth());
        _2D_Text->setSizePolicy(sizePolicy2);
        _2D_Text->setMaximumSize(QSize(88, 21));
        _2D_Text->setFocusPolicy(Qt::WheelFocus);
        _2D_Text->setAcceptDrops(true);
        _2D_Text->setAutoFillBackground(false);
        _2D_Text->setFrameShape(QFrame::NoFrame);
        _2D_Text->setFrameShadow(QFrame::Raised);
        _2D_Text->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        _2D_Text->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        _2D_Text->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        _2D_Text->setLineWrapMode(QPlainTextEdit::NoWrap);
        _2D_Text->setReadOnly(true);
        _2D_Text->setBackgroundVisible(false);
        _2D_Text->setCenterOnScroll(false);

        gridLayout_2->addWidget(_2D_Text, 1, 3, 1, 1);

        _2D_Image_Slicer = new QSlider(Image2D);
        _2D_Image_Slicer->setObjectName(QStringLiteral("_2D_Image_Slicer"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(_2D_Image_Slicer->sizePolicy().hasHeightForWidth());
        _2D_Image_Slicer->setSizePolicy(sizePolicy5);
        _2D_Image_Slicer->setMinimumSize(QSize(301, 20));
        _2D_Image_Slicer->setMaximumSize(QSize(16777215, 20));
        _2D_Image_Slicer->setAutoFillBackground(false);
        _2D_Image_Slicer->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(_2D_Image_Slicer, 2, 0, 1, 1);

        _2D_FPS = new QSpinBox(Image2D);
        _2D_FPS->setObjectName(QStringLiteral("_2D_FPS"));
        sizePolicy2.setHeightForWidth(_2D_FPS->sizePolicy().hasHeightForWidth());
        _2D_FPS->setSizePolicy(sizePolicy2);
        _2D_FPS->setMinimumSize(QSize(51, 31));
        _2D_FPS->setMaximumSize(QSize(51, 31));
        _2D_FPS->setAutoFillBackground(false);
        _2D_FPS->setMinimum(10);
        _2D_FPS->setMaximum(60);
        _2D_FPS->setValue(30);

        gridLayout_2->addWidget(_2D_FPS, 2, 3, 1, 1);

        tabWidget->addTab(Image2D, QString());
        Image3D = new QWidget();
        Image3D->setObjectName(QStringLiteral("Image3D"));
        sizePolicy.setHeightForWidth(Image3D->sizePolicy().hasHeightForWidth());
        Image3D->setSizePolicy(sizePolicy);
        gridLayout_5 = new QGridLayout(Image3D);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        _3D_Model_Left = new QToolButton(Image3D);
        _3D_Model_Left->setObjectName(QStringLiteral("_3D_Model_Left"));
        sizePolicy2.setHeightForWidth(_3D_Model_Left->sizePolicy().hasHeightForWidth());
        _3D_Model_Left->setSizePolicy(sizePolicy2);
        _3D_Model_Left->setMinimumSize(QSize(23, 22));
        _3D_Model_Left->setMaximumSize(QSize(16777215, 22));
        _3D_Model_Left->setFocusPolicy(Qt::ClickFocus);
        _3D_Model_Left->setPopupMode(QToolButton::InstantPopup);
        _3D_Model_Left->setArrowType(Qt::LeftArrow);

        gridLayout_5->addWidget(_3D_Model_Left, 1, 0, 3, 1);

        _3D_Model_Up = new QToolButton(Image3D);
        _3D_Model_Up->setObjectName(QStringLiteral("_3D_Model_Up"));
        sizePolicy2.setHeightForWidth(_3D_Model_Up->sizePolicy().hasHeightForWidth());
        _3D_Model_Up->setSizePolicy(sizePolicy2);
        _3D_Model_Up->setMinimumSize(QSize(23, 22));
        _3D_Model_Up->setMaximumSize(QSize(16777215, 22));
        _3D_Model_Up->setFocusPolicy(Qt::ClickFocus);
        _3D_Model_Up->setPopupMode(QToolButton::InstantPopup);
        _3D_Model_Up->setArrowType(Qt::UpArrow);

        gridLayout_5->addWidget(_3D_Model_Up, 1, 1, 2, 1);

        _3D_Model_Right = new QToolButton(Image3D);
        _3D_Model_Right->setObjectName(QStringLiteral("_3D_Model_Right"));
        sizePolicy2.setHeightForWidth(_3D_Model_Right->sizePolicy().hasHeightForWidth());
        _3D_Model_Right->setSizePolicy(sizePolicy2);
        _3D_Model_Right->setMinimumSize(QSize(23, 22));
        _3D_Model_Right->setMaximumSize(QSize(16777215, 22));
        _3D_Model_Right->setFocusPolicy(Qt::ClickFocus);
        _3D_Model_Right->setPopupMode(QToolButton::InstantPopup);
        _3D_Model_Right->setArrowType(Qt::RightArrow);

        gridLayout_5->addWidget(_3D_Model_Right, 1, 2, 3, 1);

        _3D_Label_Rotate = new QPlainTextEdit(Image3D);
        _3D_Label_Rotate->setObjectName(QStringLiteral("_3D_Label_Rotate"));
        sizePolicy2.setHeightForWidth(_3D_Label_Rotate->sizePolicy().hasHeightForWidth());
        _3D_Label_Rotate->setSizePolicy(sizePolicy2);
        _3D_Label_Rotate->setMaximumSize(QSize(101, 21));
        QFont font1;
        font1.setPointSize(8);
        font1.setBold(false);
        font1.setWeight(50);
        _3D_Label_Rotate->setFont(font1);
        _3D_Label_Rotate->setAutoFillBackground(true);
        _3D_Label_Rotate->setFrameShape(QFrame::NoFrame);
        _3D_Label_Rotate->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        _3D_Label_Rotate->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        _3D_Label_Rotate->setLineWrapMode(QPlainTextEdit::NoWrap);
        _3D_Label_Rotate->setReadOnly(true);
        _3D_Label_Rotate->setBackgroundVisible(true);

        gridLayout_5->addWidget(_3D_Label_Rotate, 1, 3, 1, 1);

        _3D_InformationBox_RotateValue = new QSpinBox(Image3D);
        _3D_InformationBox_RotateValue->setObjectName(QStringLiteral("_3D_InformationBox_RotateValue"));
        sizePolicy2.setHeightForWidth(_3D_InformationBox_RotateValue->sizePolicy().hasHeightForWidth());
        _3D_InformationBox_RotateValue->setSizePolicy(sizePolicy2);
        _3D_InformationBox_RotateValue->setMaximumSize(QSize(71, 22));
        _3D_InformationBox_RotateValue->setFont(font1);
        _3D_InformationBox_RotateValue->setFocusPolicy(Qt::ClickFocus);
        _3D_InformationBox_RotateValue->setKeyboardTracking(true);
        _3D_InformationBox_RotateValue->setProperty("showGroupSeparator", QVariant(false));
        _3D_InformationBox_RotateValue->setMinimum(1);
        _3D_InformationBox_RotateValue->setMaximum(180);
        _3D_InformationBox_RotateValue->setSingleStep(1);
        _3D_InformationBox_RotateValue->setValue(5);
        _3D_InformationBox_RotateValue->setDisplayIntegerBase(10);

        gridLayout_5->addWidget(_3D_InformationBox_RotateValue, 1, 4, 2, 1);

        _3D_Model_Generate = new QPushButton(Image3D);
        _3D_Model_Generate->setObjectName(QStringLiteral("_3D_Model_Generate"));
        sizePolicy2.setHeightForWidth(_3D_Model_Generate->sizePolicy().hasHeightForWidth());
        _3D_Model_Generate->setSizePolicy(sizePolicy2);
        _3D_Model_Generate->setMinimumSize(QSize(245, 23));
        _3D_Model_Generate->setMaximumSize(QSize(16777215, 23));

        gridLayout_5->addWidget(_3D_Model_Generate, 1, 7, 3, 1);

        _3D_Model_Down = new QToolButton(Image3D);
        _3D_Model_Down->setObjectName(QStringLiteral("_3D_Model_Down"));
        sizePolicy2.setHeightForWidth(_3D_Model_Down->sizePolicy().hasHeightForWidth());
        _3D_Model_Down->setSizePolicy(sizePolicy2);
        _3D_Model_Down->setMinimumSize(QSize(23, 22));
        _3D_Model_Down->setMaximumSize(QSize(16777215, 22));
        _3D_Model_Down->setFocusPolicy(Qt::ClickFocus);
        _3D_Model_Down->setPopupMode(QToolButton::InstantPopup);
        _3D_Model_Down->setArrowType(Qt::DownArrow);

        gridLayout_5->addWidget(_3D_Model_Down, 3, 1, 1, 1);

        _3D_Label_Zoom = new QPlainTextEdit(Image3D);
        _3D_Label_Zoom->setObjectName(QStringLiteral("_3D_Label_Zoom"));
        sizePolicy2.setHeightForWidth(_3D_Label_Zoom->sizePolicy().hasHeightForWidth());
        _3D_Label_Zoom->setSizePolicy(sizePolicy2);
        _3D_Label_Zoom->setMaximumSize(QSize(101, 21));
        _3D_Label_Zoom->setFont(font1);
        _3D_Label_Zoom->setAutoFillBackground(true);
        _3D_Label_Zoom->setFrameShape(QFrame::NoFrame);
        _3D_Label_Zoom->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        _3D_Label_Zoom->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        _3D_Label_Zoom->setLineWrapMode(QPlainTextEdit::NoWrap);
        _3D_Label_Zoom->setReadOnly(true);
        _3D_Label_Zoom->setBackgroundVisible(true);

        gridLayout_5->addWidget(_3D_Label_Zoom, 3, 3, 1, 1);

        _3D_InformationBox_ZoomValue = new QSpinBox(Image3D);
        _3D_InformationBox_ZoomValue->setObjectName(QStringLiteral("_3D_InformationBox_ZoomValue"));
        sizePolicy2.setHeightForWidth(_3D_InformationBox_ZoomValue->sizePolicy().hasHeightForWidth());
        _3D_InformationBox_ZoomValue->setSizePolicy(sizePolicy2);
        _3D_InformationBox_ZoomValue->setMaximumSize(QSize(71, 22));
        _3D_InformationBox_ZoomValue->setFont(font1);
        _3D_InformationBox_ZoomValue->setFocusPolicy(Qt::ClickFocus);
        _3D_InformationBox_ZoomValue->setMinimum(1);
        _3D_InformationBox_ZoomValue->setMaximum(10);
        _3D_InformationBox_ZoomValue->setSingleStep(1);
        _3D_InformationBox_ZoomValue->setValue(1);
        _3D_InformationBox_ZoomValue->setDisplayIntegerBase(10);

        gridLayout_5->addWidget(_3D_InformationBox_ZoomValue, 3, 4, 1, 1);

        _3D_Model_ZoomIn = new QPushButton(Image3D);
        _3D_Model_ZoomIn->setObjectName(QStringLiteral("_3D_Model_ZoomIn"));
        sizePolicy2.setHeightForWidth(_3D_Model_ZoomIn->sizePolicy().hasHeightForWidth());
        _3D_Model_ZoomIn->setSizePolicy(sizePolicy2);
        _3D_Model_ZoomIn->setMaximumSize(QSize(16777215, 23));

        gridLayout_5->addWidget(_3D_Model_ZoomIn, 1, 5, 1, 1);

        _3D_Model_ZoomOut = new QPushButton(Image3D);
        _3D_Model_ZoomOut->setObjectName(QStringLiteral("_3D_Model_ZoomOut"));
        sizePolicy2.setHeightForWidth(_3D_Model_ZoomOut->sizePolicy().hasHeightForWidth());
        _3D_Model_ZoomOut->setSizePolicy(sizePolicy2);
        _3D_Model_ZoomOut->setMaximumSize(QSize(16777215, 23));

        gridLayout_5->addWidget(_3D_Model_ZoomOut, 3, 5, 1, 1);

        _3D_Model_Renderer = new QVTKWidget(Image3D);
        _3D_Model_Renderer->setObjectName(QStringLiteral("_3D_Model_Renderer"));
        sizePolicy4.setHeightForWidth(_3D_Model_Renderer->sizePolicy().hasHeightForWidth());
        _3D_Model_Renderer->setSizePolicy(sizePolicy4);
        _3D_Model_Renderer->setMinimumSize(QSize(621, 421));
        _3D_Model_Renderer->setFocusPolicy(Qt::NoFocus);
        _3D_Model_Renderer->setAutoFillBackground(false);

        gridLayout_5->addWidget(_3D_Model_Renderer, 0, 0, 1, 8);

        tabWidget->addTab(Image3D, QString());

        gridLayout_3->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1013, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuAlgorithm = new QMenu(menuBar);
        menuAlgorithm->setObjectName(QStringLiteral("menuAlgorithm"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuAlgorithm->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpen_DICOM_Image);
        menuFile->addSeparator();
        menuFile->addAction(actionOpen_DICOM_Folder);
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_as_xyz_file);
        menuFile->addSeparator();
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuAlgorithm->addAction(actionMarching_Cubes_Settings);
        menuAlgorithm->addSeparator();
        menuAlgorithm->addAction(actionRay_Casting_Settings);
        menuAlgorithm->addSeparator();
        menuAlgorithm->addAction(actionTexture_Mapper);
        menuHelp->addAction(actionAbout_3DF2D);
        menuHelp->addSeparator();
        menuHelp->addAction(actionContact_Author);

        retranslateUi(MainWindow);
        QObject::connect(actionExit, SIGNAL(triggered()), MainWindow, SLOT(close()));

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "3DF2D - v1.0.0427", Q_NULLPTR));
        actionOpen_DICOM_Image->setText(QApplication::translate("MainWindow", "Open DICOM Image", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionOpen_DICOM_Image->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionOpen_DICOM_Folder->setText(QApplication::translate("MainWindow", "Open DICOM Folder", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionOpen_DICOM_Folder->setShortcut(QApplication::translate("MainWindow", "Ctrl+Alt+O", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionHelp->setText(QApplication::translate("MainWindow", "Help...", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionHelp->setShortcut(QApplication::translate("MainWindow", "Ctrl+H", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionExit->setText(QApplication::translate("MainWindow", "Exit", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionExit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionMarching_Cubes_Settings->setText(QApplication::translate("MainWindow", "Marching Cubes", Q_NULLPTR));
        actionRay_Casting_Settings->setText(QApplication::translate("MainWindow", "Ray Casting", Q_NULLPTR));
        actionSave->setText(QApplication::translate("MainWindow", "Save image", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionTexture_Mapper->setText(QApplication::translate("MainWindow", "Texture-based Rendering", Q_NULLPTR));
        actionManual->setText(QApplication::translate("MainWindow", "Manual", Q_NULLPTR));
        actionAbout_3DF2D->setText(QApplication::translate("MainWindow", "About 3DF2D...", Q_NULLPTR));
        actionContact_Author->setText(QApplication::translate("MainWindow", "Contact Author", Q_NULLPTR));
        actionSave_as_xyz_file->setText(QApplication::translate("MainWindow", "Save as xyz file", Q_NULLPTR));
        _2D_InformationBox->setTitle(QApplication::translate("MainWindow", "DICOM Informations", Q_NULLPTR));
        _2D_Information_Location->setText(QApplication::translate("MainWindow", "Location", Q_NULLPTR));
        _2D_Information_Location_out->setPlaceholderText(QApplication::translate("MainWindow", "     unknow", Q_NULLPTR));
        _2D_Information_Width->setText(QApplication::translate("MainWindow", "Image Width", Q_NULLPTR));
        _2D_Information_Width_out->setPlaceholderText(QApplication::translate("MainWindow", "     unknow", Q_NULLPTR));
        _2D_Information_Height->setText(QApplication::translate("MainWindow", "Image Heigth", Q_NULLPTR));
        _2D_Information_Height_out->setPlaceholderText(QApplication::translate("MainWindow", "     unknow", Q_NULLPTR));
        _2D_Information_Name->setText(QApplication::translate("MainWindow", "Patient Name", Q_NULLPTR));
        _2D_Information_Name_out->setPlaceholderText(QApplication::translate("MainWindow", "     unknow", Q_NULLPTR));
        _2D_Information_ID->setText(QApplication::translate("MainWindow", "Study ID", Q_NULLPTR));
        _2D_Information_ID_out->setPlaceholderText(QApplication::translate("MainWindow", "     unknow", Q_NULLPTR));
        _2D_Information_DesName->setText(QApplication::translate("MainWindow", "File Extension ", Q_NULLPTR));
        _2D_Information_DesName_out->setPlaceholderText(QApplication::translate("MainWindow", "     unknow", Q_NULLPTR));
        _2D_Image_ResetCamera->setText(QApplication::translate("MainWindow", "Reset Camera", Q_NULLPTR));
        _2D_Image_AutoPlay->setText(QApplication::translate("MainWindow", "Auto Play", Q_NULLPTR));
        _2D_Text->setPlainText(QApplication::translate("MainWindow", "Auto Play FPS", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(Image2D), QApplication::translate("MainWindow", "2D Image", Q_NULLPTR));
        _3D_Model_Left->setText(QApplication::translate("MainWindow", "Left", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        _3D_Model_Left->setShortcut(QApplication::translate("MainWindow", "Left", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        _3D_Model_Up->setText(QApplication::translate("MainWindow", "Up", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        _3D_Model_Up->setShortcut(QApplication::translate("MainWindow", "Up", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        _3D_Model_Right->setText(QApplication::translate("MainWindow", "Right", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        _3D_Model_Right->setShortcut(QApplication::translate("MainWindow", "Right", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        _3D_Label_Rotate->setPlainText(QApplication::translate("MainWindow", "Rotate Speed", Q_NULLPTR));
        _3D_InformationBox_RotateValue->setSpecialValueText(QString());
        _3D_Model_Generate->setText(QApplication::translate("MainWindow", "Generate Model", Q_NULLPTR));
        _3D_Model_Down->setText(QApplication::translate("MainWindow", "Down", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        _3D_Model_Down->setShortcut(QApplication::translate("MainWindow", "Down", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        _3D_Label_Zoom->setPlainText(QApplication::translate("MainWindow", "Zoom Factor", Q_NULLPTR));
        _3D_Model_ZoomIn->setText(QApplication::translate("MainWindow", "Zoom in", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        _3D_Model_ZoomIn->setShortcut(QApplication::translate("MainWindow", "Q", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        _3D_Model_ZoomOut->setText(QApplication::translate("MainWindow", "Zoom out", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        _3D_Model_ZoomOut->setShortcut(QApplication::translate("MainWindow", "E", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        tabWidget->setTabText(tabWidget->indexOf(Image3D), QApplication::translate("MainWindow", "3D Model", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuAlgorithm->setTitle(QApplication::translate("MainWindow", "Rendering Algorithm", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
