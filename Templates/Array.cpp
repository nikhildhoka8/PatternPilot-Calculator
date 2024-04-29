// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include <stdexcept>         // for std::out_of_bounds exception

// Default Constructor
template <typename T>
Array <T>::Array (void): 
    Base_Array<T>()
{
}


// Size Constructor
template <typename T>
Array <T>::Array(size_t length)
    : Base_Array<T>(length)
{
}


// Fill Constructor
template <typename T>
Array <T>::Array (size_t length, T fill):
    Base_Array<T>(length, fill)
{
}


// Copy Constructor
template <typename T>
Array <T>::Array (const Array & array):
    Base_Array<T>(std::move(array))
{
}


// Destructor
template <typename T>
Array <T>::~Array (void)
{
}



// resize
template <typename T>
void Array<T>::resize(size_t new_size) {
    if (new_size == this->cur_size_) {
        // No change in size
        return;
    }

    T *new_data_ = new T[new_size];
    size_t elementsToCopy = std::min(new_size, this->cur_size_);
    for (size_t i = 0; i < elementsToCopy; i++) {
        new_data_[i] = std::move(this->data_[i]);
    }
    delete[] this->data_;
    this->data_ = new_data_;
    this->cur_size_ = elementsToCopy;
    this->max_size_ = new_size;
}


template <typename T>
void Array <T>::push_back(T element)
{
    //check if the array is full
    if(this->cur_size_ == this->max_size_){
        //resize the array
        this->resize(this->max_size_ + 1);
    }
    //add the element to the end of the array
    this->data_[this->cur_size_] = std::move(element);
    this->cur_size_++;
}