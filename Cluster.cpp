//
// Created by Ryan on 2/19/2016.
//
#include <iostream>
#include "Cluster.h"

using namespace std;

Clustering::LNode LNode(const Clustering::Point &p, Clustering::LNodePtr n) {
    n = NULL;
    //next = n;
}

Clustering::Cluster::Cluster(const Clustering::Cluster &cluster) {

}

Clustering::Cluster &Clustering::Cluster::operator=(const Clustering::Cluster &cluster) {
    //return <#initializer#>;
}

Clustering::Cluster::~Cluster() {

}

int Clustering::Cluster::getSize() const {
    return 0;
}

void Clustering::Cluster::add(const Clustering::Point &point) {

}

const Clustering::Point &Clustering::Cluster::remove(const Clustering::Point &point) {
    //return <#initializer#>;
}

bool Clustering::Cluster::contains(const Clustering::Point &point) {
    return false;
}

const Clustering::Point &Clustering::Cluster::operator[](unsigned int index) const {
    //return <#initializer#>;
}

Clustering::Cluster &Clustering::Cluster::operator+=(const Clustering::Point &point) {
    //return <#initializer#>;
}

Clustering::Cluster &Clustering::Cluster::operator-=(const Clustering::Point &point) {
    //return <#initializer#>;
}

Clustering::Cluster &Clustering::Cluster::operator+=(const Clustering::Cluster &cluster) {
    //return <#initializer#>;
}

Clustering::Cluster &Clustering::Cluster::operator-=(const Clustering::Cluster &cluster) {
    //return <#initializer#>;
}

const Clustering::Cluster Clustering::operator+(const Clustering::Cluster &cluster, const Clustering::Cluster &cluster1) {
    return Clustering::Cluster();
}

const Clustering::Cluster Clustering::operator-(const Clustering::Cluster &cluster, const Clustering::Cluster &cluster1) {
    return Clustering::Cluster();
}
ostream &Clustering::operator<<(ostream &ostream1, const Clustering::Cluster &cluster) {
    //return <#initializer#>;
}

istream &Clustering::operator>>(istream &istream1, Clustering::Cluster &cluster) {
    //return <#initializer#>;
}

bool Clustering::operator==(const Clustering::Cluster &cluster, const Clustering::Cluster &cluster1) {
    return false;
}

bool Clustering::operator!=(const Clustering::Cluster &cluster, const Clustering::Cluster &cluster1) {
    return false;
}

const Clustering::Cluster Clustering::operator+(const Clustering::Cluster &cluster, const Clustering::Point &point) {
    return Clustering::Cluster();
}

const Clustering::Cluster Clustering::operator-(const Clustering::Cluster &cluster, const Clustering::Point &point) {
    return Clustering::Cluster();
}


