#ifndef LIST_H
#define LIST_H

#include <cassert>

#include "absadapter.hpp"
#include "node/node_dll.hpp"

namespace stt
{

template<typename T>
class List: public AbsLineAdapter<T>
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

    void push_back(T data)  override;
    void push_front(T data) override;
    T pop_front() override;
    T pop_back()  override;
    T front()     override;
    T back()      override;
    void insert(uint32_t pos, T data) override;
    uint32_t size() const override;
    void clear() override;
    void flip()  override;

    List<T> operator+(const List<T> &l);
    List<T> operator+=(const List<T> &l);
    List<T>& operator= (const List<T> &l);

    T& operator[] (const uint32_t index);

protected:
    void copy_from_to(const List<T> &l, List<T> &res);
    void push_first_el(T data);
    NodeDLL<T> *node(const uint32_t pos);
};

template<typename T>
List<T>::List() :
    _front(nullptr)
  , _back(nullptr)
  , AbsLineAdapter<T>()
{

}

template<typename T>
List<T>::List(const List<T> &copy) :
   List()
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
    if(AbsLineAdapter<T>::empty())
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
    if(AbsLineAdapter<T>::empty())
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
    if(pos >= size())
        return;
    auto node_after = node(pos);
    NodeDLL<T> *node = new NodeDLL<T>(data, node_after->_prev, node_after);
    if(node_after->_prev)
        node_after->_prev->_next = node;
    node_after->_prev = node;
    if(pos == 0)
        _front = node;
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
    if(AbsLineAdapter<T>::empty())
        return;
    auto node = _front;
    while (node)
    {
        node->swap_direction();
        node = node->_prev;
    }
    node = _back;
    _back = _front;
    _front = node;
}

template<typename T> void List<T>::push_first_el(T data)
{
    _front = new NodeDLL<T>(data);
    _back = _front;
}

template<typename T> NodeDLL<T>* List<T>::node(const uint32_t pos)
{
    auto node = _front;
    uint32_t current_id = 0;
    while (current_id != pos)
    {
        node = node->_next;
        current_id++;
    }
    return node;
}

template<typename T> List<T> List<T>::operator+(const List<T> &obj)
{
    List<T> res;
    copy_from_to(*this, res);
    copy_from_to(obj, res);
    return res;
}

template<typename T> List<T> List<T>::operator+=(const List<T> &obj)
{
    List<T> res;
    copy_from_to(obj, res);
    copy_from_to(res, *this);
    return *this;
}

template<typename T> List<T>& List<T>::operator= (const List<T> &obj)
{
    // Проверка на самоприсваивание
    if (this != &obj)
    {
        clear();
        copy_from_to(obj, *this);
    }
    return *this;
}

template<typename T> T& List<T>::operator[] (const uint32_t index)
{
    assert(index < size());
    return *(node(index)->_data);
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

}
#endif // LIST_H
