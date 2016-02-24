//
// Created by Ryan on 2/19/2016.
//
#include <iostream>
#include "Point.h"

using namespace std;

Clustering::Point::Point(int i) {
    __id =__idGen++;
    __dim = i;
}

Clustering::Point::Point(int i, double *pDouble) {
    __id = __idGen++;
    __dim = i;
    *__values = pDouble;
}

void Clustering::Point::setValue(int i, double d) {
    __dim = i;
    *__values = d;
}

Clustering::Point::Point(const Clustering::Point &point) {
    __id = __idGen++;
    setValue(point.getDims(), point.getValue(__dim));
}

Clustering::Point &Clustering::Point::operator=(const Clustering::Point &point) {

    setValue(point.getDims(), point.getValue(__dim));
   // return <#initializer#>;
}

Clustering::Point::~Point() {
    __idGen--;
    delete __values;
}

double Clustering::Point::distanceTo(const Clustering::Point &point) const {
    int dim1 = getDims();
    int dim2 = point.getDims();

    if(!(dim1>dim2 || dim2>dim1)){

    }
}
