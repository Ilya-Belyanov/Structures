#ifndef ABSADAPTER_HPP
#define ABSADAPTER_HPP

#include <iostream>

template<typename T>
class AbsLineAdapter
{

public:
    AbsLineAdapter();

    virtual void push_back(T data)  = 0;
    virtual void push_front(T data) = 0;
    virtual T pop_front() = 0;
    virtual T pop_back()  = 0;
    virtual T front()     = 0;
    virtual T back()      = 0;
    virtual void insert(uint32_t pos, T data) = 0;
    virtual uint32_t size() const = 0;
    virtual void clear()          = 0;
    virtual void flip()           = 0;
    bool empty();

    virtual T& operator[] (const uint32_t index) = 0;
};

template<typename T>
AbsLineAdapter<T>::AbsLineAdapter()
{

}

template<typename T>
bool AbsLineAdapter<T>::empty()
{
    return size() == 0;
}

#endif // ABSADAPTER_HPP
