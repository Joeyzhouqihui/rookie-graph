#ifndef PROPERTY_H
#define PROPERTY_H

#include <unordered_map>
#include <string>

enum valueType{
    INT,
    FLOAT,
    STRING,
    ARRAY
};

template <class T>
class Property
{
    private:
        std::unordered_map<T, std::string> kvMap;

        std::unordered_map<T, valueType> ktMap;

    public:
        void parse(char *ptr);

        template <class T1. class T2>
        T2 getValue(T keyId);

        template <class T1>
        T1 parseValue(std::string, valueType type);

        
};

#endif