#ifndef GRAPH_H
#define GRAPH_H

#include "VertexStore.h"
#include "LabelStore.h"
#include "PropertyKeyStore.h"

class Graph
{
    private:
        VertexStore *vertexstore;

        LabelStore<short> *labelStore;

        PropertyKeyStore<short> *propertyKeyStore;
    
    public:
        

};

#endif