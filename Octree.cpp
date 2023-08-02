// Octree.cpp
#include <iostream>
#include <ostream>
#include <vector>
#include <cmath>
const int MAX_DEPTH = 16

template<typename PointType>
bool Octree<PointType>::insert(OctNode<PointType> node) {

    int depth = node.depth;
    int index = node.index;
    // Expand vectors size if needed
    if (depth >= nodes.size()) {
        nodes.resize(depth + 1);
    }
    if (index >= nodes[depth].size()) {
        nodes[depth].resize(index + 1);
    }

    // Insert node into correct depth vector
    nodes[depth][index] = node;

    return true;

}

template<typename PointType>
Octree<PointType>::Octree(PointType rootValue) {

    OctNode<PointType>* root = new OctNode<PointType>();
    root->depth = 0;
    root->index = 0;
    root->PT = new PointType(rootValue);

    insert(*root);

}

template<typename PointType>
OctNode<PointType>& Octree<PointType>::get(int depth, int index) {
    return nodes[depth][index];
}


