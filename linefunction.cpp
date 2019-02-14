#include "linefunction.h"
#define _USE_MATH_DEFINES
#include "math.h"
lineFunction::lineFunction(){
}
double lineFunction::getSlope(double angle){
    double x = tan(angle);
    return x;
}
double lineFunction::getConstant(int x, int y){
    double tempY;
    tempY = y - (slope * x);
    return tempY;
}
bool lineFunction::isPassThroughPoint(int x, int y){
    double tempY;
     tempY = (slope * x) + constant;
    if ((fabs(tempY - y) < 0.0000001)|| tempY == y){
        return true;
    }
    else return false;
}
void lineFunction::setNewValue(double angle, int x, int y){
    slope = lineFunction::getSlope(angle*(M_PI)/180);
    constant = lineFunction::getConstant(x,y);
}
