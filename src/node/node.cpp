#include "node.h"

template<typename T> Node<T>::Node(): _data(T()){}
template<typename T> Node<T>::Node(T data): _data(new T(data)){}

template<typename T> Node<T>::~Node()
{
    delete _data;
    _data = nullptr;
}

template<typename T> const T& Node<T>::data() const
{
    return *_data;
}
