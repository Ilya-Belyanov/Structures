#ifndef NODE_DLL_HPP
#define NODE_DLL_HPP

#include "node.hpp"

template<typename T>
struct NodeDLL : public Node<T> {
    NodeDLL<T> *_prev;
    NodeDLL<T> *_next;

    NodeDLL(T data, NodeDLL<T> *prev = nullptr, NodeDLL<T> *next = nullptr);

    ~NodeDLL();

    //void swap_direction();
};

template<typename T>
NodeDLL<T>::NodeDLL(T data, NodeDLL *prev, NodeDLL<T> *next):
    Node<T>(data),
    _prev(prev),
    _next(next)
{
}

template<typename T>
NodeDLL<T>::~NodeDLL() {
    _prev = nullptr;
    _next = nullptr;
}

#endif // NODE_DLL_HPP
