//
// Created by Ryan on 2/19/2016.
//
#include <iostream>
#include <cmath>
#include "Point.h"

using namespace std;
//CONSTRUCTOR
Clustering::Point::Point(int i) {
    __id =__idGen++;
    __dim = i;
    *__values = new double[__dim];
    //__values[i];
}
//2-ARG CONSTRUCTOR
Clustering::Point::Point(int i, double *pDouble) {
    __id = __idGen++;
    __dim = i;
    *__values = pDouble;
}

//COPY CONSTRUCTOR
Clustering::Point::Point(const Clustering::Point &point) {
    __id = point.__id;
    __dim = point.__dim;
    *__values = new double[__dim];
    *__values = point.__values[__dim];
}
//ASSIGNMENT OPERATOR
Clustering::Point &Clustering::Point::operator=(const Clustering::Point &point) {
    Point newPoint(getDims());
    int dim = point.getDims();
    for (int i = 0; i < dim; ++i) {
        newPoint.setValue(i, point.getValue(i));
    }
    return newPoint;
}
//DESTRUCTOR
Clustering::Point::~Point() {
    __idGen--;
    delete __values;
}

void Clustering::Point::setValue(int i, double d) {
    //__dim = i;
    *__values[i] = d;
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

Clustering::Point &Clustering::operator+=(Clustering::Point &point, const Clustering::Point &point1) {
    for(int i = 0; i < point.getDims(); i++){
        point[i] = point[i] + point1.getValue(i);
    }
}

const Clustering::Point Clustering::operator+(const Clustering::Point &point, const Clustering::Point &point1) {
    Point newPoint(point.getDims());
    for (int i = 0; i < newPoint.getDims(); ++i)
        newPoint[i] = point.getValue(i) + point1.getValue(i);
    return newPoint;
}

Clustering::Point &Clustering::operator-=(Clustering::Point &point, const Clustering::Point &point1) {
    for(int i = 0; i < point.getDims(); i++)
        point[i] = point[i] - point1.getValue(i);
}

const Clustering::Point Clustering::operator-(const Clustering::Point &point, const Clustering::Point &point1) {
    Point newPoint(point.getDims());
    for (int i = 0; i < point.getDims(); ++i) {
        newPoint[i] = point.getValue(i) - point1.getValue(i);
    }
    return newPoint;
}

bool Clustering::operator==(const Clustering::Point &point, const Clustering::Point &point1) {
    if(point.getId() == point1.getId()){
        if(point.getDims() == point1.getDims()){
            bool runTruth = true;
            for(int i = 0; i < point.getDims(); i++){
                if(point.getValue(i) != point1.getValue(i)) runTruth = false;
            }
            return runTruth;
        }
        else return false;
    }
    else return false;
}

bool Clustering::operator!=(const Clustering::Point &point, const Clustering::Point &point1) {
    if(point == point1) return false;
    else return true;
}
