// -*- C++ -*-
// $Id: Stack.inl 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.

#include "Stack.h"

// size of the Stack
template <typename T>
inline
size_t Stack <T>::size (void) const
{
    return this->top_;
}


// top
// return the value of the top of the stack
template <typename T>
inline
T Stack <T>::top (void) const
{
    if(top_ > 0)
    {
        return data_[top_-1];
    }
    else
    {
        throw empty_exception("Stack is empty");
    }
}


// is_empty
template <typename T>
inline
bool Stack <T>::is_empty (void) const
{
    return (this->top_ == 0);
}
