#ifndef VERTEX_BUFFER_MANAGER_H
#define VERTEX_BUFFER_MANAGER_H

#include "BufferManager.h"

// This is used as write buffer.
class ExtendBufferBlock: public BufferBlock
{
    private:
        char *tail;

    public:
        bool canFit(int blockSize, int byte);

        /**
         * After append you need to return the physical address of the newly added record, 
         * so that the original data can write it to the corresponding place.
         */
        int append(char *data, int byte);
};

template <class T>
class VertexBufferManager: public BufferManager
{
    private:
        int extendBlockNum, currentExendBlock;

        ExtendBufferBlock *extendBlocks;

    public:
        VertexBufferManager(int size, int blockNum, int extendNum);

        int idToOffset(T id);

};

#endif