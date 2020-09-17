#ifndef ADJACENCY_LIST_H
#define ADJACENCY_LIST_H

#include "Edge.h"

template <class T>
class AdjacencyList
{
    private:
        std::deque<T> labelIds;

        std::unordered_map<T, EdgeList<T> > edgeLists;

    public:
        EdgeList<T>* getEdgeListByLabel(T labelId);
 
};

#endif
