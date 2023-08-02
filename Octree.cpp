// Octree.cpp
#include <iostream>
#include <ostream>
#include <vector>
#include <cmath>


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
Octree<PointType>::Octree(PointType rootValue, int chunkSize) {

    OctNode<PointType>* root = new OctNode<PointType>();
    root->depth = 0;
    root->index = 0;
    root->PT = new PointType(rootValue);

    insert(*root);

    Max_depth = log2(chunkSize);
    chunk_size = chunkSize;
}

template<typename PointType>
OctNode<PointType>& Octree<PointType>::get(int depth, int index) {
    return nodes[depth][index];
}


template<typename PointType>
void Octree<PointType>::printNode(OctNode<PointType> node) {
    std::cout << "Depth: " << node.depth
              << " Index: " << node.index
              << " Parent Index: " << node.parentI
              << std::endl;
}

template<typename PointType>
void Octree<PointType>::printAllNodes(Octree<PointType>& octree) {

    for (int i = 0; i < octree.nodes.size(); i++) {
        for (int j = 0; j < octree.nodes[i].size(); j++) {

            OctNode<PointType> node = octree.nodes[i][j];

            if (node.PT != nullptr) {
                printNode(node);
            }
        }
    }
}

template<typename PointType>
bool Octree<PointType>::insertNode(PointType node) {
    int parent = 0;
    for (int i = 1; i <= Max_depth; i++)
    {
        parent = getParent(node);
        current_depth += 1;
        std::cout << "_____________parent:  " <<  parent << std::endl;
        if(i == Max_depth)
            break;
        OctNode<PointType>* on = new OctNode<PointType>();
        on->depth = current_depth;
        on->index = parent;
        on->parentI = last_midpoint;
        insert(*on);
    }
    OctNode<PointType>* on = new OctNode<PointType>();
    on->depth = current_depth;
    on->index = parent;
    on->parentI = last_midpoint;
    on->PT = *node;
    insert(*on);
}

//this should return the parent node in current depth
template<typename PointType>
int Octree<PointType>::getParent(PointType node) {
    int depth = current_depth;
    depth++;
    int parent;
    //get the boundries
    int bound = chunk_size / depth;
    int midPoint = (last_midpoint) + (bound / 2);
    last_midpoint = midPoint;
    int x = node.x - genesisBlock.x;
    int y = node.y - genesisBlock.y;
    int xMid = bound / 2;
    int yMid = bound / 2;
    int row = -1;
    int col = -1;
    std::cout<< "bound:  " << bound << std::endl
         << "midpoint:  " << midPoint << std::endl;
    //get x region
    if(x >= midPoint)
        col = 1;
    else
        col = 0;
    if(y >= midPoint)
        row = 1;
    else
        row = 0;
    std::cout<< "column:  " << col << std::endl
             << "row:  " << row << std::endl ;
    if(row == 1 && col == 1)
        parent = 3;
    else if(row == 1 && col == 0)
        parent = 2;
    else if(row == 0 && col == 1)
        parent = 1;
    else
        parent = 0;
    return parent;

}
