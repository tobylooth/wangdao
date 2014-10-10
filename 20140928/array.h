#ifndef ARRAY_H_
#define ARRAY_H_

#include <iostream>

class Arry
friend std::ostream &operator<<(std::ostream &os,const Arry &arr);
friend Array operator+ (const Array &a,const Array &b);
friend bool operator< (const Array &a,const Array &b);
friend bool operator<=(const Array &a,const Array &b);
friend bool operator> (const Array &a,const Array &b);
friend bool operator>=(const Array &a,const Array &b);
friend bool operator==(const Array &a,const Array &b);
friend bool operator!=(const Array &a,const Array &b);

{
public:
    Array (size_t capacity);
    Array (int *arr,size_t capacity);
    Array (const Array &other);
    ~Array();

    Array &operator=(const Array &other);
    Array &operator+=(const Array &other);

    int   &operator[] (size_t index);
    int operator[] (size_t index) const;

    size_t getSize() const {return size_;}
    size_t getCapacity() const {return capacity_;}



private:
        int *data_;
        size_t size_;
        size_t  capacity_;
    /* data */
};


#endif
