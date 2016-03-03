//
// Created by Ryan on 2/19/2016.
//
#include <iostream>
#include <cmath>
#include <sstream>
#include "Point.h"

using namespace std;
int unsigned Clustering::Point::__idGen = 0;
//CONSTRUCTOR
Clustering::Point::Point(int i) {
    __id =__idGen++;
    __dim = i;
    __values = new double[__dim];
    for(int k = 0; k < __dim; k++)
        __values[k] = 0.0;
}
//2-ARG CONSTRUCTOR
Clustering::Point::Point(int i, double *pDouble) {
    __id = __idGen++;
    __dim = i;
    __values = pDouble;
}

//COPY CONSTRUCTOR
Clustering::Point::Point(const Clustering::Point &point) {
    ++__idGen;
    __id = point.__id;
    __dim = point.__dim;
    __values = new double[__dim];
    for (int i = 0; i < __dim; ++i) {
        __values[i] = point.__values[i];
    }
    //__values = point.__values;
}
//ASSIGNMENT OPERATOR
Clustering::Point &Clustering::Point::operator=(const Clustering::Point &point) {
    __dim = point.__dim;
    __id = point.__id;
    for (int i = 0; i < __dim; ++i) {
        __values[i] = point.__values[i];
    }
    return *this;
}
//DESTRUCTOR
Clustering::Point::~Point() {
    --__idGen;
    delete[] __values;
    __values = nullptr;
}

/*void Clustering::Point::setValue(int i, double d) {
    __values[i] = d;
}*/

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
    for(int i = 0; i < __dim; i++)
        __values[i] = __values[i] * d;
    return *this;
}


Clustering::Point &Clustering::Point::operator/=(double d) {
    for(int i = 0; i < __dim; i++)
        __values[i] = __values[i] / d;
    return *this;
}

const Clustering::Point Clustering::Point::operator*(double d) const {
    Point newPoint(__dim);
    newPoint.__values = __values;
    newPoint *= d;
    return newPoint;
}

const Clustering::Point Clustering::Point::operator/(double d) const {
    Point newPoint(__dim);
    newPoint.__values = __values;
    newPoint *= d;
    return  newPoint;
}
//FRIEND FUNCTIONS
Clustering::Point &Clustering::operator+=(Clustering::Point &point, const Clustering::Point &point1) {
    for(int i = 0; i < point.getDims(); i++){
        point[i] = point[i] + point1.getValue(i);
    }
    return point;
}

const Clustering::Point Clustering::operator+(const Clustering::Point &point, const Clustering::Point &point1) {
    Point newPoint(point.getDims());
    newPoint += point;
    newPoint += point1;
    return newPoint;
}

Clustering::Point &Clustering::operator-=(Clustering::Point &point, const Clustering::Point &point1) {
    for(int i = 0; i < point.getDims(); i++)
        point[i] = point[i] - point1.getValue(i);
    return point;
}

const Clustering::Point Clustering::operator-(const Clustering::Point &point, const Clustering::Point &point1) {
    Point newPoint(point);
    newPoint -= point1;
    return newPoint;
}

bool Clustering::operator==(const Clustering::Point &point, const Clustering::Point &point1) {
    if(point.getId() == point1.getId()) {
        if (point.getDims() == point1.getDims()) {
            for (int i = 0; i < point.getDims(); i++)
                if (point.__values[i] != point1.__values[i]) return false;
            return true;
        }
        else return false;
    }
    else return false;
}

bool Clustering::operator!=(const Clustering::Point &point, const Clustering::Point &point1) {
    return !(point == point1);
}

bool Clustering::operator<(const Clustering::Point &point, const Clustering::Point &point1) {
    for(int i = 0; i < point.getDims(); i++){
        if(point.getValue(i) != point1.getValue(i)){
            if(point.getValue(i) < point1.getValue(i)) return true;
            else return false;
        }
    }
    return false;
}

bool Clustering::operator>(const Clustering::Point &point, const Clustering::Point &point1) {
    return !(point < point1);
}

bool Clustering::operator<=(const Clustering::Point &point, const Clustering::Point &point1) {
    return ((point == point1)||(point < point1));
}

bool Clustering::operator>=(const Clustering::Point &point, const Clustering::Point &point1) {
    return ((point > point1) || (point == point1));
}

std::ostream &Clustering::operator<<(ostream &ostream1, const Clustering::Point &point) {
    for(int i = 0; i < point.getDims(); i++){
        ostream1 << point.getValue(i) << ", ";
    }
    ostream1 << endl;
    return ostream1;
}

std::istream &Clustering::operator>>(istream &istream1, Clustering::Point &point) {
    int i =0;
    double temp;
    while(istream1 >> temp){
        point.__values[i] = temp;
        if(istream1.peek() == ',') istream1.ignore();
        i++;
    }
}
