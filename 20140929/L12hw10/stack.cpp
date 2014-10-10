#include "stack.h"

template <typename T>

void Stack_t<T>::push (const T &t)
{
    elems_.push_back(t);
}

template <typename T>
void Stack_t<T>::pop ()
{
    if(elems_.empty())
        throw std::out_of_range("out of range");
    elems_.pop_back();
}

template <typename   T>
T Stack_t<T>::top () const
{
    if(elems_.empty())
        throw std::out_of_range("out of range");
    return elems_.back();
}
