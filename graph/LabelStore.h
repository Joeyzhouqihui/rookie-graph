#ifndef LABEL_STORE_H
#define LABEL_STORE_H

#include <unordered_map>
#include <string>
#include "../utils/IdGenerator.h"

template <class T>
class LabelStore
{
    private:
        std::unordered_map<std::string, T> labelStrToIdMap;

        std::unordered_map<T, std::string> labelIdToStrMap;

        IdGenerator<T> *idGenerator;

    public:
        string getLabelStr(T labelId);

        T getLabelId(string labelStr);

        void addLabel(string labelStr);
        
};

#endif