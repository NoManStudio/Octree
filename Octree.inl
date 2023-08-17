// Octree.cpp
#include <iostream>
#include <ostream>
#include <vector>
#include <cmath>


template<typename PointType>
bool Octree<PointType>::insert(OctNode<PointType> node) {

    int depth = node.depth;
    int index = node.index;
    int parent = node.parentI;
    int parent1 = node.parent1;
    int parent2 = node.parent2;
    int parent3 = node.parent3;
    // Expand vectors size if    needed
    if (depth >= nodes.size())
    {
        nodes.resize(depth + 1);
    }
    if (parent1 >= nodes[depth].size())
    {
        nodes[depth].resize(parent1 + 1);
    }
    if (parent2 >= nodes[depth][parent1][parent2].size())
    {
        nodes[depth][parent1][parent2].resize(index + 1);
    }
    if (parent3 >= nodes[depth][parent1][parent2][parent3].size())
    {
        nodes[depth][parent1][parent2][parent3].resize(index + 1);
    }
    if (parent >= nodes[depth][parent1][parent2][parent3][parent].size())
    {
        nodes[depth][parent1][parent2][parent3][parent].resize(index + 1);
    }
    if (index >= nodes[depth][parent1][parent2][parent3][parent][index].size())
    {
        nodes[depth][parent1][parent2][parent3][parent][index].resize(index + 1);
    }
    // Insert node into correct depth vector
    nodes[depth][parent1][parent2][parent3][parent][index] = node;

    return true;

}

template<typename PointType>
Octree<PointType>::Octree(int chunkSize) {
    Max_depth = log2(chunkSize);
    chunk_size = chunkSize;
}

template<typename PointType>
OctNode<PointType>& Octree<PointType>::get(int depth, int index, int parent) {
    return nodes[depth][parent][index];
}


template<typename PointType>
void Octree<PointType>::printNode(OctNode<PointType> node) {
    std::cout << "Depth: " << node.depth
              << " Index: " << node.index
              << " Parent Index: " << node.parentI    << std::endl;
    std::cout << " Data:  " << node.PT->data << std::endl;

}

template<typename PointType>
void Octree<PointType>::printAllNodes(Octree<PointType>& octree) {

    for (int i = 0; i < octree.nodes.size(); i++) {

        for (int j = 0; j < octree.nodes[i].size(); j++) {

            for (int k = 0; k < octree.nodes[i][j].size(); k++) {

                OctNode<PointType> node = octree.nodes[i][j][k];

                if (node.PT != nullptr) {
                    printNode(node);
                }
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
        last_parent = parent;

    }
    PointType* Point = new PointType(node);
    OctNode<PointType>* on = new OctNode<PointType>();
    on->depth = current_depth;
    on->index = parent;
    on->parentI = last_parent;
    on->PT = Point;
    insert(*on);
    current_depth = 0;
    last_xmidpoint = 0;
    last_ymidpoint = 0;
    last_zmidpoint = 0;
    last_parent = 0;
}

//this should return the parent node in current depth
template<typename PointType>
int Octree<PointType>::getParent(PointType node) {
    int depth = current_depth;
    depth++;
    int parent;
    //get the boundries
    int bound = chunk_size / depth;
    int midPoint;
    int x = node.x - genesisBlock.x;
    int y = node.y - genesisBlock.y;
    int z = node.z - genesisBlock.z;
    int xmidPoint = 0;
    int ymidPoint = 0;
    int zmidPoint = 0;
    if(depth == 1) {
        xmidPoint = bound / 2;
        ymidPoint = bound / 2;
        zmidPoint = bound / 2;
    }
    else if(last_xmidpoint <= x)
    {
        xmidPoint = (last_xmidpoint) + (bound / 2);
        if(last_ymidpoint <= y)
            ymidPoint = (last_ymidpoint) + (bound / 2);
        else
            ymidPoint = (last_ymidpoint) - (bound / 2);
        if(last_zmidpoint <= z)
            zmidPoint = (last_zmidpoint) + (bound / 2);
        else
            zmidPoint = (last_zmidpoint) - (bound / 2);
    }
    else
    {
        xmidPoint = (last_xmidpoint) - (bound / 2);
        if(last_ymidpoint <= y)
            ymidPoint = (last_ymidpoint) + (bound / 2);
        else
            ymidPoint = (last_ymidpoint) - (bound / 2);
        if(last_zmidpoint <= z)
            zmidPoint = (last_zmidpoint) + (bound / 2);
        else
            zmidPoint = (last_zmidpoint) - (bound / 2);
    }

    last_xmidpoint = xmidPoint;
    last_ymidpoint = ymidPoint;
    last_zmidpoint = zmidPoint;


    int row = -1;
    int col = -1;
    int height = -1;
    std::cout<< "bound:  " << bound << std::endl
         << "xmidpoint:  " << xmidPoint << std::endl
         << "ymidpoint:  " << ymidPoint << std::endl
         << "zmidpoint:  " << zmidPoint << std::endl;
    //get x region
    if(x >= xmidPoint)
        col = 1;
    else
        col = 0;
    if(y >= ymidPoint)
        row = 1;
    else
        row = 0;
    if(z >= zmidPoint)
        height = 1;
    else
        height = 0;

    std::cout<< "column:  " << col << std::endl
             << "row:  " << row << std::endl
             << "z:  " << height << std::endl ;
    if(row == 1 && col == 1 && height == 0)
        parent = 3;
    else if(row == 1 && col == 0 && height == 0)
        parent = 2;
    else if(row == 0 && col == 1 && height == 0)
        parent = 1;
    else if(row == 0 && col == 0 && height == 0)
        parent = 0;
    else if(row == 1 && col == 1 && height == 1)
        parent = 7;
    else if(row == 0 && col == 1 && height == 1)
        parent = 5;
    else if(row == 1 && col == 0 && height == 1)
        parent = 6;
    else
        parent = 4;
    return parent;

}
