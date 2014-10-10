
#ifndef STACK_H_
#define STACK_H_


#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <deque>
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
template <>  //模板特化
class Stack_t<std::string>

{
    public:
        void push( const std::string &s)
        {
            elems_.push_back(s);
        }
        void  pop()
        { elems_.pop_back();}

        std::string top () const
        { return elems_.back();}

        bool empty() const
        { return elems_.empty();}

    private :
        std::deque<std::string> elems_;
};





#endif
