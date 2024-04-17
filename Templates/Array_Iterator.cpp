

template <typename T> 
Array_Iterator <T>::Array_Iterator (Array <T> & a): a_ (a), curr_ (0) { }


template <typename T> 
bool Array_Iterator <T>::is_done (void) 
{ 
    return this->curr_ >= this->a_.cur_size_; 
}

template <typename T>
void Array_Iterator <T>::advance (void) 
{ 
    ++ this->curr_; 
}
        
template <typename T>
T & Array_Iterator <T>::operator * (void) 
{ 
    return this->a_.data_[this->curr_]; 
}
        
template <typename T>
T * Array_Iterator <T>::operator -> (void) 
{ 
    return &this->a_.data_[this->curr_]; 
}