#ifndef EDGE_H
#define EDGE_H

#include "../content/Property.h"
#include <deque>

template <class T>
class Edge
{
    private:
        T labelId;

        int srcId, desId;

        Property<T> *property;
    
    public:
        int getSrcId();

        int getDesId();

        Property* getProperty();

        void setProperty();

};

template <class T>
class EdgeList
{
    private:
        std::deque<Edge<T> > edges;

        std::deque<Edge<T> >::iterator it;

    public:
        bool forward();

        void backward();

        Edge<T> getEdge();

};

#endif