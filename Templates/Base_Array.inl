

//size
template <typename T>
inline
size_t Base_Array <T>::size (void) const
{
    return this->cur_size_;
}

// max size
template <typename T>
inline
size_t Base_Array <T>::max_size (void) const
{
    return this->max_size_;
}