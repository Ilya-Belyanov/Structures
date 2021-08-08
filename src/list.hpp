#ifndef LIST_H
#define LIST_H

#include "node/node_dll.hpp"

template<typename T>
class List
{
    NodeDLL<T> *_front;
    NodeDLL<T> *_back;

public:
    List();
    List(const List<T> &copy);

    template<typename First, typename... Args>
    List(First first, Args... args) : List()
    {
        push_back(first);
        uint32_t l = sizeof... (Args);
        T items [l] { args... };
        for(uint32_t i = 0; i < l; i++)
            push_back(items[i]);
    }

    ~List();

    void push_back(T data);
    void push_front(T data);
    T pop_front();
    T pop_back();
    T front();
    T back();
    void insert(uint32_t pos, T data);
    bool empty();
    void clear();
    void flip();
    uint32_t size() const;

    List<T> operator+(const List<T> &l);
    List<T> operator+=(const List<T> &lr);
    List<T>& operator= (const List<T> &l);

private:
    void push_first_el(T data);
    void copy_from_to(const List<T> &l, List<T> &res);
};

template<typename T>
List<T>::List() :
    _front(nullptr)
  , _back(nullptr)
{

}

template<typename T>
List<T>::List(const List<T> &copy) :
    _front(nullptr)
  , _back(nullptr)
{
    copy_from_to(copy, *this);
}

template<typename T>
List<T>::~List()
{
    clear();
}

template<typename T> void List<T>::push_back(T data)
{
    if(empty())
        push_first_el(data);
    else
    {
        auto node = _back;
        _back = new NodeDLL<T>(data, node);
        node->_next = _back;
    }
}

template<typename T> void List<T>::push_front(T data)
{
    if(empty())
        push_first_el(data);
    else
    {
        auto node = _front;
        _front = new NodeDLL<T>(data, nullptr, node);
        node->_prev = _front;
    }
}

template<typename T> T List<T>::pop_front()
{
    if(_front)
    {
        T data = front();
        auto node = _front;
        _front = _front->_next;
        if(_front)
            _front->_prev = nullptr;
        else
            _back = nullptr;
        delete node;
        return data;
    }
    return T();
}

template<typename T> T List<T>::pop_back()
{
    if(_back)
    {
        T data = back();
        auto node = _back;
        _back = _back->_prev;
        if(_back)
            _back->_next = nullptr;
        else
            _front = nullptr;
        delete node;
        return data;
    }
    return T();
}

template<typename T> T List<T>::front()
{
    if(_front)
        return _front->data();
    return T();
}

template<typename T> T List<T>::back()
{
    if(_back)
        return _back->data();
    return T();
}

template<typename T> void List<T>::insert(uint32_t pos, T data)
{
    // TODO
}

template<typename T> bool List<T>::empty()
{
    return size() == 0;
}

template<typename T> void List<T>::clear()
{
    while(_front)
        pop_front();
}

template<typename T> uint32_t List<T>::size() const
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

template<typename T> void List<T>::flip()
{
    if(empty())
        return;
    //TODO
}

template<typename T> List<T> List<T>::operator+(const List<T> &l)
{
    List<T> res;
    copy_from_to(*this, res);
    copy_from_to(l, res);
    return res;
}

template<typename T> List<T> List<T>::operator+=(const List<T> &lr)
{
    List<T> res;
    copy_from_to(lr, res);
    copy_from_to(res, *this);
    return *this;
}

template<typename T> List<T>& List<T>::operator= (const List<T> &l)
{
    // Проверка на самоприсваивание
    if (this != &l)
    {
        clear();
        copy_from_to(l, *this);
    }
    return *this;
}

template<typename T> void List<T>::push_first_el(T data)
{
    _front = new NodeDLL<T>(data);
    _back = _front;
}

template<typename T> void List<T>::copy_from_to(const List<T> &l, List<T> &res)
{
    auto node = l._front;
    while (node)
    {
        res.push_back(node->data());
        node = node->_next;
    }
}
#endif // LIST_H
