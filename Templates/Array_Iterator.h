#ifndef ARRAY_ITERATOR_H
#define ARRAY_ITERATOR_H
#include "Array.h"

template <typename T>
class Array;


template <typename T>
class Array_Iterator {
    public:
        Array_Iterator (Array <T> & a);
        ~Array_Iterator (void) = default;
        bool is_done (void);
        void advance (void);
        T & operator * (void);
        T * operator -> (void);
    private:
        Array <T> & a_;
        size_t curr_;
};
#include "Array_Iterator.cpp"
#endif