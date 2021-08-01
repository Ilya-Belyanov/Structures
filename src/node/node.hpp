#ifndef NODE_H
#define NODE_H

template<typename T>
struct Node {
    T *_data;
    Node();
    Node(T data);

    virtual ~Node();
    const T& data() const;
};

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
#endif // NODE_H
