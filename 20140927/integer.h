#ifndef INTEGER_H_
#define INTEGER_H_

#include <iosteam>

class Integer {
    friend std::ostream &operator<<(std::ostream &os,const Integer &i);
    friend std::istream &operator>>(std::istream &is,Integer &i);
public:

    Integer (int data = 0);
    Integer &operator=(int data);

    Integer &operator++();
    Integer operator++(int);

    operator int()
    { return data_;}


private:
    int data_;
    /* data */
};




#endif
