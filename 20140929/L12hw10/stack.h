#ifndef STACK_H_
#define STACK_H_


#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

template <typename T>
class Stack_t {
public:
     void push (const T &t);
     void pop ();
     T  top () const;

     bool empty() const
     { return elems_.empty();}

private:
    std::vector<T> elems_;
    /* data */
};






#endif
