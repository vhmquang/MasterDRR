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
void MainWindow::drawDCMSeries(std::string folderDCM)
{   try{
        this->ui->Image3D->setEnabled(true);
        readerDCMSeries->SetDirectoryName(folderDCM.c_str()); //read the directory
        readerDCMSeries->Update(); //update directory
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
   // volume = vtkSmartPointer<vtkImageData>::New();

}
/* old code
 * void MainWindow::restart(){
    rayCastFunction->Delete();
    volumeMapper->Delete();
    mMaxSliderX=0;
    volumeColor->Delete();
    volumeScalarOpacity->Delete();
    volumeGradientOpacity->Delete();
    volumeProperty->Delete();
    volumeRaycaster->Delete();
    readerDCMSeries->Delete();
    imageViewerDCMSeriesX->Delete();
    volume->Delete();
    surface->Delete();
    renderer->Delete();
    mapper->Delete();
    actor->Delete();
    fixedPointVolumeRaycaster->Delete();
}
*/
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
    mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    actor = vtkSmartPointer<vtkActor>::New();
    fixedPointVolumeRaycaster = vtkSmartPointer<vtkFixedPointVolumeRayCastMapper>::New();
    renderer = vtkSmartPointer<vtkRenderer>::New();
}

void MainWindow::on__3D_Model_Generate_clicked()
{
    vtkSmartPointer<vtkRendererCollection> list = ui->_3D_Model_Renderer->GetRenderWindow()->GetRenderers(); //get number of renderer
    list->RemoveAllItems(); //remove all renderer to reduce memory
    initialize3D(); // construct all pipeline
    if (mMaxSliderX <= 0){ //check if there are DICOM files in pipeline
        QMessageBox::critical(this, "DRR",
                              "Please open DICOM file before generate 3D",
                              QMessageBox::Ok);
    }
    else {
        if (algorithm ==0){
            surface->SetInputData( readerDCMSeries->GetOutput()); //input the volume to Marching cube
            if (marchingCubesSettings->getMarchingCubes()=="value"){ // if use value
                surface->SetNumberOfContours(4);//set number of contour to 4
                surface->SetValue(0,marchingCubesSettings->getContourValues().at(0)); //contour 1 value
                surface->SetValue(1,marchingCubesSettings->getContourValues().at(1)); //contour 2 value
                surface->SetValue(2,marchingCubesSettings->getContourValues().at(2)); //contour 3 value
                surface->SetValue(3,marchingCubesSettings->getContourValues().at(3)); //contour 4 value
            }
            else { //if use range
                surface->GenerateValues(marchingCubesSettings->getNumberOfContour(),(double)marchingCubesSettings->getMin(),(double)marchingCubesSettings->getMax());
            }
            if (marchingCubesSettings->getColor()){
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
            renderer->SetBackground(.1, .2, .3);
            ui->_3D_Model_Renderer->GetRenderWindow()->AddRenderer(renderer);//add renderer to display window
            //   ui->_3D_Model_Renderer->GetRenderWindow()->Start();
            //   ui->_3D_Model_Renderer->GetRenderWindow()->Finalize();
            ui->_3D_Model_Renderer->GetRenderWindow()->Render();
        }
        else if (algorithm == 1) //Texture mapping 3D
        {
            setVolumePropertyTexture();
            volumeTextureMapper->SetInputData( readerDCMSeries->GetOutput());
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
        else {
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
