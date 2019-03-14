#include "boundaryextractor.h"
#include "QFile"

#define _USE_MATH_DEFINES
#include "math.h"
BoundaryExtractor::BoundaryExtractor(int z,int* imageDims,vtkSmartPointer<vtkImageData> data, ClockWiseTrace *clockWiseSettings )
{
    this->imageData = data;
    this->z = z;
    this->imageDims = imageDims;
    this->clockWiseSettings = clockWiseSettings;
}

int BoundaryExtractor::getOffSet(int x, int y, int z, int* dims){
    int offset = x + y * dims[1] + z * dims[1] * dims[0];
    return offset;
}
int* BoundaryExtractor::indexTo3D (int index, int* dims){
    int* result = new int[3];
    int z = index /(dims[0]*dims[1]);
    index -= (z * dims[0] * dims[1]);
    int y = index / dims[0];
    int x = index % dims[0];
    result[0] = x;
    result[1] = y;
    result[2] = z;
    return result;
}
/*
double BoundaryExtractor::bilinearInterpolation(double q11, double q12, double q21, double q22, double x1, double x2, double y1, double y2, double x, double y)
{
    double x2x1, y2y1, x2x, y2y, yy1, xx1;
    x2x1 = x2 - x1;
    y2y1 = y2 - y1;
    x2x = x2 - x;
    y2y = y2 - y;
    yy1 = y - y1;
    xx1 = x - x1;
    return 1.0 / (x2x1 * y2y1) * (
                q11 * x2x * y2y +
                q21 * xx1 * y2y +
                q12 * x2x * yy1 +
                q22 * xx1 * yy1
                );
}
*/
QVector<int> BoundaryExtractor::getAllIndexFromKDistance(int position, int distance, int startingPoint, int z, int* resultDims){
    QVector<int> resultArray ;
    QVector<int> topLeft ;
    QVector<int> topRight ;
    QVector<int> bottomLeft ;
    QVector<int> bottomRight;
    int* location = indexTo3D(position,resultDims);
    int x = location[0];
    int y = location[1];
    int width = resultDims[0];
    int height = resultDims[0];
    int result = 0;
    int tempX;
    int tempY;
    int i;
    /*
     Case 1: Top Left
    */
    tempX = x - distance;
    for ( i = 0; i <= distance; i++){
        tempY = y - i;
        if (tempX >= 0 && tempX < width && tempY >= 0 && tempY < height ){
            result = getOffSet(tempX,tempY,z,resultDims);
            topLeft.append(result);
        }
    }
    tempY = y - distance;
    for ( i = (distance - 1); i > 0; i--){
        tempX = x - i;
        if (tempX >= 0 && tempX < width && tempY >= 0 && tempY < height ){
            result = getOffSet(tempX,tempY,z,resultDims);
            topLeft.append(result);
        }
    }
    /*
    Case 2: Top Right
    */
    tempY = y - distance;
    for ( i = 0 ; i <= distance; i++){
        tempX = x + i;
        if (tempX >= 0 && tempX < width && tempY >= 0 && tempY < height ){
            result = getOffSet(tempX,tempY,z,resultDims);
            topRight.append(result);
        }
    }
    tempX = x + distance;
    for ( i = (distance - 1); i > 0; i--){
        tempY = y - i;
        if (tempX >= 0 && tempX < width && tempY >= 0 && tempY < height ){
            result = getOffSet(tempX,tempY,z,resultDims);
            topRight.append(result);
        }
    }
    /*
    Case 3: Bottom Right
    */
    tempX = x + distance;
    for ( i = 0 ; i <= distance; i++ ){
        tempY = y + i;
        if (tempX >= 0 && tempX < width && tempY >= 0 && tempY < height ){
            result = getOffSet(tempX,tempY,z,resultDims);
            bottomRight.append(result);
        }
    }
    tempY = y + distance;
    for ( i = (distance - 1) ; i > 0; i-- ){
        tempX = x + i;
        if (tempX >= 0 && tempX < width && tempY >= 0 && tempY < height ){
            result = getOffSet(tempX,tempY,z,resultDims);
            bottomRight.append(result);
        }
    }

    /*
    Case 4: Bottom Left
    */
    tempY = y + distance;
    for ( i = 0; i <= distance ; i++ ){
        tempX = x - i;
        if (tempX >= 0 && tempX < width && tempY >= 0 && tempY < height ){
            result = getOffSet(tempX,tempY,z,resultDims);
            bottomLeft.append(result);
        }
    }
    tempX = x - distance;
    for ( i = (distance - 1 ); i > 0 ; i-- ){
        tempY = y + i;
        if (tempX >= 0 && tempX < width && tempY >= 0 && tempY < height ){
            result = getOffSet(tempX,tempY,z,resultDims);
            bottomLeft.append(result);
        }
    }
    switch (startingPoint){
    case 1:
        resultArray.append(bottomLeft);
        resultArray.append(topLeft);
        resultArray.append(topRight);
        resultArray.append(bottomRight);
        break;
    case 3:
        resultArray.append(topLeft);
        resultArray.append(topRight);
        resultArray.append(bottomRight);
        resultArray.append(bottomLeft);
        break;
    case 7:
        resultArray.append(topRight);
        resultArray.append(bottomRight);
        resultArray.append(bottomLeft);
        resultArray.append(topLeft);
        break;
    case 5:
        resultArray.append(bottomRight);
        resultArray.append(bottomLeft);
        resultArray.append(topLeft);
        resultArray.append(topRight);
        break;
    }
    delete []location;
    return resultArray;
}
double BoundaryExtractor::startingAngle(int prevPoint, int currPoint,int* resultDims){
    double angle = 0;
    if (prevPoint == 0){
        return angle = 90;
    }
    int* prevLocation = indexTo3D(prevPoint,resultDims);
    int* currLocation = indexTo3D(currPoint,resultDims);
    angle =  atan2(prevLocation[1] - currLocation[1], prevLocation[0] - currLocation[0])* 180 / M_PI;
    delete []prevLocation;
    delete []currLocation;
    return angle;
}

int BoundaryExtractor::checkStartPosition(int prevPoint,int currPoint, int* resultDims){
    int* currPosition = indexTo3D(currPoint,resultDims);
    int* prevPosition = indexTo3D(prevPoint,resultDims);
    int prevX = prevPosition[0];
    int currX = currPosition[0];
    int prevY = prevPosition[1];
    int currY = currPosition[1];
    if (prevPoint == 0){
        delete []currPosition;
        delete []prevPosition;
        return 1;
    }
    else if (prevX == currX && prevY > currY){
        delete []currPosition;
        delete []prevPosition;
        return 0;
    }
    else if (prevX == currX && prevY < currY){
        delete []currPosition;
        delete []prevPosition;
        return 1;
    }
    else if (prevX > currX){
        delete []currPosition;
        delete []prevPosition;
        return 1;
    }
    else{
        delete []currPosition;
        delete []prevPosition;
        return 0;
    }
}
int BoundaryExtractor::findNextPoint(int distance, int currPoint, int prevPoint, int z, int* resultDims, QVector<int> boundaryDataVector,QVector<int> tempVector,int firstPoint){
    lineFunction line;
    double angle;
    double stepAngle = 0.5;
    int* currPointLocation = indexTo3D(currPoint,resultDims);
    int* prevPointLocation = indexTo3D(prevPoint,resultDims);
    int position;
    int nextPointX;
    int nextPointY;
    int currentX = currPointLocation[0];
    int currentY = currPointLocation[1];
    int prevX = prevPointLocation[0];
    int prevY = prevPointLocation[1];
    int nextPoint;
    bool isPass;
    int i;
    int k;
    int vectorIndex;
    QVector<int> allIndexFromKDistance;
    if (prevX == currentX){
        if (prevY < currentY)
            angle = -90;
        else
            angle = 90;
    }
    else
    {
        angle = startingAngle(prevPoint,currPoint, resultDims);
    }
    if (prevPoint == 0){
        angle = 89.5;
    }
    position = checkStartPosition(prevPoint,currPoint,resultDims);
    for ( i = 0; i < 720; i++)
    {
        angle = angle + stepAngle;
        if (angle == -90 || angle == 90 || angle == 270 || angle == -270 || angle == 450  || angle == 630)
        {
            for ( k = 1 ; k <= distance; k++)
            {
                if (position == 0)
                {
                    nextPointX = currPointLocation[0];
                    nextPointY = currPointLocation[1] - k;
                    nextPoint = getOffSet(nextPointX,nextPointY,currPointLocation[2],resultDims);
                }
                else {
                    nextPointX = currPointLocation[0];
                    nextPointY = currPointLocation[1] + k;
                    nextPoint = getOffSet(nextPointX,nextPointY,currPointLocation[2],resultDims);
                }
                if (boundaryDataVector.contains(nextPoint))
                {
                    if (nextPoint == firstPoint)
                    {
                        delete []currPointLocation;
                        delete []prevPointLocation;
                        return -1;
                    }
                    else if(!tempVector.contains(nextPoint)){
                        // qDebug() <<"Return point x: \t" << nextPointX << "\t y: \t" << nextPointY;
                        delete []currPointLocation;
                        delete []prevPointLocation;
                        return nextPoint;
                    }
                }
            }
            if (position == 0){
                position = 1;
            }
            else {
                position = 0;
            }
        }
        else
        {
            line.setNewValue(angle,currPointLocation[0],currPointLocation[1]);
            for ( k = 1 ; k <= distance; k++)
            {
                allIndexFromKDistance = getAllIndexFromKDistance(currPoint,k,1,z,resultDims);
                for (vectorIndex = 0 ; vectorIndex < allIndexFromKDistance.size();vectorIndex++)
                {
                    nextPoint = allIndexFromKDistance.at(vectorIndex);
                    int* nextPointLocation = indexTo3D(nextPoint,resultDims);
                    isPass = line.isPassThroughPoint(nextPointLocation[0], nextPointLocation[1]);
                    nextPointX = nextPointLocation[0];
                    if (position == 0)
                    {
                        if (isPass && boundaryDataVector.contains(nextPoint) && nextPointX < currPointLocation[0])
                        {
                            if (nextPoint == firstPoint)
                            {
                                delete []currPointLocation;
                                delete []prevPointLocation;
                                delete []nextPointLocation;
                                return -1;
                            }
                            else if(!tempVector.contains(nextPoint)){
                                //   qDebug() <<"Return point x: \t" << nextPointX << "\t y: \t" << nextPointY;
                                delete []currPointLocation;
                                delete []prevPointLocation;
                                delete []nextPointLocation;
                                return nextPoint;
                            }
                        }
                    }
                    else {
                        if (isPass && boundaryDataVector.contains(nextPoint) && nextPointX  > currPointLocation[0])
                        {
                            if (nextPoint == firstPoint)
                            {
                                delete []currPointLocation;
                                delete []prevPointLocation;
                                delete []nextPointLocation;
                                return -1;
                            }
                            else if(!tempVector.contains(nextPoint)){
                                //   qDebug() <<"Return point x: \t" << nextPointX << "\t y: \t" << nextPointY;
                                delete []currPointLocation;
                                delete []prevPointLocation;
                                delete []nextPointLocation;
                                return nextPoint;
                            }
                        }
                    }
                    delete []nextPointLocation;
                }
            }
        }
    }
    // qDebug() << "Can't find next point at distance" << distance;
    delete []currPointLocation;
    delete []prevPointLocation;
    return -2;
}
bool BoundaryExtractor::isBoundaryPoint(int x, int y ,int z,double lowerValue, double upperValue, int* dims,     QHash<int,double> dataArray){
    int x1 = x + 1;
    int x2 = x - 1 ;
    int y1 = y + 1;
    int y2 = y -1 ;
    bool isValid = false;
    int tempIndex = 0;
    if (x1 < dims[0] && x2 >= 0 && y1 < dims[1] && y2 >= 0){
        tempIndex = getOffSet(x2,y1,z,dims);
        if (  dataArray.value(tempIndex) <= lowerValue ||   dataArray.value(tempIndex) >= upperValue)
        {   isValid = true;
            return isValid;

        }
    }
    if (x1 < dims[0] && x2 >= 0 && y1 < dims[1] && y2 >= 0){
        tempIndex = getOffSet(x2,y,z,dims);
        if (  dataArray.value(tempIndex) <= lowerValue ||   dataArray.value(tempIndex) >= upperValue)
        {   isValid = true;
            return isValid;
        }
    }
    if (x1 < dims[0] && x2 >= 0 && y1 < dims[1] && y2 >= 0){
        tempIndex = getOffSet(x2,y2,z,dims);
        if (  dataArray.value(tempIndex) <= lowerValue ||   dataArray.value(tempIndex) >= upperValue)
        {   isValid = true;
            return isValid;
        }
    }
    if (x1 < dims[0] && x2 >= 0 && y1 < dims[1] && y2 >= 0){
        tempIndex = getOffSet(x,y2,z,dims);
        if (  dataArray.value(tempIndex) <= lowerValue ||   dataArray.value(tempIndex) >= upperValue)
        {   isValid = true;
            return isValid;
        }
    }
    if (x1 < dims[0] && x2 >= 0 && y1 < dims[1] && y2 >= 0){
        tempIndex = getOffSet(x,y1,z,dims);
        if (  dataArray.value(tempIndex) <= lowerValue ||   dataArray.value(tempIndex) >= upperValue)
        {   isValid = true;
            return isValid;
        }
    }
    if (x1 < dims[0] && x2 >= 0 && y1 < dims[1] && y2 >= 0){
        tempIndex = getOffSet(x1,y,z,dims);
        if (  dataArray.value(tempIndex) <= lowerValue ||   dataArray.value(tempIndex) >= upperValue)
        {   isValid = true;
            return isValid;
        }
    }
    if (x1 < dims[0] && x2 >= 0 && y1 < dims[1] && y2 >= 0){
        tempIndex = getOffSet(x1,y1,z,dims);
        if (  dataArray.value(tempIndex) <= lowerValue ||   dataArray.value(tempIndex) >= upperValue)
        {   isValid = true;
            return isValid;
        }
    }
    if (x1 < dims[0] && x2 >= 0 && y1 < dims[1] && y2 >= 0){
        tempIndex = getOffSet(x1,y2,z,dims);
        if (  dataArray.value(tempIndex) <= lowerValue ||   dataArray.value(tempIndex) >= upperValue)
        {   isValid = true;
            return isValid;
        }
    }
    return isValid;
}

int BoundaryExtractor::findFirstPoint(int z, QVector<int> boundaryDataVector, QVector<int> blackListVector, int* imageDims){
    int index;
    int y;
    int x;
    for (y  = imageDims[1] - 1 ; y >= 0  ;y--)
    {
        for ( x = 0; x < imageDims[0]; x++)
        {
            index = getOffSet(x,y,z,imageDims);
            if (boundaryDataVector.contains(index) && !blackListVector.contains(index))
            {
                return index;
            }
        }
    }
    return -2;
}

QHash<int,double> BoundaryExtractor::extractDICOMData(int z, int* imageDims,vtkSmartPointer<vtkImageData> imageData){
    qDebug() <<"Extract DICOM data for slice z" << z ;
    QHash<int,double> dataArray   ;
    double temp;
    int index;
    int y;
    int x;
    for (y = imageDims[1] - 1; y >=0  ;y--){
        for (x = 0; x < imageDims[0]; x++){
            index = getOffSet(x,y,z,imageDims);
            temp = imageData->GetScalarComponentAsDouble(x,y,z,0);
            dataArray.insert(index,temp);
        }
    }
    //  qDebug() << "Size" << dataArray.size();
    return dataArray;
}
QVector<int> BoundaryExtractor::filterVectorByThreshold(double  lower, double upper, int* dims, int z,QHash<int,double> dataArray){
    QVector<int> filterDataVector;
    int y;
    int x;
    for ( y = dims[1] - 1; y >=0 ; y--)
    {
        for ( x = 0; x < dims[0]; x++)
        {
            int tempIndex = getOffSet(x,y,z,dims);
            if ( dataArray.value(tempIndex) <= upper && dataArray.value(tempIndex) >= lower)
            {
                filterDataVector.append(tempIndex);
            }
        }
    }
    return filterDataVector;
    // qDebug() << "Size of filterDataVector" << filterDataVector.size();
}

QVector<int> BoundaryExtractor::fillHoleByBenzier(int distance, int z, QVector<int> tempVector,int* resultDims){
    QVector<int> _fillVector;
    QVector<int> _tempVector = tempVector;
    double x;
    double y;
    int index;
    int i;
    double t;
    if (distance >  1)
    {
        for (i = 0; i < tempVector.size(); i++)
        {
            if (i == 0){
                int* p0Location = indexTo3D(tempVector.at(tempVector.size() - 1), resultDims);
                int* p1Location = indexTo3D(tempVector.at(i),resultDims);
                int* p2Location = indexTo3D(tempVector.at(i+1), resultDims);
                int x0 = p0Location[0];
                int x1 = p1Location[0];
                int x2 = p2Location[0];
                int y0 = p0Location[1];
                int y1 = p1Location[1];
                int y2 = p2Location[1];
                for (t = 0; t <=1; t+=0.05)
                {
                    x = (1-t)*(1-t)*x0 + 2*(1-t)*t*x1 + t*t*x2;
                    y = (1-t)*(1-t)*y0 + 2*(1-t)*t*y1 + t*t*y2;
                    index = getOffSet(round(x),round(y),z,resultDims);
                    if (!_tempVector.contains(index) && !_fillVector.contains(index))
                    {
                        _fillVector.append(index);
                    }
                }
                delete[] p0Location;
                delete[] p1Location;
                delete[] p2Location;

            }
            else if (i == tempVector.size() - 1)
            {
                int* p0Location = indexTo3D(tempVector.at(i-1), resultDims);
                int* p1Location = indexTo3D(tempVector.at(i),resultDims);
                int* p2Location = indexTo3D(tempVector.at(0), resultDims);
                int x0 = p0Location[0];
                int x1 = p1Location[0];
                int x2 = p2Location[0];
                int y0 = p0Location[1];
                int y1 = p1Location[1];
                int y2 = p2Location[1];
                for (t = 0; t <=1; t+=0.1)
                {
                    x = (1-t)*(1-t)*x0 + 2*(1-t)*t*x1 + t*t*x2;
                    y = (1-t)*(1-t)*y0 + 2*(1-t)*t*y1 + t*t*y2;
                    index = getOffSet(round(x),round(y),z,resultDims);
                    if (!_tempVector.contains(index) && !_fillVector.contains(index))
                    {
                        _fillVector.append(index);
                    }
                }
                delete[] p0Location;
                delete[] p1Location;
                delete[] p2Location;
            }
            else
            {
                int* p0Location = indexTo3D(tempVector.at(i-1), resultDims);
                int* p1Location = indexTo3D(tempVector.at(i),resultDims);
                int* p2Location = indexTo3D(tempVector.at(i+1), resultDims);
                int x0 = p0Location[0];
                int x1 = p1Location[0];
                int x2 = p2Location[0];
                int y0 = p0Location[1];
                int y1 = p1Location[1];
                int y2 = p2Location[1];
                for (t = 0; t <=1; t+=0.1)
                {
                    x = (1-t)*(1-t)*x0 + 2*(1-t)*t*x1 + t*t*x2;
                    y = (1-t)*(1-t)*y0 + 2*(1-t)*t*y1 + t*t*y2;
                    index = getOffSet(round(x),round(y),z,resultDims);
                    if (!_tempVector.contains(index) && !_fillVector.contains(index))
                    {
                        _fillVector.append(index);
                    }
                }
                delete[] p0Location;
                delete[] p1Location;
                delete[] p2Location;
            }
        }
        if (_fillVector.size()>0)
        {
            tempVector.append(_fillVector);
        }
        _fillVector.clear();
        return _tempVector;
    }
    else
        return _tempVector;
}
QVector<int> BoundaryExtractor::findBoundaryPoint(QVector<int> filterDataVector, int* resultDims,int lowerBound, int upperBound,QHash<int,double> dataArray){
    QVector<int> boundaryDataVector;
    int filterDataIndex;
    int x;
    int y;
    int z;
    int i;
    for (i = 0; i < filterDataVector.size(); i++)
    {
        filterDataIndex = filterDataVector.at(i);
        int* filterDataLocation = indexTo3D(filterDataIndex,resultDims);
        x = filterDataLocation[0];
        y = filterDataLocation[1];
        z = filterDataLocation[2];
        bool isBoundary = isBoundaryPoint(x,y,z,lowerBound,upperBound,resultDims,dataArray);
        if (isBoundary){
            boundaryDataVector.append(filterDataIndex);
        }
        delete []filterDataLocation;
    }
    //qDebug() << "Size of boundary point" << boundaryDataVector.size();
    return boundaryDataVector;
}
void BoundaryExtractor::printSingleXYZfile(QString filename, QVector<int> data, int *dims){
    QString filename2 = filename;
    QFile file2( filename2 );
    double localX;
    double localY;
    int i;
    double localZ;
    if ( file2.open(QIODevice::ReadWrite | QIODevice::Text) )
    {
        QTextStream stream( &file2 );
        for (i = 0; i < data.size() ; i++)
        {
            int* location = indexTo3D(data.value(i),dims);
            localX = location[0] ;
            localY= location[1] ;
            localZ = location[2] ;
            stream << localX << ' ';
            stream << localY << ' ';
            stream << localZ << ' ';
            stream << '\n';
            delete []location;
        }
    }
}
QVector<int> BoundaryExtractor::clockWiseTrace(int z,int* imageDims,vtkSmartPointer<vtkImageData> imageData, ClockWiseTrace *clockWiseSettings){
    bool isRunning = true;
    bool isFirstPoint = true;
    int firstPoint;
    int currPoint;
    int prevPoint;
    int nextPoint;
    int defaultDistance = 1;
    int distance = defaultDistance;
    int maxDistance = clockWiseSettings->maxDistance;
    int countRetry = 0;
    int numberOfRetry = clockWiseSettings->retryTimes;
    int requiredPoint = clockWiseSettings->points;
    double _lowerBound = clockWiseSettings->lower;
    double _upperBound = clockWiseSettings->upper;
    double _stepBound = clockWiseSettings->step;
    QVector<int> _blackListVector;
    QVector<int> _tempVector;
    QHash<int,double> dataArray = extractDICOMData(z,imageDims,imageData);
    QVector<int> _filterDataVector = filterVectorByThreshold(_lowerBound,_upperBound,imageDims,z,dataArray);
    QVector<int> _boundaryDataVector = findBoundaryPoint(_filterDataVector,imageDims,_lowerBound,_upperBound,dataArray);
    while(isRunning){
        if (isFirstPoint) // check if we first start the rotation
        {
            currPoint = findFirstPoint(z,_boundaryDataVector,_blackListVector,imageDims); // find the first point to start rotating
            firstPoint = currPoint;
            _tempVector.append(firstPoint);
            nextPoint = findNextPoint(distance,currPoint,0,z,imageDims,_boundaryDataVector,_tempVector,firstPoint); // find next point with previous point is first point
            isFirstPoint = false;
        }
        else
        {
            nextPoint = findNextPoint(distance,currPoint,prevPoint,z,imageDims,_boundaryDataVector,_tempVector,firstPoint); // find
        }
        if (nextPoint >= 0) // sucessfully get the next point
        {
            _tempVector.append(nextPoint); //assign to point list
            prevPoint = currPoint;
            currPoint = nextPoint;
        }
        if (nextPoint == -1) // meet the ending requirement which is first point == next point
        {
            if (_tempVector.size() < requiredPoint) // if required points is not met, retry the algorithm
            {
                if(countRetry >= numberOfRetry) // if excess the retry time, return fail
                {
                    distance++;
                    isFirstPoint = true;
                    _tempVector.clear();
                    _blackListVector.clear();
                    countRetry = 0;
                }
                else // restart the algorithm
                {   countRetry++;
                    isFirstPoint = true;
                    _tempVector.clear();
                    _blackListVector.append(firstPoint); // add the first point the blacklist so we can exlude this point next retry
                }
            }
            else // if we sucessfully find the boundary, fill the missing points
            {
                _tempVector = fillHoleByBenzier(distance,z,_tempVector,imageDims);
                return _tempVector;
            }
        }
        if (nextPoint == -2) // can not find the next point, retry the algorithm
        {
            if(countRetry >= numberOfRetry)
            {
                distance++;
                isFirstPoint = true;
                _tempVector.clear();
                _blackListVector.clear();
                countRetry = 0;
            }
            else
            {
                countRetry++;
                isFirstPoint = true;
                _tempVector.clear();
                _blackListVector.append(firstPoint);
            }
        }
        if (distance > maxDistance)
        {
            if (_lowerBound > _upperBound)
            {
                qDebug() << "Can't extract external boundary of slice: " << z;
                QString filterName = "filterDataVector";
                filterName.append(z);
                filterName.append(".xyz");
                QString boundaryName = "boundaryDataVector";
                boundaryName.append(z);
                boundaryName.append(".xyz");
                // printSingleXYZfile(filterName,_filterDataVector,imageDims);
                //printSingleXYZfile(boundaryName,_boundaryDataVector,imageDims);
                return _tempVector;
            }
            else
            {
                _lowerBound = _lowerBound + _stepBound;
                distance = defaultDistance;
                isFirstPoint = true;
                countRetry = 0;
                _tempVector.clear();
                _blackListVector.clear();
                _filterDataVector.clear();
                _boundaryDataVector.clear();
                //qDebug() << "Increase lowerBound by :"<< _stepBound <<" to: " << _lowerBound;
                _filterDataVector = filterVectorByThreshold(_lowerBound,_upperBound,imageDims,z,dataArray);
                _boundaryDataVector = findBoundaryPoint(_filterDataVector,imageDims,_lowerBound,_upperBound,dataArray);
            }
        }
    }
}
QVector<int> BoundaryExtractor::getResult(){
    if (isFinish)
        return finalResult;
}
bool BoundaryExtractor::getStatus(){
    return isFinish;
}

void BoundaryExtractor::executeBoundary(){
    qDebug() << "receive signal from slice " << z;
    qDebug() << "move object to thread" << QThread::currentThreadId();
   // auto f1 = QtConcurrent::run(QThreadPool::globalInstance(),clockWiseTrace,z,imageDims,imageData,clockWiseSettings);
    finalResult = clockWiseTrace(z,imageDims,imageData,clockWiseSettings);
    isFinish = true;
}
