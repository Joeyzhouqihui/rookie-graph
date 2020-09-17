#ifndef IO_MANAGER_H
#define IO_MANAGER_H

#include "file/FileManager.h"
#include <unordered_map>

enum FileType {
    vertex,
    adjacency,
    vertex_property,
    edge_property,

    label,
    vertex_property_key,
    edge_property_key
};

class Requests
{
    public:
        int *offsets;

        int *bytes;
        
        void **buffers;

        Requests();

        void addRequest(int offset, int byte, void *buffer);

};

class IoSlave
{
    private:
        // There may be several threads than read a common file at the same time.
        const short maxReaderNum, maxRequestNum, timeout;

        FileManager* fileReaderPool;

        FileManager fileWriter, fileAppender;

        Requests* readRequestsNum;

        short readRequestsNum;

        Requests *writeRequests, *appendRequests;

        short writeRequestsNum, appendRequestNum;

    public:
        IoSlave(int num1, int num2, double time);

        void addReadRequest(int offset, int byte, void *buffer);

        void addWriteRequest(int offset, int byte, void *buffer);

        void doReads();

        void doWrites();

        void doAppend();

        // May use a thread to asynchronously execute the following two functions
        void checkFull();

        void checkTimeOut();
};

class IoManager
{
    private:
        std::unordered_map<FileType, IoSlave*> slavesCamp;

    public:
        IoManager();

        void read(FileType fileType, int offset, int byte, void *buffer);

        void write(FileType fileType, int offset, int byte, void *buffer);

        void append(FileType fileType, int offset, int byte, void *buffer);
};

#endif