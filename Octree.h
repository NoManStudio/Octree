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
    int last_xmidpoint = 0;
    int last_ymidpoint = 0;
    int last_zmidpoint = 0;
    int last_parent = 0;
    PointType genesisBlock;

    std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<OctNode<PointType>>>>>>> nodes;

    Octree(int chunkSize);

    bool insert(OctNode<PointType> node);

    OctNode<PointType>& get(int depth, int index, int parent);

    void printAllNodes(Octree<PointType>& octree);

    int getNumBits(int value, int max);

    int getIndex(int value, int bits);

    void printNode(OctNode<PointType> node);

    bool insertNode(PointType node);

    int getParent(PointType node);
};

#include "./Octree.inl"
#endif //OCTREE_OCTREE_H
