#include <stdexcept> 
#include <cstring>
#include "Base_Array.h"

#define DEFAULT_SIZE 7

//default constructor
template <typename T>
Base_Array<T>::Base_Array(void)
    : data_(new T[DEFAULT_SIZE]),
    cur_size_(0),
    max_size_(DEFAULT_SIZE)
{
}

//size constructor
template <typename T>
Base_Array<T>::Base_Array(size_t length): 
    data_(nullptr),
    cur_size_(0),
    max_size_(0)
{
    //check if the size is 0, if it is then set the size to the default size and then set the current size to the length
    if (length == 0)
    {
        this->data_ = new T[DEFAULT_SIZE];
        this->cur_size_ = length;
        this->max_size_ = DEFAULT_SIZE;
    }
    else
    {
        this->data_ = new T[length];
        this->cur_size_ = length;
        this->max_size_ = length;
    }

}

//fill constructor
template <typename T>
Base_Array<T>::Base_Array(size_t length, T fill)
    : Base_Array<T>(length)
{
    //call the fill method
    this->fill(fill);
}

//copy constructor
template <typename T>
Base_Array<T>::Base_Array(const Base_Array & arr)
    : Base_Array(arr.cur_size_)
{
    //copy the data from the array
    for (size_t i = 0; i < arr.cur_size_; i++)
    {
        this->data_[i] = arr.data_[i];
    }
}

//destructor
template <typename T>
Base_Array<T>::~Base_Array(void)
{
    if (this->data_ != nullptr)
    {
        delete[] this->data_;
    }
}


//assignment operator
template <typename T>
const Base_Array<T> & Base_Array<T>::operator = (const Base_Array & rhs)
{
    //check if the arrays are the same
    if (this != &rhs)
    {
        
        
        //set the current size to the right hand side
        this->cur_size_ = rhs.cur_size_;
        //set the max size to the right hand side
        this->max_size_ = rhs.max_size_;
        //delete the data
        delete[] this->data_;
        //create a new array
        this->data_ = new T[this->max_size_];
        //copy the data from the right hand side
        for (size_t i = 0; i < this->cur_size_; i++)
        {
            this->data_[i] = rhs.data_[i];
        }
    }
    return *this;
}

// [] operator
template <typename T>
T & Base_Array<T>::operator [] (size_t index)
{
    //check if the index is greater than the current size
    if (index >= this->size())
    {
        throw std::out_of_range("Index is out of range");
    }
    return this->data_[index];
}

// [] operator
template <typename T>
const T & Base_Array<T>::operator [] (size_t index) const
{
    //check if the index is greater than the current size
    if (index >= this->size())
    {
        throw std::out_of_range("Index is out of range");
    }
    return this->data_[index];
}

//get method at index
template <typename T>
T Base_Array<T>::get(size_t index) const
{
    //check if the index is greater than the current size
    if (index >= this->size())
    {
        throw std::out_of_range("Index is out of range");
    }
    return this->data_[index];
}

//set method at index
template <typename T>
void Base_Array<T>::set(size_t index, T value)
{
    //check if the index is greater than the current size
    if (index >= this->size())
    {
        throw std::out_of_range("Index is out of range");
    }
    this->data_[index] = value;
}

//find the index of a value
template <typename T>
int Base_Array<T>::find(T value) const
{
    //call the find method with a starting index of 0, catch the exception and return -1
    try
    {
        return this->find(value, 0);
    }
    catch (std::out_of_range & e)
    {
        return -1;
    }
}

//find the index of a value at a starting index
template <typename T>
int Base_Array<T>::find(T val, size_t start) const
{
    //check if the start index is greater than the current size
    if (start >= this->size())
    {
        throw std::out_of_range("Index is out of range");
    }
    //iterate through the array
    for (size_t i = start; i < this->size(); i++)
    {
        //check if the value is equal to the value at the index
        if (this->data_[i] == val)
        {
            return i;
        }
    }
    return -1;
}

//== operator
template <typename T>
bool Base_Array<T>::operator == (const Base_Array & rhs) const
{
    //check if the arrays are the same
    if(this == &rhs){
        return true;
    }
    if (this->size() != rhs.size())
    {
        return false;
    }
    //iterate through the array
    for (size_t i = 0; i < this->size(); i++)
    {
        //check if the values are the same
        if (this->data_[i] != rhs.data_[i])
        {
            return false;
        }
    }
    return true;
}

//!= operator defined in terms of the == operator
template <typename T>
bool Base_Array<T>::operator != (const Base_Array & rhs) const
{
    return !(*this == rhs);
}

//fill the array with a value
template <typename T>
void Base_Array<T>::fill(T value)
{
    //iterate through the array
    for (size_t i = 0; i < this->size(); i++)
    {
        //set the value at the index to the value
        this->data_[i] = value;
    }
}


