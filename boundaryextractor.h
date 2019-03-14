#ifndef BOUNDARYEXTRACTOR_H
#define BOUNDARYEXTRACTOR_H
#include "linefunction.h"
#include "QVector"
#include "QHash"
#include "vtkSmartPointer.h"
#include "vtkImageData.h"
#include "clockwisetrace.h"
#include "QDebug"
#include "QObject"
#include "QThreadPool"
#include "QtConcurrent/QtConcurrent"
#include "QtConcurrent/qtconcurrentrun.h"
#include "QFuture"
#include "QFutureSynchronizer"
#include "QThread"
class BoundaryExtractor: public QObject
{
    Q_OBJECT
    
public:
    BoundaryExtractor(int z, int *imageDims, vtkSmartPointer<vtkImageData> data, ClockWiseTrace *clockWiseSettings);
    QVector<int> getResult();
    bool getStatus();

public slots:    
    void executeBoundary();
    
private:
    vtkSmartPointer<vtkImageData> imageData ;
    int getOffSet(int x, int y, int z, int* dims);
    int* indexTo3D (int index, int* dims);
    QVector<int> getAllIndexFromKDistance(int position, int distance, int startingPoint, int z, int* resultDims);
    double startingAngle(int prevPoint, int currPoint,int* resultDims);
    int checkStartPosition(int prevPoint,int currPoint, int* resultDims);
    int findNextPoint(int distance, int currPoint, int prevPoint, int z, int* resultDims, QVector<int> boundaryDataVector,QVector<int> tempVector,int firstPoint);
    bool isBoundaryPoint(int x, int y ,int z,double lowerValue, double upperValue, int* dims,     QHash<int,double> dataArray);
    int findFirstPoint(int z, QVector<int> boundaryDataVector, QVector<int> blackListVector, int* imageDims);
    QHash<int,double> extractDICOMData(int z, int* imageDims,vtkSmartPointer<vtkImageData> imageData);
    QVector<int> filterVectorByThreshold(double  lower, double upper, int* dims, int z,QHash<int,double> dataArray);
    QVector<int> fillHoleByBenzier(int distance, int z, QVector<int> tempVector,int* resultDims);
    QVector<int> findBoundaryPoint(QVector<int> filterDataVector, int* resultDims,int lowerBound, int upperBound,QHash<int,double> dataArray);
    void printSingleXYZfile(QString filename, QVector<int> data, int *dims);
    QVector<int> clockWiseTrace(int z,int* imageDims,vtkSmartPointer<vtkImageData> imageData, ClockWiseTrace *clockWiseSettings);
    bool isFinish = false;
    QVector<int> finalResult;
    int z;
    int* imageDims;
    vtkSmartPointer<vtkImageData> data;
    ClockWiseTrace *clockWiseSettings ;

};

#endif // BOUNDARYEXTRACTOR_H
