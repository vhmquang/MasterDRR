#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vtkSmartPointer.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderer.h>
#include <vtkDICOMImageReader.h>
#include <vtkImageViewer2.h>
#include <vtkMarchingCubes.h>
#include <vtkRenderWindow.h>
#include <vtkImageData.h>
#include <vtkCamera.h>
#include <vtkObject.h>
#include <vtkOutputWindow.h>
#include <vtkVolume.h>
#include <vtkVolumeRayCastMapper.h>
#include <vtkVolumeRayCastCompositeFunction.h>
#include <vtkVolumeProperty.h>
#include <vtkColorTransferFunction.h>
#include <vtkPiecewiseFunction.h>
#include <vtkWin32OutputWindow.h>
#include <vtkFixedPointVolumeRayCastMapper.h>
#include <vtkVolumeTextureMapper3D.h>
#include <vtkAutoInit.h>
#include <vtkProperty.h>
#include <vtkLookupTable.h>
#include <QVTKWidget.h>
#include <QFileDialog.h>
#include <screenshot.h>
#include <marchingcubes.h>
#include <raycaster.h>
#include <texturemapper.h>

#include <vtkSimplePointsWriter.h>
#include <vtkImageDataGeometryFilter.h>
#include <vtkWin32OutputWindow.h>
#include <vtkPolyData.h>
#include <vtkDelaunay3D.h>
#include <vtkDataSetMapper.h>
#include <vtkProperty.h>
#include <vtkPolyDataMapper.h>
#include <vtkCleanPolyData.h>
#include <vtkSimplePointsReader.h>
#include <vtkXMLPolyDataWriter.h>
#include <vtkDataSetSurfaceFilter.h>
#include <vtkXMLPolyDataReader.h>
#include <vtkDataSet.h>
#include <vtkPointSet.h>
#include <vtkXMLImageDataWriter.h>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QDebug>
#include <QVector3D>
#include <QVector2D>
#include <QVector>
#include <math.h>
#include <linefunction.h>
#include <QHash>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void resizeEvent(QResizeEvent *event);
private slots:
    void openDCMFolder();
    void drawDCMSeries(std::string folderDCM);

    void on__2D_Image_ResetCamera_clicked();

    void on_actionOpen_DICOM_Folder_triggered();
    void initialize();
    void defaultCamera();
    void initialize3D();
    void on__2D_Image_AutoPlay_clicked();
    void on__3D_Model_Generate_clicked();

    void on__3D_Model_ZoomIn_pressed();

    void on__3D_Model_ZoomOut_pressed();

    void on__3D_Model_Up_clicked();

    void on__3D_Model_Down_clicked();

    void on__3D_Model_Left_clicked();

    void on__3D_Model_Right_clicked();

    void on__2D_Image_Slicer_valueChanged(int position);

    void on_actionHelp_triggered();

    void setVolumePropertyTexture();

    void setVolumePropertyRaycaster();

    void on_actionMarching_Cubes_Settings_triggered();

    void on_actionRay_Casting_Settings_triggered();

    void on_tabWidget_tabBarClicked(int index);

    void on_actionOpen_DICOM_Image_triggered();

    void on_actionSave_triggered();

    void on_actionTexture_Mapper_triggered();

    void on_actionAbout_3DF2D_triggered();

    void on_actionContact_Author_triggered();

    double bilinearInterpolation(double q11, double q12, double q21, double q22, double x1, double x2, double y1, double y2, double x, double y);

    int getOffSet2D(int x, int y, int* dims);

    void printXYZfile(QString filename, QVector<QVector<int>> data, int* dims, double *spacing);

    void on_actionSave_as_xyz_file_triggered();

private:
    Ui::MainWindow *ui;
    vtkSmartPointer<vtkDICOMImageReader> readerDCMSeries;
    vtkSmartPointer<vtkImageViewer2> imageViewerDCMSeriesX;
    vtkSmartPointer<vtkImageData> volume;
    vtkSmartPointer<vtkMarchingCubes> surface;
    vtkSmartPointer<vtkRenderer> renderer;
    vtkSmartPointer<vtkPolyDataMapper> mapper ;
    vtkSmartPointer<vtkActor> actor;
    vtkSmartPointer<vtkCamera> camera;
    vtkSmartPointer<vtkVolumeRayCastCompositeFunction> rayCastFunction;
    vtkSmartPointer<vtkVolumeRayCastMapper> volumeMapper;
    vtkSmartPointer<vtkColorTransferFunction>volumeColor;
    vtkSmartPointer<vtkPiecewiseFunction> volumeScalarOpacity;
    vtkSmartPointer<vtkPiecewiseFunction> volumeGradientOpacity;
    vtkSmartPointer<vtkVolumeProperty> volumeProperty;
    vtkSmartPointer<vtkVolume> volume3D;
    vtkSmartPointer<vtkFixedPointVolumeRayCastMapper> fixedPointVolumeRaycaster;
    vtkSmartPointer<vtkVolumeTextureMapper3D> volumeTextureMapper;
    int algorithm = 0;
    int mMinSliderX = -1;
    int mMaxSliderX = -1;
    double x;
    double y;
    double z;
    int ex = 0;
    bool isRenderWindowFinalized = false;
    bool isZoom = true;
    bool isNotZoom = true;
    double *controlPointRaycaster1;
    double *controlPointRaycaster2;
    double *controlPointRaycaster3;
    double *lightSettingsRaycaster;
    QString lastUsedDir;
    QFileDialog *dir = new QFileDialog(this);
    QFileDialog *file = new QFileDialog(this);
    Raycaster *rayCasterSettings = new Raycaster(this);
    ScreenShot screenShot;
    marchingcubes *marchingCubesSettings = new marchingcubes(this);
    texturemapper *textureMapperSettings = new texturemapper(this);
    double *controlPointTexture1;
    double *controlPointTexture2;
    double *controlPointTexture3;
    double *lightSettingsTexture;

    int sliceMin;
    int finalIndex = 0;
    int sliceMax;
    int* imageDims;
    double* result;
    int firstPoint;
    int resultSize;
    int* finalResult;
    double lowerBound = 400;
    double defaultLowerBound = 400;
    double upperBound = 2500;
    double maxLowerBound = 2500;
    double stepBound = 100;
    QVector<int> resultVector;
    QVector<QVector<double>> modifiedDataVector;
    QVector<int> tempVector;
    QVector<QVector<int>> finalVector;
    QVector<int> filterDataVector;
    QVector<int> boundaryDataVector;
    QVector<QVector<int>> externalBoundaryVector;
    QVector<int> blackListVector;
    QVector<int> fillVector;
    int* resultDims;
    int   numberOfAddedPoint = 0;
    QHash<int,double> dataArray;
    vtkSmartPointer<vtkImageData> imageData ;
    vtkSmartPointer<vtkSimplePointsWriter> xyzWriter = vtkSmartPointer<vtkSimplePointsWriter>::New();
    vtkSmartPointer<vtkImageViewer2> imageViewerDCMSeries = vtkSmartPointer<vtkImageViewer2>::New();
    vtkSmartPointer<vtkImageDataGeometryFilter> imageFilter = vtkSmartPointer<vtkImageDataGeometryFilter>::New();
    vtkSmartPointer<vtkDelaunay3D> delaunay3D = vtkSmartPointer<vtkDelaunay3D>::New();
    enum startPosition { left = 0, right = 1};

};

#endif // MAINWINDOW_H
