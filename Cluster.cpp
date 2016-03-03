//
// Created by Ryan on 2/19/2016.
//
#include <iostream>
#include <sstream>
#include "Cluster.h"

using namespace std;


Clustering::LNode::LNode(const Clustering::Point &p, Clustering::LNodePtr n):point(p) {
    next = n;
}

Clustering::Cluster::Cluster(const Clustering::Cluster &cluster) {
    __size = cluster.__size;
    __points = cluster.__points;
}

Clustering::Cluster &Clustering::Cluster::operator=(const Clustering::Cluster &cluster) {
    __size = cluster.__size;
    __points = cluster.__points;
}

Clustering::Cluster::~Cluster() {

}

void Clustering::Cluster::add(const Clustering::Point &point) {
    Point p(point);
    LNodePtr curr = __points;
    if(curr == nullptr)
        __points = new LNode(p, nullptr);
    else if(p <= curr->point)
        __points = new LNode(p, curr);
    /*else if(p > curr->point)
        */
    else{
        LNodePtr prev = curr;
        if(curr->next != nullptr) {
            curr = curr->next;
            while (curr->next != nullptr && p >= curr->point) {
                prev = curr;
                curr = curr->next;
            }
        }
        if(curr->next == nullptr) curr->next = new LNode(p, nullptr);
        else prev->next = new LNode(p, curr);
    }
    __size = ++__size;
}

const Clustering::Point &Clustering::Cluster::remove(const Clustering::Point &point) {
    __size = --__size;
    LNodePtr cursor = __points->next;
    LNodePtr oneBack = __points;
    if(point == oneBack->point){
        __points = oneBack->next;
        oneBack->next = nullptr;
    }
    else {
        while ((oneBack->point != point || cursor->point != point) && (cursor->next != nullptr)) {
            oneBack = cursor;
            cursor = cursor->next;
        }
        if (cursor->point == point) {
            oneBack->next = cursor->next;
            cursor->next = nullptr;
        }
    }
}

bool Clustering::Cluster::contains(const Clustering::Point &point) {
    LNodePtr cursor = __points;
    while(point != cursor->point){
        if(cursor->next == nullptr) return false;
        cursor = cursor->next;
    }
    return true;
}

const Clustering::Point &Clustering::Cluster::operator[](unsigned int index) const {
    LNodePtr cursor = __points;
    for(int i = 0; i < index; i++)
        cursor = cursor->next;
    return cursor->point;
}

Clustering::Cluster &Clustering::Cluster::operator+=(const Clustering::Point &point) {
    add(point);
}

Clustering::Cluster &Clustering::Cluster::operator-=(const Clustering::Point &point) {
    remove(point);
}

Clustering::Cluster &Clustering::Cluster::operator+=(const Clustering::Cluster &cluster) {
    LNodePtr cursor2 = cluster.__points;
    for(int i = 0; i < cluster.__size; i++) {
        if (contains(cursor2->point))
            cursor2 = cursor2->next;
        else {
            add(cursor2->point);
            cursor2 = cursor2->next;
        }
    }
}

Clustering::Cluster &Clustering::Cluster::operator-=(const Clustering::Cluster &cluster) {
    LNodePtr cursor2 = cluster.__points;
    for(int i = 0; i < cluster.__size; i++){
        if(contains(cursor2->point)) {
            remove(cursor2->point);
            cursor2 = cursor2->next;
        }
        else
            cursor2 = cursor2->next;
    }
}

const Clustering::Cluster Clustering::operator+(const Clustering::Cluster &cluster, const Clustering::Cluster &cluster1) {
    Cluster newCluster(cluster);
    newCluster += cluster1;
    return newCluster;
}

const Clustering::Cluster Clustering::operator-(const Clustering::Cluster &cluster, const Clustering::Cluster &cluster1) {
    Cluster newCluster(cluster);
    newCluster -= cluster1;
    return newCluster;
}

const Clustering::Cluster Clustering::operator+(const Clustering::Cluster &cluster, const Clustering::Point &point) {
    Cluster newCluster(cluster);
    newCluster += point;
    return newCluster;
}

const Clustering::Cluster Clustering::operator-(const Clustering::Cluster &cluster, const Clustering::Point &point) {
    Cluster newCluster(cluster);
    newCluster -= point;
    return newCluster;
}

ostream &Clustering::operator<<(ostream &ostream1, const Clustering::Cluster &cluster) {
    /*for(int i = 0; i < cluster.__size; i++){
        ostream1 << cluster[i] << ", ";
    }
    ostream1 << endl;*/
    LNodePtr curr = cluster.__points;
    while(curr->next != nullptr){
        ostream1 << curr->point;
        curr = curr->next;
    }
    ostream1 << curr->point << endl;

}

istream &Clustering::operator>>(istream &istream1, Clustering::Cluster &cluster) {
    string s;
    stringstream ss;
    double temp;
    int count = 0;

    while(getline(istream1, s, '\n')) {
        for (int i = 0; i < s.length(); i++) {
            if (ispunct(s[i]) && ispunct(s[i]) == ',')
                ++count;
        }

        ss.str(s);
        Clustering::Point p(count);
        ss >> p;
        cluster.add(p);
    }

}

bool Clustering::operator==(const Clustering::Cluster &cluster, const Clustering::Cluster &cluster1) {
    if(cluster.__size == cluster1.__size){
        LNodePtr cursor1 = cluster.__points;
        LNodePtr cursor2 = cluster1.__points;
        for(int i = 0; i < cluster.__size; i++){
            if(cursor1->point != cursor2->point) return false;
            else{
                cursor1 = cursor1->next;
                cursor2 = cursor2->next;
            }
        }
        return true;
    }
    else return false;
}

bool Clustering::operator!=(const Clustering::Cluster &cluster, const Clustering::Cluster &cluster1) {
    return !(cluster == cluster1);
}





