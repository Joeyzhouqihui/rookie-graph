#ifndef PROPERTY_H
#define PROPERTY_H

enum PropertyType {stringProperty, 
                   shortProperty, intProperty, longProperty, longLongProperty, 
                   boolenProperty,
                   arrayProperty};

template <class T1, class T2>
class Property
{
    private:
        PropertyType type;
        T1 *key;
        T2 *value;
    public:
        Property();

        Property(Property& p);

        Property(T1 key, T2 value);

        PropertyType getType();

        void getValue();

        void setValue();
};

#endif