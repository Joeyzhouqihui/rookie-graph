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
        size_t *offsets;

        size_t *bytes;
        
        void **buffers;

        Requests();

        void addRequest(size_t offset, size_t byte, void *buffer);

};

class IoSlave
{
    private:
        // There may be several threads than read a common file at the same time.
        const short max_reader_num, max_request_num, timeout;

        FileManager* fileReaderPool;

        FileManager fileWriter, fileAppender;

        Requests* readRequestsNum;

        short readRequestsNum;

        Requests *writeRequests, *appendRequests;

        short writeRequestsNum, appendRequestNum;

    public:
        IoSlave(int num1, int num2, double time);

        void addReadRequest(size_t offset, size_t byte, void *buffer);

        void addWriteRequest(size_t offset, size_t byte, void *buffer);

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

        void read(FileType fileType, size_t offset, size_t byte, void *buffer);

        void write(FileType fileType, size_t offset, size_t byte, void *buffer);

        void append(FileType fileType, size_t offset, size_t byte, void *buffer);
};

#endif