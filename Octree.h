#include "./OctNode.h"
#include <vector>

#ifndef OCTREE_OCTREE_H
#define OCTREE_OCTREE_H

template<typename PointType>
class Octree
{
public:
    int Max_depth = 0;
    int current_depth = 0;
    int chunk_size = 0;
    PointType genesisBlock;

    std::vector<std::vector<OctNode<PointType>>> nodes;

    Octree(PointType rootValue, int chunkSize);

    bool insert(OctNode<PointType> node);

    OctNode<PointType>& get(int depth, int index);

    void printAllNodes(Octree<PointType>& octree);

    int getNumBits(int value, int max);

    int getIndex(int value, int bits);

    void printNode(OctNode<PointType> node);

    bool insertNode(PointType node);

    int getParent(PointType node);
};

#include "./Octree.inl"
#endif //OCTREE_OCTREE_H
