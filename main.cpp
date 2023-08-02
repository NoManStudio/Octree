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
    Point() {} // Default constructor
    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        return os << "(" << p.x << ", " << p.y << ", " << p.z << ")";
    }
    Point(float x, float y, float z) : x(x), y(y), z(z) {}
};
int main()
{
    Point p1(2, 2, 8);
    Point p3(1, 1, 1);
    Point p4(8, 7, 8);
    Point p5(7, 8, 8);
    Point genesisBlock(0, 0, 0);

    OctNode<Point>* on = new OctNode<Point>();

    Octree<Point>* oc = new Octree<Point>(genesisBlock, 4);
    oc->genesisBlock = genesisBlock;
    oc->insertNode(p1);
//    oc->insert(*on);
//    OctNode<int> ot = oc->get(1, 1);
//    std::cout<< *ot.PT;
//    oc->printAllNodes(*oc);
}
