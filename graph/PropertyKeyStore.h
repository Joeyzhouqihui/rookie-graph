#ifndef PROPERTY_KEY_STORE_H
#define PROPERTY_KEY_STORE_H

#include <unordered_map>
#include <string>
#include "../utils/IdGenerator.h"

template <class T>
class PropertyKeyStore
{
    private:
        std::unordered_map<std::string, T> keyStrToIdMap;

        std::unordered_map<T, std::string> keyIdToStrMap;

        IdGenerator<T> *idGenerator;

    public:
        string getKeyStr(T id);

        T getKeyId(string str);

        void addKey(string str);
        
};

#endif