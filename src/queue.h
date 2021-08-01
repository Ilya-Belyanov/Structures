#ifndef QUEQU_H
#define QUEQU_H

template<typename T>
class Queue
{
public:
    Queue();
    ~Queue();

    void push(T data);
    T pop();
    T front();
    T back();
    bool empty();
};

#endif // QUEQU_H
