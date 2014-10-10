#include "integer.h"

using namespace std;

Integer::Integer(int data)
    :data_(data)
{}

ostream &operator<< (ostream &os,const Integer &i)
{
    return os << i.data_;
}

istream &operator>> (istream &is,Integer &i)
{
    int temp = i.data_;
    is >>i.data;
    if(!is)
    {
        i.data_ = temp;
    }

    return is;
}

Integer Integer::operator++(int)
{
    Integer temp(*this);
    ++data_;

    return temp;
}
Integer &Integer::operator++()
{
    ++data_;
    return *this;
}
Integer &Integer::operator=(int data)
{
    data_=data;
    return *this;
}











