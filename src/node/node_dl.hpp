#ifndef NODE_DL_HPP
#define NODE_DL_HPP

#include "node.hpp"

namespace stt
{

template<typename T>
struct NodeDL: public Node<T>
{
    NodeDL *_next;
    NodeDL(T data, NodeDL *next = nullptr);

    ~NodeDL();
};

template<typename T>
NodeDL<T>::NodeDL(T data, NodeDL *next):
    Node<T>(data),
    _next(next)
{
}

template<typename T> NodeDL<T>::~NodeDL()
{
    _next = nullptr;
}

}
#endif // NODE_DL_HPP
