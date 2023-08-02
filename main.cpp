//
// Created by amirmfarhang on 8/2/23.
//
#include "./OctNode.h"
#include "./Octree.h"
#include "./Octree.h"
#include <stdio.h>
#include <iostream>

const int MAX_DEPTH = 10;
const int BITS_PER_DIM = 3;

struct Point {
    float x;
    float y;
    float z;
    std::string data;
    Point() {} // Default constructor
    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        return os << "(" << p.x << ", " << p.y << ", " << p.z << ")";
    }
    Point(float x, float y, float z, std::string data) : x(x), y(y), z(z), data(data) {}
};
int main()
{
    Point p1(0, 1, 8, "8");
    Point p2(1, 0, 1, "1");
    Point p3(1, 1, 1, "1");
    Point p4(0, 0, 8, "test");
//    Point p5(7, 8, 8);
    Point genesisBlock(0, 0, 0, "Hello");

    OctNode<Point>* on = new OctNode<Point>();

    Octree<Point>* oc = new Octree<Point>(4);
    oc->genesisBlock = genesisBlock;
    oc->insertNode(p4);
    oc->insertNode(p3);
    oc->insertNode(p1);
    oc->insertNode(p2);
    oc->printAllNodes(*oc);

//    oc->insert(*on);
//    OctNode<Point> ot = oc->get(2, 0, 0);
//    std::cout<< "point" <<  *ot.PT;

}


+