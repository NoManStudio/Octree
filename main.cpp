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
    Point p1(8, 8, 8, "this is def");
    Point p2(2, 2, 3, "1");
    Point p3(3, 2, 3, "1");
    Point p4(2, 3, 3, "test");
    Point p5(3, 3, 2, "8");
    Point p6(2, 2, 2, "zero");
    Point p7(3, 2, 2, "1");
    Point p8(2, 3, 2, "test");
//    Point p5(7, 8, 8);
    Point genesisBlock(0, 0, 0, "Hello");

    OctNode<Point>* on = new OctNode<Point>();

    Octree<Point>* oc = new Octree<Point>(8);
    oc->genesisBlock = genesisBlock;
    oc->insertNode(p1);
//    oc->insertNode(p2);
//    oc->insertNode(p3);
//    oc->insertNode(p4);
//    oc->insertNode(p5);
//    oc->insertNode(p6);
//    oc->insertNode(p7);
//    oc->insertNode(p8);
//    oc->insertNode(p3);
//    oc->insertNode(p1);
//    oc->insertNode(p2);
    oc->printAllNodes(*oc);

//    oc->insert(*on);
//    OctNode<Point> ot = oc->get(2, 0, 0);
//    std::cout<< "point" <<  *ot.PT;

}


