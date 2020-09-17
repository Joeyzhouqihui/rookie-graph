#ifndef VERTEX_H
#define VERTEX_H

#include "AdjacencyList.h"
#include <iterator>

template <class T>
class Vertex
{
    private:
        T id;
        
        T labelId;

        Property<T> property;

        AdjacencyList<T> adjacencyList;

    public:
        T getLabelId();

        Property<T>* getProperty();

        void setProperty(<Property<T> *p);

        iterator getNeighbours();

        iterator getNeighbours(T labelId);

};

#endif