#ifndef BUFFER_MANAGER_H
#define BUFFER_MANAGER_H

#include "../diskio/IoManager.h"

/**
 * joeyzhouqihui 2020/9/17
 * The buffer is consist of blocks, blocks are consist of records and records are several bytes.
 * The data exchange between disk and memory is block based.
 */
class BufferBlock
{
    private:
        char *blockPtr;

        // The location of this block on the disk.
        int diskOffset;
    
    public:
        BufferBlock(char *ptr, int byte);

        void copy(IoManager *in, int byte);

        void dump(IoManager *out, int byte);
};

class BufferManager
{
    private:
        // how many bytes total does the buffer has
        const int bufferSize, leftSize;

        // how many bytes total does a block have and how many blocks does the buffer have
        const int blockSize, blockNum;

        // how many bytes does a single record occupy  
        const short recordSize;

        char *buffer;

        BufferBlock *bufferBlocks[];

        // bitmap
        int freeBlocks;

        int dirtyBlocks;

        IoManager *ioManager;

    public:
        BufferManager(int size, int blockNum);

        virtual ~BufferManager();

        virtual bool isFull();

        virtual bool hit(int offset);

        virtual char* fetchRecords(int offset, int num);

        virtual BufferBlock* getFreeBlock();

        virtual void swapOutBlock();

        virtual void swapInBlock();        

};

#endif