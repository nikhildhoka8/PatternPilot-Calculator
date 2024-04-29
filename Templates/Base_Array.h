#pragma once
#ifndef _BASE_ARRAY_H_
#define _BASE_ARRAY_H_

#include <cstring>


template <typename T>
class Base_Array
{
    public:
    //default constructor
    Base_Array(void);

    //size constructor
    Base_Array(size_t length);

    //fill constructor
    Base_Array(size_t length, T fill);

    //copy constructor
    Base_Array(const Base_Array & arr);


    //destructor
    ~Base_Array(void);

    //assignment operator
    const Base_Array & operator = (const Base_Array & rhs);

    //get the current size of the array
    size_t size(void) const;

    //get the max size of the array
    size_t max_size(void) const;

    // [] operator
    T & operator [] (size_t index);

    // [] operator
    const T & operator [] (size_t index) const;

    //get method at index
    T get(size_t index) const;

    //set method at index
    void set(size_t index, T value);

    //find the index of a value
    int find(T value) const;

    //find the index of a value at a starting index
    int find(T val, size_t start) const;

    //== operator
    bool operator == (const Base_Array & rhs) const;

    //!= operator
    bool operator != (const Base_Array & rhs) const;

    //fill the array with a value
    void fill(T value);


    protected:
        T * data_;
        size_t cur_size_;
        size_t max_size_;
};
#include "Base_Array.cpp"
#include "Base_Array.inl"
#endif // !defined _BASE_ARRAY_H_