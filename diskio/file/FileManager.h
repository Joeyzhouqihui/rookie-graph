#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <stdio.h>
#include <string>

/**
 *  The job of a fileManeger is just open, read, write file data and check if the operations are legal.
 */
class FileManager
{
    private:
        const char *filename;

        // the two values of the boolean variable stand for "r" or "w" mode
        const bool mode;

        FILE* fp;
    
    public:
        FileManager(const char* fn, bool m);

        FileManager(const std::string, bool m);

        virtual ~FileManager();

        virtual bool fetchToBuffer(size_t offsets[], size_t bytes[], void *buffers[]);

        virtual bool dumpToFile(size_t offsets[], size_t bytes[], void *buffers[]);

        /**
         * This function is used when the graph structure is chanaged
         * For example, when a vertex has new neighbours, the space it originially occupys cannot store those newly comming data.
         * So we need to put them at the end of the file and use pointer to link them with the original data. 
         */ 
        virtual size_t appendToFile(size_t bytes[], void *buffers[]);

};

#endif