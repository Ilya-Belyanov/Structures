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

#endif // NODE_H
