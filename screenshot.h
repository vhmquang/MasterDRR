#ifndef SCREENSHOT_H
#define SCREENSHOT_H
#include <QPixmap>
#include <vtkWindowToImageFilter.h>
#include <vtkPNGWriter.h>
#include <vtkSmartPointer.h>
#include <vtkWindow.h>
#include <QWidget>
class ScreenShot: public QWidget
{
    Q_OBJECT
public:
    void doScreenShot(vtkWindow *renWin);
    void SaveShot(std::string name);
    void TakeShot(vtkWindow *renWin);
private:
     vtkSmartPointer<vtkWindowToImageFilter> windowToImageFilter ;
     vtkSmartPointer<vtkPNGWriter> writer ;
};

#endif // SCREENSHOT_H
