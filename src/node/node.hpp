#ifndef NODE_H
#define NODE_H

#include <iostream>

namespace stt
{

template<typename T>
struct Node {
    T *_data;
    Node(T data);

    virtual ~Node();
    const T& data() const;
};

template<typename T> Node<T>::Node(T data): _data(new T(data)){}

template<typename T> Node<T>::~Node()
{
    delete _data;
}

template<typename T> const T &Node<T>::data() const
{
    return *_data;
}

}
#endif // NODE_H
