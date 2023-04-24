#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <inttypes.h>

typedef struct s_Data {
    unsigned int    value;
}   Data;

class Serializer {
    public:
        Serializer();
        Serializer( const Serializer &ref );
        ~Serializer();
        Serializer& operator=(const Serializer &rhs);
        uintptr_t serialize(Data* ptr);
        Data* deserialize(uintptr_t raw);
};

#endif