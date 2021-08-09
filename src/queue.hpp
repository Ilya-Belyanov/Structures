#ifndef QUEUE_H
#define QUEUE_H

#include "list.hpp"

template<typename T, template <typename> class A = List>
class Queue
{
    A<T> adapter;

public:
    Queue();
    Queue(const Queue<T, A> &copy);

    template<typename First, typename... Args>
    Queue(First first, Args... args) :
      adapter(first, args...)
    {
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

    Queue<T, A> operator+(const Queue<T, A> &q);
    Queue<T, A> operator+=(const Queue<T, A> &qr);
    Queue<T, A>& operator= (const Queue<T, A> &q);
};

template<typename T, template <typename> class A>
Queue<T, A>::Queue() :
    adapter()
{

}

template<typename T, template <typename> class A>
Queue<T, A>::Queue(const Queue<T, A> &copy) :
  adapter(copy.adapter)
{
}

template<typename T, template <typename> class A>
Queue<T, A>::~Queue()
{
    adapter.clear();
}

template<typename T, template <typename> class A>
void Queue<T, A>::push(T data)
{
    adapter.push_back(data);
}

template<typename T, template <typename> class A>
T Queue<T, A>::pop()
{
    return adapter.pop_front();
}

template<typename T, template <typename> class A>
T Queue<T, A>::front()
{
    return adapter.front();
}

template<typename T, template <typename> class A>
T Queue<T, A>::back()
{
    return adapter.back();
}

template<typename T, template <typename> class A>
bool Queue<T, A>::empty()
{
    return adapter.empty();
}

template<typename T, template <typename> class A>
void Queue<T, A>::clear()
{
    adapter.clear();
}

template<typename T, template <typename> class A>
uint32_t Queue<T, A>::size() const
{
    return adapter.size();
}

template<typename T, template <typename> class A>
void Queue<T, A>::flip()
{
    /*
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
    */
    adapter.flip();
}

template<typename T, template <typename> class A>
Queue<T, A> Queue<T, A>::operator+(const Queue<T, A> &q)
{
    Queue<T, A> res;
    res.adapter = adapter + q.adapter;
    return res;
}

template<typename T, template <typename> class A>
Queue<T, A> Queue<T, A>::operator+=(const Queue<T, A> &q)
{
    adapter += q.adapter;
    return *this;
}

template<typename T, template <typename> class A>
Queue<T, A>& Queue<T, A>::operator= (const Queue<T, A> &q)
{
    adapter = q.adapter;
    return *this;
}

#endif // QUEUE_H
