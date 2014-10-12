#ifndef UNIQUE_HPP_
#define UNIQUE_HPP_

#include <algorithm>
#include <stddef.h>
#include <utility>

template <typename T>

class UniquePtr
{
    public:
        typedef T element_type;
        typedef T *pointer;
        typedef T &reference;

        explicit UniquePtr (T *ptr =NULL ) throw()
            :ptr_(ptr)
        {}

        UniquePtr( UniquePtr &&u) throw()
            :ptr_(u.ptr_)
        {
            u.ptr_ = NULL;
        }

        UniquePtr &operator=(UniquePtr &&u) throw()
        {
            if(this != &u)
            {
                delete ptr_;
                ptr_=u.ptr_;
                u.ptr_ =NULL;
            }
            return *this;
        }

        ~UniquePtr() throw()
        {
            delete ptr_;
        }

        reference operator*() const throw()
        { return *ptr_; }
        pointer operator->() const throw()
        { return ptr_; }

        pointer get() const throw()
        { return ptr_; }

        pointer release() throw()
        {
            pointer temp(ptr_);
            ptr_ =NULL;
            return temp;
        }

        void swap( UniquePtr &other)
        {
            std::swap(ptr_,other.ptr_);
        }

    private:
        UniquePtr(const UniquePtr &);
        void operator=( const UniquePtr &);

        T *ptr_;
};


#endif
