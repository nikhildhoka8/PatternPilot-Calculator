// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.


// Default Constructor
template <typename T>
Stack <T>::Stack (void):
    data_ (10),
    top_ (0)
{
}


// Copy Constructor
template <typename T>
Stack <T>::Stack (const Stack & stack):
    data_(stack.data_),
    top_ (stack.top_)
{
}


// Destructor
template <typename T>
Stack <T>::~Stack (void)
{

}


// push
template <typename T>
void Stack <T>::push (T element)
{
    if (data_.size() <= top_)
    {
        // Increase the array size
        data_.resize(data_.size() + 10);
    }
    
    // Insert the new element at the top of the stack
    data_[top_++] = element;

}


// pop
template <typename T>
void Stack <T>::pop (void)
{
    //check if the stack is empty
    if (is_empty())
    {
        throw empty_exception("Stack is empty");
    }
    else
    {
        //remove the top element from the stack
        --top_;
    }
}


// operator =
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
    //check if the stack is the same
    if (this != &rhs)
    {
        data_ = rhs.data_;
        top_ = rhs.top_;
    }
    return *this;


}


// clear
template <typename T>
void Stack <T>::clear (void)
{
    //clear the stack
    top_ = 0;
}

