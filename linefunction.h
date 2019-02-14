#ifndef LINEFUNCTION_H
#define LINEFUNCTION_H


class lineFunction
{
public:
    lineFunction();
    void setNewValue(double angle, int x, int y);
    double getSlope(double angle);
    double getConstant(int x, int y);
    bool isPassThroughPoint(int x, int y);

public:
    double slope;
    double constant;
};

#endif // LINEFUNCTION_H
