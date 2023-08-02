//
// Created by amirmfarhang on 8/2/23.
//

#ifndef OCTREE_OCTNODE_H
#define OCTREE_OCTNODE_H

template<typename PointType>
class OctNode
{
public:
    int depth = 0;
    int parentI = 0;
    int index= 0;
    PointType* PT = nullptr;
};


#endif //OCTREE_OCTNODE_H
