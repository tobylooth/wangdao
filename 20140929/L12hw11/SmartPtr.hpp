#ifndef SMART_PTR_H_
#define SMART_PTR_H_

#include <iostream>

class Animal
{
    public:
        Animal() { std::cout << "Animal " << std::endl; }
        ~Animal() { std::cout << "~Animal " << std::endl;}

        void run() {  std::cout << "Animal is running " <<std::endl;}

};
template  <typename T>
class SmartPtr_t {
public:
    SmartPtr_t ( T *ptr) : ptr_(ptr) {}
    ~SmartPtr_t () { delete ptr_;}

    T &operator*()  { return *ptr_;}
    const T &operator*() const { return *ptr_;}


    T &operator->() { return ptr_; }
    const T &operator->() const {return ptr_; }

    void resetPtr( T *ptr =NULL);
   const  T *getptr() const { return ptr_;}





private:
   SmartPtr_t( const SmartPtr_t &);
   void operator=(const SmartPtr_t &);
   T ptr_;
    /* data */
};

template <typename T>
void SmartPtr_t<T>::resetPtr(T *ptr )
{
    if( ptr!= ptr_)
    {
        delete ptr_;
        ptr_=ptr;
    }
}



#endif
