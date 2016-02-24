//
// Created by Ryan on 2/19/2016.
//
#include <iostream>
#include <cmath>
#include "Point.h"

using namespace std;

Clustering::Point::Point(int i) {
    __id =__idGen++;
    __dim = i;
    *__values = new double[__dim];
    //__values[i];
}

Clustering::Point::Point(int i, double *pDouble) {
    __id = __idGen++;
    __dim = i;
    *__values = pDouble;
}

void Clustering::Point::setValue(int i, double d) {
    //__dim = i;
    *__values[i] = d;
}

Clustering::Point::Point(const Clustering::Point &point) {
    __id = point.__id;
    *__values  = new double[__dim];
    *__values = point.__values[__dim];
}

Clustering::Point &Clustering::Point::operator=(const Clustering::Point &point) {
    Point newPoint(getDims());
    int dim = point.getDims();
    for (int i = 0; i < dim; ++i) {
        newPoint.setValue(i, point.getValue(i));
    }
    return newPoint;
}

Clustering::Point::~Point() {
    __idGen--;
    delete __values;
}

double Clustering::Point::distanceTo(const Clustering::Point &point) const {
    int dim1 = getDims();
    int dim2 = point.getDims();
    double runTotal = 0;

    if(!(dim1>dim2 || dim2>dim1)){
        for(int i = 0; i < dim1; i++){
            runTotal = runTotal + pow((getValue(i) - point.getValue(i)), 2);
        }
        return sqrt(runTotal);
    }
    else if(dim1 > dim2){
        for(int i = 0; i < dim1; i++)
            runTotal = runTotal + pow((getValue(i) - point.getValue(i)), 2);
        return sqrt(runTotal);
    }

    else{
        for(int i = 0; i < dim2; i++)
            runTotal = runTotal + pow((getValue(i) - point.getValue(i)), 2);
        return sqrt(runTotal);
    }
}

Clustering::Point &Clustering::Point::operator*=(double d) {
    Point pointA(getDims());
    for(int i = 0; i < getDims(); i++)
        pointA.setValue(i, getValue(i)*d);

    return pointA;
}


Clustering::Point &Clustering::Point::operator/=(double d) {
    Point pointA(getDims());
    for(int i = 0; i < getDims(); i++)
        pointA / d;

    return pointA;
}

const Clustering::Point Clustering::Point::operator*(double d) const {
    //Point newPoint(getDims());
    Point newPoint(getDims()) = Point;
    newPoint *= d;
    return newPoint;
}

const Clustering::Point Clustering::Point::operator/(double d) const {
    Point newPoint(getDims()) = Point;
    newPoint *= d;
    return  newPoint;
}
