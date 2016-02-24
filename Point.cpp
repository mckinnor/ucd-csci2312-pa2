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
    //__values[i];
}

Clustering::Point::Point(int i, double *pDouble) {
    __id = __idGen++;
    __dim = i;
    __values[i] = pDouble;
}

void Clustering::Point::setValue(int i, double d) {
    //__dim = i;
    *__values[i] = d;
}

Clustering::Point::Point(const Clustering::Point &point) {
    __id = __idGen++;
    setValue(point.getDims(), point.getValue(__dim));
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
            runTotal = runTotal + pow(2, (getValue(i)-point.getValue(i)));
        }
        return sqrt(runTotal);
    }
    else if(dim1 > dim2){
        for(int i = 0; i < dim1; i++)
            runTotal = runTotal + pow(2, (getValue(i) - point.getValue(i)));
        return sqrt(runTotal);
    }

    else{
        for(int i = 0; i < dim2; i++)
            runTotal = runTotal + pow(2, (getValue(i) - point.getValue(i)));
        return sqrt(runTotal);
    }
}

