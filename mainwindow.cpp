#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <screenshot.h>
#include <QMessageBox>
#include <QString>
#include <QEvent>
#include <QThread>
#include <QDebug>
#include <QFileDialog>
#include <vtkRendererCollection.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "QtConcurrent/QtConcurrent"
#include "QtConcurrent/qtconcurrentrun.h"
#include "QFuture"
#include "QThreadPool"
#include "QFutureSynchronizer"
#include "QThread"

VTK_MODULE_INIT(vtkRenderingOpenGL) //initialize object factory for Marching Cubes
VTK_MODULE_INIT(vtkRenderingVolumeOpenGL) //initialize object factory for Ray Caster
VTK_MODULE_INIT(vtkInteractionStyle) //initialize object factory for default interation style in 2D
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    vtkObject::GlobalWarningDisplayOff();//turn off the error display (delete to hide the error)
    renderer = vtkSmartPointer<vtkRenderer>::New();// create renderer to fix the overlap render window on other components
    ui->_3D_Model_Renderer->GetRenderWindow()->AddRenderer(renderer);
    ui->_2D_Image_Renderer->GetRenderWindow()->AddRenderer(renderer);
    this->ui->Image3D->setDisabled(true);
    qDebug() << QThread::idealThreadCount();
}

MainWindow::~MainWindow()
{
    delete ui;
}  
void MainWindow::on__2D_Image_ResetCamera_clicked()
{   if (mMaxSliderX < 0){ //check if there are DICOM files in pipeline
        QMessageBox::critical(this, "DRR",
                              "Please open DICOM file",
                              QMessageBox::Ok);
    }
    else {
        defaultCamera();
        imageViewerDCMSeriesX->Render();
    }
}
/*
 * double MainWindow::calPointValue(int beginX,int beginY,double pointX,double pointY,int Oz, double xSpacing, double ySpacing,double* data){
    double q11,  q12,  q21,  q22,  x1,  x2,  y1,  y2,x,y ;
    x = pointX * xSpacing;
    y = pointY * ySpacing;
    x1 = beginX * xSpacing;
    y1 = beginY * ySpacing;
    y2 = (beginY + 1) * xSpacing;
    x2 = (beginX + 1) * ySpacing;
    int q11Index = getOffSet(beginX,beginY,Oz,imageDims);
    int q12Index = getOffSet(beginX,beginY+1,Oz,imageDims);
    int q21Index = getOffSet(beginX+1,beginY,Oz,imageDims);
    int q22Index = getOffSet(beginX+1,beginY+1,Oz,imageDims);
    q11 = data[q11Index];
    q12 = data[q12Index];
    q21 = data[q21Index];
    q22 = data[q22Index];
    double result = bilinearInterpolation(q11,q12,q21,q22,x1,x2,y1,y2,x,y);
    return result;
}
*/

int MainWindow::getOffSet2D(int x, int y,int* dims){
    int offset = x+ y * dims[0];
    return offset;
}


void MainWindow::drawDCMSeries(std::string folderDCM)
{   try{
        this->ui->Image3D->setEnabled(true);
        readerDCMSeries->SetDirectoryName(folderDCM.c_str()); //read the directory
        readerDCMSeries->Update(); //update directory
        imageData = readerDCMSeries->GetOutput();
        qDebug() << readerDCMSeries;
        qDebug() << imageData->GetDataDimension();
        // volume->DeepCopy(readerDCMSeries->GetOutput()); //copy the dataset to new one
        imageViewerDCMSeriesX->SetInputConnection(readerDCMSeries->GetOutputPort()); //get dataset to viewer
        mMinSliderX = imageViewerDCMSeriesX->GetSliceMin();
        mMaxSliderX = imageViewerDCMSeriesX->GetSliceMax();
        ui->_2D_Image_Slicer->setMinimum(mMinSliderX);
        ui->_2D_Image_Slicer->setMaximum(mMaxSliderX);
        imageViewerDCMSeriesX->SetRenderWindow(ui->_2D_Image_Renderer->GetRenderWindow()); //set renderwindow to display
        imageViewerDCMSeriesX->SetSlice(mMinSliderX);
        imageViewerDCMSeriesX->Render();
        imageViewerDCMSeriesX->GetRenderer()->GetActiveCamera()->GetPosition(x,y,z); //get active camera position
        if(mMaxSliderX > 0){
            ui->_2D_Information_ID_out->setText(readerDCMSeries->GetStudyID());
            ui->_2D_Information_Name_out->setText(readerDCMSeries->GetPatientName());
            ui->_2D_Information_Height_out->setText(QString::number(readerDCMSeries->GetHeight()));
            ui->_2D_Information_Width_out->setText(QString::number(readerDCMSeries->GetWidth()));
            ui->_2D_Information_DesName_out->setText(readerDCMSeries->GetDescriptiveName());
            ui->_2D_Information_Location_out->setText(readerDCMSeries->GetDirectoryName());
        }
        //imageData = readerDCMSeries->GetOutput();
        imageDims = imageData->GetDimensions();
        qDebug() << imageDims;
        double* _pixelSpacing = readerDCMSeries->GetPixelSpacing();
        qDebug() << imageDims[0];
        qDebug() << *(imageDims+1);
        qDebug() << *(imageDims+2);
        qDebug() << *_pixelSpacing;
        qDebug() << *(_pixelSpacing+1);
        qDebug() << *(_pixelSpacing+2);
        throw mMaxSliderX;
    }
    catch (int err){ //catch error if there are no DICOM files
        if (err <=0){
            this->ui->Image3D->setDisabled(true);
            QMessageBox::critical(this, "DRR",
                                  "Folder you open does not contain any DICOM images, please retry .",
                                  QMessageBox::Ok);
        }
    }

}
void MainWindow::openDCMFolder()
{

    dir->setParent(this);
    dir->setFileMode(QFileDialog::DirectoryOnly);
    QDir folderNameDCM;
    if (lastUsedDir.isNull()){
        dir->setDirectory(QDir::currentPath());
        if (dir->exec()){
            initialize();
            folderNameDCM = dir->directory();
            lastUsedDir = folderNameDCM.absolutePath();
            std::string stdstrFolderNameDCM = folderNameDCM.absolutePath().toUtf8().constData();
            drawDCMSeries(stdstrFolderNameDCM);
        }
    }
    else{
        dir->setDirectory(lastUsedDir);
        if(dir->exec()){
            initialize();
            folderNameDCM = dir->directory();
            lastUsedDir = folderNameDCM.absolutePath();
            std::string stdstrFolderNameDCM = folderNameDCM.absolutePath().toUtf8().constData();
            drawDCMSeries(stdstrFolderNameDCM);
        }
    };
    /* move inside condition to prevent getting invalid directory
        std::string stdstrFolderNameDCM = folderNameDCM.toUtf8().constData();
        drawDCMSeries(stdstrFolderNameDCM);
    */

    /*   old code
  * else {
       //delete the pipeline to ensure the uniform of data from 2D to 3D
        initialize();
        QString folderNameDCM = QFileDialog::getExistingDirectory(this,tr("Open DCM Folder"),QDir::currentPath(),QFileDialog::ShowDirsOnly);
        std::string stdstrFolderNameDCM = folderNameDCM.toUtf8().constData();
        drawDCMSeries(stdstrFolderNameDCM);
    }
    */
}

void MainWindow::on_actionOpen_DICOM_Folder_triggered()
{
    openDCMFolder();
}
void MainWindow::initialize(){
    // rayCastFunction = vtkSmartPointer<vtkVolumeRayCastCompositeFunction>::New(); // old code
    readerDCMSeries = vtkSmartPointer<vtkDICOMImageReader>::New();
    imageViewerDCMSeriesX = vtkSmartPointer<vtkImageViewer2>::New();
    imageData = vtkSmartPointer<vtkImageData>::New();
    simplePointReader = vtkSmartPointer<vtkSimplePointsReader>::New();
    mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    actor = vtkSmartPointer<vtkActor>::New();
    renderer = vtkSmartPointer<vtkRenderer>::New();
    PLYReader = vtkSmartPointer<vtkPLYReader>::New();
    // volume = vtkSmartPointer<vtkImageData>::New();

}

void MainWindow::defaultCamera(){ //set the default position to make the 2D image viewable after interaction
    imageViewerDCMSeriesX->GetRenderer()->GetActiveCamera()->SetPosition(x,y,z);
    imageViewerDCMSeriesX->GetRenderer()->GetActiveCamera()->SetViewUp(0,1,0);
}


void MainWindow::on__2D_Image_AutoPlay_clicked()
{   //running the display through all slices
    if (mMaxSliderX < 0){ //check if there are DICOM files in pipeline
        QMessageBox::critical(this, "DRR",
                              "Please open DICOM file",
                              QMessageBox::Ok);
    }
    else {
        int tempPosition = mMinSliderX;
        defaultCamera();
        while (tempPosition <= mMaxSliderX){
            imageViewerDCMSeriesX->SetSlice(tempPosition);
            imageViewerDCMSeriesX->Render();
            QThread::msleep((1000/ui->_2D_FPS->value())); //set the program the stop after interval for the each slice
            tempPosition++;

        }
    }
}
void MainWindow::initialize3D(){
    volumeMapper = vtkSmartPointer<vtkVolumeRayCastMapper>::New();
    volumeColor = vtkSmartPointer<vtkColorTransferFunction>::New();
    volumeScalarOpacity = vtkSmartPointer<vtkPiecewiseFunction>::New();
    volumeGradientOpacity = vtkSmartPointer<vtkPiecewiseFunction>::New();
    volumeProperty = vtkSmartPointer<vtkVolumeProperty>::New();
    volume3D = vtkSmartPointer<vtkVolume>::New();
    volumeTextureMapper = vtkSmartPointer<vtkVolumeTextureMapper3D>::New();
    surface = vtkSmartPointer<vtkMarchingCubes>::New();
    fixedPointVolumeRaycaster = vtkSmartPointer<vtkFixedPointVolumeRayCastMapper>::New();
}

void MainWindow::on__3D_Model_Generate_clicked()
{
    vtkSmartPointer<vtkRendererCollection> list = ui->_3D_Model_Renderer->GetRenderWindow()->GetRenderers(); //get number of renderer
    list->RemoveAllItems(); //remove all current renderers. If you want two renderers layer, do not remove the old renderer
    initialize3D(); // construct all pipeline
    if (mMaxSliderX <= 0){ //check if there are DICOM files in pipeline
        QMessageBox::critical(this, "DRR",
                              "Please open DICOM file before generate 3D",
                              QMessageBox::Ok);
    }
    else {
        if (algorithm ==0){ //Marching Cube
            surface->SetInputData( readerDCMSeries->GetOutput()); //input the volume to MC algorithm
            if (marchingCubesSettings->getMarchingCubes()=="value"){ // if use single threshold value
                surface->SetNumberOfContours(4);//set number of contour to 4. Adjust this value to have more contours
                surface->SetValue(0,marchingCubesSettings->getContourValues().at(0)); //contour 1 value
                surface->SetValue(1,marchingCubesSettings->getContourValues().at(1)); //contour 2 value
                surface->SetValue(2,marchingCubesSettings->getContourValues().at(2)); //contour 3 value
                surface->SetValue(3,marchingCubesSettings->getContourValues().at(3)); //contour 4 value
            }
            else { //if use threshold range
                surface->GenerateValues(marchingCubesSettings->getNumberOfContour(),(double)marchingCubesSettings->getMin(),(double)marchingCubesSettings->getMax());
            }
            if (marchingCubesSettings->getColor()) // if we want to set color to output mesh
            {
                vtkSmartPointer<vtkLookupTable> colorTable = vtkSmartPointer<vtkLookupTable> ::New();
                colorTable->SetHueRange(0,1);
                colorTable->Build();
                mapper->SetScalarRange(0,5000);
                mapper->SetLookupTable(colorTable);
                mapper->ScalarVisibilityOn();//turn off/on the function to color image according to scalar value
            }
            else{
                mapper->ScalarVisibilityOff();
            }
            surface->SetComputeGradients(marchingCubesSettings->getGradient());
            surface->SetComputeNormals(marchingCubesSettings->getNormals());
            mapper->SetInputConnection(surface->GetOutputPort());//input for mapper
            actor->SetMapper(mapper);//bound mapper to actor
            renderer->AddActor(actor);//add actor to renderer
            renderer->SetBackground(.1, .2, .3); // set background color
            ui->_3D_Model_Renderer->GetRenderWindow()->AddRenderer(renderer);//add renderer to display window
            ui->_3D_Model_Renderer->GetRenderWindow()->Render();
        }
        else if (algorithm == 1) //Texture mapping 3D
        {
            setVolumePropertyTexture();
            volumeTextureMapper->SetInputData( readerDCMSeries->GetOutput()); // set the input data for TB
            volumeTextureMapper->SetSampleDistance(textureMapperSettings->getSamplingDistant());
            volumeTextureMapper->SetUseCompressedTexture(textureMapperSettings->getUseCompress());
            volume3D->SetMapper(volumeTextureMapper);
            volume3D->SetProperty(volumeProperty);
            renderer->AddViewProp(volume3D);
            ui->_3D_Model_Renderer->GetRenderWindow()->AddRenderer(renderer);
            // ui->_3D_Model_Renderer->GetRenderWindow()->Start();
            //     ui->_3D_Model_Renderer->GetRenderWindow()->Finalize();
            ui->_3D_Model_Renderer->GetRenderWindow()->Render();
        }
        else if (algorithm == 2) {
            /*  if (volume->GetDataObjectType()==5){ // design which algorithm should be used for each data type
                volumeMapper->SetInputData(volume);
                volumeMapper->SetVolumeRayCastFunction(rayCastFunction);
                volumeRaycaster->SetMapper(volumeMapper);
                volumeRaycaster->SetProperty(volumeProperty);
                renderer->AddViewProp(volumeRaycaster);
                  renderer->SetBackground(.1, .2, .3);
                ui->_3D_Model_Renderer->GetRenderWindow()->AddRenderer(renderer);
                ui->_3D_Model_Renderer->GetRenderWindow()->Start();
                ui->_3D_Model_Renderer->GetRenderWindow()->Finalize();
                ui->_3D_Model_Renderer->GetRenderWindow()->Render();
            }*/
            //remove base ray caster and replace all method with fixed point ray caster
            setVolumePropertyRaycaster(); //set volume attribute for raycasting algorithm
            fixedPointVolumeRaycaster->SetInputData( readerDCMSeries->GetOutput()); // fixed point ray caster
            if (rayCasterSettings->getBlendMode()=="Minip")
                fixedPointVolumeRaycaster->SetBlendModeToMinimumIntensity();
            else if (rayCasterSettings->getBlendMode()=="Composite"){
                fixedPointVolumeRaycaster->SetBlendModeToComposite();
                volume3D->SetProperty(volumeProperty);
            }
            else if (rayCasterSettings->getBlendMode()=="Maxip")
                fixedPointVolumeRaycaster->SetBlendModeToMaximumIntensity();
            else{
                fixedPointVolumeRaycaster->SetBlendModeToAdditive();
                volume3D->SetProperty(volumeProperty);
            }
            volume3D->SetMapper(fixedPointVolumeRaycaster);
            renderer->AddViewProp(volume3D);
            ui->_3D_Model_Renderer->GetRenderWindow()->AddRenderer(renderer);
            //  ui->_3D_Model_Renderer->GetRenderWindow()->Start();
            //   ui->_3D_Model_Renderer->GetRenderWindow()->Finalize();
            ui->_3D_Model_Renderer->GetRenderWindow()->Render();
        }
    }
    qDebug() << list->GetNumberOfItems();
    ex = 1;
}

void MainWindow::setVolumePropertyRaycaster(){
    volumeColor->AddRGBPoint(*controlPointRaycaster1,    *(controlPointRaycaster1+1),  *(controlPointRaycaster1+2),  *(controlPointRaycaster1+3));
    volumeColor->AddRGBPoint(*controlPointRaycaster2,   *(controlPointRaycaster2+1),  *(controlPointRaycaster2+2),  *(controlPointRaycaster2+3));
    volumeColor->AddRGBPoint(*controlPointRaycaster3,  *(controlPointRaycaster3+1),  *(controlPointRaycaster3+2),  *(controlPointRaycaster3+3));
    volumeScalarOpacity->AddPoint(*controlPointRaycaster1,     *(controlPointRaycaster1+4));
    volumeScalarOpacity->AddPoint(*controlPointRaycaster2,   *(controlPointRaycaster2+4));
    volumeScalarOpacity->AddPoint(*controlPointRaycaster3,  *(controlPointRaycaster3+4));
    volumeGradientOpacity->AddPoint(*controlPointRaycaster1,    *(controlPointRaycaster1+4));
    volumeGradientOpacity->AddPoint(*controlPointRaycaster2,   *(controlPointRaycaster2+4));
    volumeGradientOpacity->AddPoint(*controlPointRaycaster3,  *(controlPointRaycaster3+4));
    volumeProperty->SetColor(volumeColor);
    volumeProperty->SetScalarOpacity(volumeScalarOpacity);
    volumeProperty->SetGradientOpacity(volumeGradientOpacity);
    volumeProperty->SetInterpolationTypeToLinear();
    volumeProperty->ShadeOn();
    volumeProperty->SetAmbient(*lightSettingsRaycaster);
    volumeProperty->SetDiffuse(*(lightSettingsRaycaster+1));
    volumeProperty->SetSpecular(*(lightSettingsRaycaster+2));
}
void MainWindow::setVolumePropertyTexture(){
    volumeColor->AddRGBPoint(*controlPointTexture1,    *(controlPointTexture1+1),  *(controlPointTexture1+2),  *(controlPointTexture1+3));
    volumeColor->AddRGBPoint(*controlPointTexture2,   *(controlPointTexture2+1),  *(controlPointTexture2+2),  *(controlPointTexture2+3));
    volumeColor->AddRGBPoint(*controlPointTexture3,  *(controlPointTexture3+1),  *(controlPointTexture3+2),  *(controlPointTexture3+3));
    volumeScalarOpacity->AddPoint(*controlPointTexture1,     *(controlPointTexture1+4));
    volumeScalarOpacity->AddPoint(*controlPointTexture2,   *(controlPointTexture2+4));
    volumeScalarOpacity->AddPoint(*controlPointTexture3,  *(controlPointTexture3+4));
    volumeGradientOpacity->AddPoint(*controlPointTexture1,    *(controlPointTexture1+4));
    volumeGradientOpacity->AddPoint(*controlPointTexture2,   *(controlPointTexture2+4));
    volumeGradientOpacity->AddPoint(*controlPointTexture3,  *(controlPointTexture3+4));
    volumeProperty->SetColor(volumeColor);
    volumeProperty->SetScalarOpacity(volumeScalarOpacity);
    volumeProperty->SetGradientOpacity(volumeGradientOpacity);
    volumeProperty->SetInterpolationTypeToLinear();
    volumeProperty->ShadeOn();
    volumeProperty->SetAmbient(*lightSettingsTexture);
    volumeProperty->SetDiffuse(*(lightSettingsTexture+1));
    volumeProperty->SetSpecular(*(lightSettingsTexture+2));
}

void MainWindow::on__3D_Model_ZoomIn_pressed()
{
    if(mMaxSliderX > 0){
        renderer->GetActiveCamera()->Zoom(1+((float)(ui->_3D_InformationBox_ZoomValue->value())/10.00));
        ui->_3D_Model_Renderer->GetRenderWindow()->Render();
    }
}
void MainWindow::on__3D_Model_ZoomOut_pressed()
{
    if(mMaxSliderX > 0){
        renderer->GetActiveCamera()->Zoom(1-((float)(ui->_3D_InformationBox_ZoomValue->value())/20.00));
        ui->_3D_Model_Renderer->GetRenderWindow()->Render();
    }
}

void MainWindow::on__3D_Model_Up_clicked()
{
    if (mMaxSliderX > 0){
        renderer->GetActiveCamera()->Elevation(ui->_3D_InformationBox_RotateValue->value());
        ui->_3D_Model_Renderer->GetRenderWindow()->Render();
    }
}

void MainWindow::on__3D_Model_Down_clicked()
{
    if (mMaxSliderX > 0){
        renderer->GetActiveCamera()->Elevation(-ui->_3D_InformationBox_RotateValue->value());
        ui->_3D_Model_Renderer->GetRenderWindow()->Render();
    }
}


void MainWindow::on__3D_Model_Left_clicked()
{
    if (mMaxSliderX > 0){
        renderer->GetActiveCamera()->Azimuth(ui->_3D_InformationBox_RotateValue->value());
        ui->_3D_Model_Renderer->GetRenderWindow()->Render();
    }
}

void MainWindow::on__3D_Model_Right_clicked()
{
    if (mMaxSliderX > 0){
        renderer->GetActiveCamera()->Azimuth(-ui->_3D_InformationBox_RotateValue->value());
        ui->_3D_Model_Renderer->GetRenderWindow()->Render();
    }
}

void MainWindow::on__2D_Image_Slicer_valueChanged(int position)
{
    imageViewerDCMSeriesX->SetSlice(position);
    defaultCamera();
    imageViewerDCMSeriesX->Render();
}
//help action
void MainWindow::on_actionHelp_triggered()
{
    QMessageBox::information(this,"Help","Use arrow to rotate model\n Q and E to zoom in and zoom out\n To generate 3D model, input iso-value and press Generate 3D Model",QMessageBox::Ok);
}

void MainWindow::on_actionMarching_Cubes_Settings_triggered()
{   algorithm = 0;
    marchingCubesSettings->exec();
}
//raycast settings
void MainWindow::on_actionRay_Casting_Settings_triggered()
{
    algorithm = 2;
    if(rayCasterSettings->exec()){
        controlPointRaycaster1 = rayCasterSettings->point1Settings();
        controlPointRaycaster2 = rayCasterSettings->point2Settings();
        controlPointRaycaster3 = rayCasterSettings->point3Settings();
        lightSettingsRaycaster = rayCasterSettings->lightSettings();
    }
}
//render window on tab change
void MainWindow::on_tabWidget_tabBarClicked(int index)
{   if (!isRenderWindowFinalized){
        ui->_2D_Image_Renderer->GetRenderWindow()->Finalize();
        ui->_3D_Model_Renderer->GetRenderWindow()->Finalize();
        isRenderWindowFinalized = true;
    }
    if (index == 0)
    {
        ui->_2D_Image_Renderer->GetRenderWindow()->Render();
    }
    else{
        ui->_3D_Model_Renderer->GetRenderWindow()->Render();
    }
}
//open DICOM action
void MainWindow::on_actionOpen_DICOM_Image_triggered()
{
    file->setParent(this);
    file->setFileMode(QFileDialog::ExistingFile);
    if (file->exec()){
        QStringList fileNameDCM = file->selectedFiles();
        std::string stdstrFileNameDCM = fileNameDCM.at(0).toUtf8().constData();
        initialize();
        try{
            this->ui->Image3D->setDisabled(true); //disable 3D tab
            readerDCMSeries->SetFileName(stdstrFileNameDCM.c_str());
            readerDCMSeries->Update();
            imageViewerDCMSeriesX->SetInputConnection(readerDCMSeries->GetOutputPort()); //get dataset to viewer
            mMinSliderX = imageViewerDCMSeriesX->GetSliceMin();
            mMaxSliderX = imageViewerDCMSeriesX->GetSliceMax();
            ui->_2D_Image_Slicer->setMinimum(mMinSliderX);
            ui->_2D_Image_Slicer->setMaximum(mMaxSliderX);
            imageViewerDCMSeriesX->SetRenderWindow(ui->_2D_Image_Renderer->GetRenderWindow()); //set renderwindow to display
            imageViewerDCMSeriesX->SetSlice(mMinSliderX);
            imageViewerDCMSeriesX->Render();
            imageViewerDCMSeriesX->GetRenderer()->GetActiveCamera()->GetPosition(x,y,z); //get active camera position
            ui->_2D_Information_ID_out->setText(readerDCMSeries->GetStudyID());
            ui->_2D_Information_Name_out->setText(readerDCMSeries->GetPatientName());
            ui->_2D_Information_Height_out->setText(QString::number(readerDCMSeries->GetHeight()));
            ui->_2D_Information_Width_out->setText(QString::number(readerDCMSeries->GetWidth()));
            ui->_2D_Information_DesName_out->setText(readerDCMSeries->GetDescriptiveName());
            ui->_2D_Information_Location_out->setText(fileNameDCM.at(0));
        }
        catch (int err){ //catch error if there are no DICOM files
            if (err <=0){
                this->ui->Image3D->setEnabled(true);
                QMessageBox::critical(this, "DRR",
                                      "Folder you open does not contain any DICOM images, please retry .",
                                      QMessageBox::Ok);
            }
        }
    }
}
//save action
void MainWindow::on_actionSave_triggered()
{   if (this->ui->tabWidget->currentIndex()==1)
        screenShot.doScreenShot(ui->_3D_Model_Renderer->GetRenderWindow());
    else
        screenShot.doScreenShot(ui->_2D_Image_Renderer->GetRenderWindow());
}

void MainWindow::resizeEvent(QResizeEvent *event){
    QMainWindow::resizeEvent(event);
    ui->_3D_Model_Renderer->GetRenderWindow()->Finalize();
    ui->_2D_Image_Renderer->GetRenderWindow()->Finalize();
    ui->_3D_Model_Renderer->GetRenderWindow()->Render();
    ui->_2D_Image_Renderer->GetRenderWindow()->Render();
    qDebug("test");
}

void MainWindow::on_actionTexture_Mapper_triggered()
{
    algorithm = 1;
    if (textureMapperSettings->exec()){
        controlPointTexture1 = textureMapperSettings->point1Settings();
        controlPointTexture2 = textureMapperSettings->point2Settings();
        controlPointTexture3 = textureMapperSettings->point3Settings();
        lightSettingsTexture = textureMapperSettings->lightSettings();
    }
}

void MainWindow::on_actionAbout_3DF2D_triggered()
{
    QMessageBox::information(this,"About 3DF2D","3D Model From 2D Dicom\nVersion 1.0.0427\nInternational University, Computer Science & Engineering Department.\nDescription: An application based on VTK library for building, vissualizing and handling a 3D object from CT scanned slices. This application is built for aiding medical staffs and doctors in diagnostic and treatment of patients.",QMessageBox::Ok);
}

void MainWindow::on_actionContact_Author_triggered()
{
    QMessageBox::information(this,"About Authors","If you have any problems or encounter any errors, please contact us as follow:\nvhmquang@gmail.com\nnvsinh@hcmiu.edu.vn",QMessageBox::Ok);

}

void MainWindow::on_actionSave_as_xyz_file_triggered()
{
    if (clockWiseTraceSettings->exec())
    {
        qDebug() << "Start saving";
        int width = *imageDims;
        qDebug() << width;
        int height = *(imageDims +1);
        int depth = *(imageDims+2);
        double* imageSpacing = imageData->GetSpacing();
        qDebug() << imageSpacing;
        double xSpacing = *imageSpacing;
        double ySpacing = *(imageSpacing +1);
        double zSpacing = *(imageSpacing +2);
        numberOfAddedPoint = 0;
        double indexRatio = 0.0;
        indexRatio = zSpacing/xSpacing;
        numberOfAddedPoint = int(xSpacing*width/zSpacing);
        // buffer 20 points
        resultSize = numberOfAddedPoint*numberOfAddedPoint*depth;
        result = new double[resultSize];
        finalResult = new int[resultSize];
        int simple[3] = {numberOfAddedPoint,numberOfAddedPoint,1};
        resultDims = imageDims;
        vtkIdType a = imageData->GetNumberOfPoints();
        double* spacing = readerDCMSeries->GetPixelSpacing();
        int maxDimension = numberOfAddedPoint*numberOfAddedPoint*depth;
        int _pointAdd = int(spacing[2]/spacing[1])+10;
        qDebug() << imageSpacing;
        /*
    //Calculate data for new grid
    for (int z = 0; z < imageDims[2]; z++ ){
        //    qDebug("Running Inside Image");
        QVector<double> tempVector;
        for (int y = 0; y < numberOfAddedPoint;y++){
            for (int x = 0; x < numberOfAddedPoint; x++){
                if ((fmod((x * indexRatio), xSpacing) == 0) && (fmod((y * indexRatio), ySpacing) == 0)){
                    int resultIndex = getOffSet(x,y,z,resultDims);
                    int dataIndex = getOffSet(x * indexRatio,y * indexRatio,z,imageDims);
                    result[resultIndex] =  dataArray[dataIndex];
                    tempVector.append(dataArray[dataIndex]);
                    //qDebug() << "x: " << x <<"\t y: "<< y << "\t z: "<<z <<"\n";
                    qDebug() << "Index: " << resultIndex << "Data: " << result[resultIndex];
                }
                else {
                    double pointX = x * indexRatio;
                    double pointY = y * indexRatio;
                    int i = static_cast<int> (floor(pointX));
                    int j = static_cast<int> (floor(pointY));
                    int resultIndex = getOffSet(x,y,z,resultDims);
                    result[resultIndex] = calPointValue(i,j,pointX,pointY,z,xSpacing,ySpacing,dataArray);
                    tempVector.append( calPointValue(i,j,pointX,pointY,z,xSpacing,ySpacing,dataArray));
                    //qDebug() << "Index: " << resultIndex << "Data: " << result[resultIndex];
                }
            }
        }
        modifiedDataVector.append(tempVector);
        QVector<QVector<double>> same = modifiedDataVector;
    }*/
        //  qDebug() << imageData->GetScalarComponentAsDouble(70,267,0,0);
        int* _imageDims = imageDims;
        QFutureSynchronizer<QVector<int>> futureSync;
        QThreadPool::globalInstance()->setMaxThreadCount(3);
        QVector<BoundaryExtractor*> listExtractor;
        int z;
        qDebug() << "This thread" << QThread::currentThreadId();
        QThread thread;
        for (z = 0; z < resultDims[2]; z++)
        {
            BoundaryExtractor *t = new BoundaryExtractor(z,_imageDims,imageData,clockWiseTraceSettings);
            t->moveToThread(&thread);
            t->executeBoundary();
            // QObject::connect(this,SIGNAL(execute()),t,SLOT(executeBoundary()));
            listExtractor.append(t);
            // auto f1 = QtConcurrent::run(QThreadPool::globalInstance(),clockWiseTrace,z,_imageDims,imageData,clockWiseTraceSettings);
            // futureSync.addFuture(f1);
            qDebug() << "Number of thread" << QThreadPool::globalInstance()->activeThreadCount();
        }
        thread.start();
        bool isFinishLoop = false;
        emit execute();
        /*
        while (!isFinishLoop){
            isFinishLoop = true;
            for (int i = 0; i < listExtractor.size();i++)
            {
                qDebug() << "status" << listExtractor.at(i)->getStatus() << "slice" << i;
                if (!listExtractor.at(i)->getStatus())
                    isFinishLoop = false;
            }

        }
        */

        //futureSync.waitForFinished();
        //auto listFutures = futureSync.futures();

        int i;
        for (i = 0; i < listExtractor.size(); i++){
            qDebug() << "Print result" ;
            externalBoundaryVector.append(listExtractor.at(i)->getResult());
        }

        //qDebug() << externalBoundaryVector.size();
        //printXYZfile("filterDataVector.xyz",filterDataVector,resultDims,imageSpacing);
        //printXYZfile("boundaryDataVector.xyz",boundaryDataVector,resultDims,imageSpacing);
        //  printXYZfile("externalBoundaryData.xyz",externalBoundaryVector,resultDims,imageSpacing);
        //qDebug() << fillVector.size();
        //  printSingleXYZfile("fillData.xyz",fillVector,resultDims,imageSpacing);
    }
}
void MainWindow::printXYZfile(QString filename, QVector<QVector<int> > data, int *dims, double *spacing){
    QString filename1 = filename;
    QFile file( filename1 );
    QVector<int> temp;
    double localX;
    double localY;
    double localZ;
    int count = 0;
    int i;
    int j;
    if ( file.open(QIODevice::ReadWrite | QIODevice::Text) )
    {
        QTextStream stream( &file );
        for (i = 0; i < data.size() ; i++)
        {
            temp = data.at(i);
            for (j = 0; j < temp.size(); j++)
            {
                // int* location = indexTo3D(temp.value(j),dims);
                //  localX = location[0] * spacing[0];
                // localY= location[1] * spacing[1];
                //  localZ = count * spacing[2];
                //  stream << localX << ' ';
                //  stream << localY << ' ';
                //  stream << localZ << ' ';
                stream << '\n';
                //delete []location;
            }
            count++;
        }
    }
}

void MainWindow::on_actionOpen_xyz_File_triggered()
{
    file->setParent(this);
    file->setFileMode(QFileDialog::ExistingFile);
    if (file->exec()){
        QStringList fileNameDCM = file->selectedFiles();
        std::string stdstrFileNameDCM = fileNameDCM.at(0).toUtf8().constData();
        initialize();
        try{
            this->ui->Image3D->setDisabled(false); //enable 3D tab
            simplePointReader->SetFileName(stdstrFileNameDCM.c_str());
            simplePointReader->Update();
            mapper->SetInputConnection(simplePointReader->GetOutputPort()); //get dataset to viewer
            actor->SetMapper(mapper);
            actor->GetProperty()->SetPointSize(1);
            renderer->AddActor(actor);
            ui->_3D_Model_Renderer->GetRenderWindow()->AddRenderer(renderer);
            ui->_3D_Model_Renderer->GetRenderWindow()->Render();
            ballPivot->setFile(stdstrFileNameDCM);
        }
        catch (int err){ //catch error if there are no DICOM files
            if (err <=0){
                this->ui->Image3D->setEnabled(true);
                QMessageBox::critical(this, "DRR",
                                      "Folder you open does not contain any DICOM images, please retry .",
                                      QMessageBox::Ok);
            }
        }
    }
}

void MainWindow::on_actionBall_Pivot_triggered()
{
    algorithm = 3;
    if(ballPivot->exec())
    {
        ballPivot->buildMesh();
    }
    vtkSmartPointer<vtkRendererCollection> list = ui->_3D_Model_Renderer->GetRenderWindow()->GetRenderers(); //get number of renderer
    list->RemoveAllItems(); //remove all renderer to reduce memory
    PLYReader = vtkSmartPointer<vtkPLYReader>::New();
    PLYReader->SetFileName("result.ply");
    qDebug() << "set file name ok";
    PLYReader->Update();
    mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper->SetInputConnection(PLYReader->GetOutputPort()); //get dataset to viewer
    actor = vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);
    renderer = vtkSmartPointer<vtkRenderer>::New();
    renderer->AddActor(actor);
    qDebug() << "set mapper + actor  ok";
    ui->_3D_Model_Renderer->GetRenderWindow()->AddRenderer(renderer);
    ui->_3D_Model_Renderer->GetRenderWindow()->Render();
}
