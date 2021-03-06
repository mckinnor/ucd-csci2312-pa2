#ifndef CLUSTERING_POINT_H
#define CLUSTERING_POINT_H

#include <iostream>

namespace Clustering {

    class Point {
    private:
        unsigned int __id;
        int __dim;        // number of dimensions of the point
        double *__values; // values of the point's dimensions

        static unsigned int __idGen; // id generator

    public:
        Point(int);
        Point(int, double *);

        // Big three: cpy ctor, overloaded operator=, dtor
        Point(const Point &);
        Point &operator=(const Point &);
        ~Point();

        // Accessors & mutators
        int getId() const{return __id;}
        int getDims() const{return __dim;}
        void setValue(int i, double d){__values[i] = d;}
        double getValue(int i) const{return __values[i];}

        // Functions
        double distanceTo(const Point &) const;

        // Overloaded operators

        // Members
        Point &operator*=(double); // p *= 6; p.operator*=(6);
        Point &operator/=(double);
        const Point operator*(double) const; // prevent (p1 * 2) = p2;
        const Point operator/(double) const; // p3 = p2 / 2;

        double &operator[](int index){return __values[index];}

        // Friends
        friend Point &operator+=(Point &, const Point &);
        friend Point &operator-=(Point &, const Point &);
        friend const Point operator+(const Point &, const Point &);
        friend const Point operator-(const Point &, const Point &);

        friend bool operator==(const Point &, const Point &);
        friend bool operator!=(const Point &, const Point &);

        friend bool operator<(const Point &, const Point &);
        friend bool operator>(const Point &, const Point &);
        friend bool operator<=(const Point &, const Point &);
        friend bool operator>=(const Point &, const Point &);

        friend std::ostream &operator<<(std::ostream &, const Point &);
        friend std::istream &operator>>(std::istream &, Point &);
    };
    Point &operator+=(Point &point, const Point &point1);
    Point &operator-=(Point &point, const Point &point1);
    const Point operator+(const Point &point, const Point &point1);
    const Point operator-(const Point &point, const Point &point1);
    bool operator==(const Point &point, const Point &point1);
    bool operator!=(const Point &point, const Point &point1);
    bool operator<(const Point &point, const Point &point1);
    bool operator>(const Point &point, const Point &point1);
    bool operator<=(const Point &point, const Point &point1);
    bool operator>=(const Point &point, const Point &point1);
    std::ostream &operator<<(std::ostream &ostream1, const Point &point);
    std::istream &operator>>(std::istream &istream1, Point &point);
}
#endif //CLUSTERING_POINT_H
