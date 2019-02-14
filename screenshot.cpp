#include "screenshot.h"
#include <QScreen>
#include <QGuiApplication>
#include <QWindow>
#include <QStandardPaths>
#include <QFileDialog>

void ScreenShot::doScreenShot(vtkWindow *renWin)
{
       TakeShot(renWin);
       QString format = "png";
       QString initialPath = QStandardPaths::writableLocation(QStandardPaths::PicturesLocation);
       if (initialPath.isEmpty())
           initialPath = QDir::currentPath();
       initialPath += "/untitled." + format;

       QFileDialog fileDialog(this, "Save As", initialPath,"Portable Network Graphics (*.png)");
       fileDialog.setAcceptMode(QFileDialog::AcceptSave);
       fileDialog.setFileMode(QFileDialog::AnyFile);
       fileDialog.setDirectory(initialPath);
       fileDialog.setDefaultSuffix(".png");
       if (fileDialog.exec() == QDialog::Accepted){
       std::string fileName = fileDialog.selectedFiles().first().toUtf8().constData();
       SaveShot(fileName);
       }

}
void ScreenShot::SaveShot(std::string fileName){
    writer = vtkSmartPointer<vtkPNGWriter>::New();
    writer->SetFileName(fileName.c_str());
    writer->SetInputConnection(windowToImageFilter->GetOutputPort());
    writer->Write();
}
void ScreenShot::TakeShot(vtkWindow *renWin){
    windowToImageFilter = vtkSmartPointer<vtkWindowToImageFilter>::New();
     windowToImageFilter->Modified();
     windowToImageFilter->SetInput(renWin);
     windowToImageFilter->SetInputBufferTypeToRGBA(); //also record the alpha (transparency) channel
     windowToImageFilter->ReadFrontBufferOff(); // read from the back buffer
     windowToImageFilter->Update();
}
