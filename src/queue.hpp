#ifndef QUEQU_H
#define QUEQU_H

#include "node/node_dl.hpp"

template<typename T>
class Queue
{
    NodeDL<T> *_front;
    NodeDL<T> *_back;
    uint32_t _size;

public:
    Queue();
    ~Queue();

    void push(T data);
    T pop();
    T front();
    T back();
    bool empty();
};

template<typename T>
Queue<T>::Queue() :
    _front(nullptr)
  , _back(nullptr)
  , _size(0)
{

}

template<typename T>
Queue<T>::~Queue()
{
    while(_front)
        pop();
}

template<typename T> void Queue<T>::push(T data)
{
    if(empty())
    {
        _front = new NodeDL<T>(data);
        _back = _front;
    }
    else
    {
        auto node = _back;
        _back = new NodeDL<T>(data);
        node->_next = _back;
    }
    _size++;
}

template<typename T> T Queue<T>::pop()
{
    if(_front)
    {
        T data = front();
        auto node = _front;
        _front = _front->_next;
        _size--;
        delete node;
        if(empty())
            _back = nullptr;
        return data;
    }
    return T();
}

template<typename T> T Queue<T>::front()
{
    if(_front)
        return _front->data();
    return T();
}

template<typename T> T Queue<T>::back()
{
    if(_back)
        return _back->data();
    return T();
}

template<typename T> bool Queue<T>::empty()
{
    return _size == 0;
}
#endif // QUEQU_H
