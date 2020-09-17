#ifndef ID_GENERATOR_H
#define ID_GENERATOR_H

template <class T>
class IdGenerator
{
    private:
        T counter;
    public:
        T getNewId();
};

#endif