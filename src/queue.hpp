#ifndef QUEUE_H
#define QUEUE_H

#include "node/node_dl.hpp"

template<typename T>
class Queue
{
    NodeDL<T> *_front;
    NodeDL<T> *_back;

public:
    Queue();
    Queue(const Queue<T> &copy);

    template<typename First, typename... Args>
    Queue(First first, Args... args) : Queue()
    {
        push(first);
        uint32_t l = sizeof... (Args);
        T items [l] { args... };
        for(uint32_t i = 0; i < l; i++)
            push(items[i]);
    }

    ~Queue();

    void push(T data);
    T pop();
    T front();
    T back();
    bool empty();
    void clear();
    uint32_t size() const;
    void flip();

    Queue<T> operator+(const Queue<T> &q);
    Queue<T> operator+=(const Queue<T> &qr);
    Queue<T>& operator= (const Queue<T> &q);

private:
    void copyFromTo(const Queue<T> &q, Queue<T> &res);
};

template<typename T>
Queue<T>::Queue() :
    _front(nullptr)
  , _back(nullptr)
{

}

template<typename T>
Queue<T>::Queue(const Queue<T> &copy) :
    _front(nullptr)
  , _back(nullptr)
{
    copyFromTo(copy, *this);
}

template<typename T>
Queue<T>::~Queue()
{
    clear();
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
}

template<typename T> T Queue<T>::pop()
{
    if(_front)
    {
        T data = front();
        auto node = _front;
        _front = _front->_next;
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
    return size() == 0;
}

template<typename T> void Queue<T>::clear()
{
    while(_front)
        pop();
}

template<typename T> uint32_t Queue<T>::size() const
{
    auto node = _front;
    uint32_t _size = 0;
    while (node)
    {
        _size++;
        node = node->_next;
    }
    return _size;
}

template<typename T> void Queue<T>::flip()
{
    if(empty())
        return;
    auto node = _front;
    auto node_next = _front->_next;
    node->_next = nullptr;
    while(node_next)
    {
        auto tmp = node_next->_next;
        node_next->_next = node;
        node = node_next;
        node_next = tmp;
    }
    _back = _front;
    _front = node;
}

template<typename T> Queue<T> Queue<T>::operator+(const Queue<T> &q)
{
    Queue<T> res;
    copyFromTo(*this, res);
    copyFromTo(q, res);
    return res;
}

template<typename T> Queue<T> Queue<T>::operator+=(const Queue<T> &q)
{
    Queue<T> res;
    copyFromTo(q, res);
    copyFromTo(res, *this);
    return *this;
}

template<typename T> Queue<T>& Queue<T>::operator= (const Queue<T> &q)
{
    // Проверка на самоприсваивание
    if (this != &q)
    {
        clear();
        copyFromTo(q, *this);
    }
    return *this;
}

template<typename T> void Queue<T>::copyFromTo(const Queue<T> &q, Queue<T> &res)
{
    auto node = q._front;
    while (node)
    {
        res.push(node->data());
        node = node->_next;
    }
}

#endif // QUEUE_H
