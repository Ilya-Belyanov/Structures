#ifndef STACK_HPP
#define STACK_HPP

#include "queue.hpp"

template<typename T, template <typename> class A = List>
class Stack : public Queue<T, A>
{

public:
    Stack();
    Stack(const Stack<T, A> &copy);

    template<typename First, typename... Args>
    Stack(First first, Args... args) :
        Queue<T, A>(first, args...)
    {}

    void push(T data) override;

    Stack<T, A> operator+(const Stack<T, A> &q);
    Stack<T, A> operator+=(const Stack<T, A> &qr);
    Stack<T, A>& operator= (const Stack<T, A> &q);
};



template<typename T, template <typename> class A>
Stack<T, A>::Stack() :
    Queue<T, A>()
{

}

template<typename T, template <typename> class A>
Stack<T, A>::Stack(const Stack<T, A> &copy) :
  Queue<T, A>(copy.adapter)
{
}

template<typename T, template <typename> class A>
void Stack<T, A>::push(T data)
{
    Queue<T, A>::adapter.push_front(data);
}

template<typename T, template <typename> class A>
Stack<T, A> Stack<T, A>::operator+(const Stack<T, A> &q)
{
    Stack<T, A> res;
    res.adapter = Queue<T, A>::adapter + q.adapter;
    return res;
}

template<typename T, template <typename> class A>
Stack<T, A> Stack<T, A>::operator+=(const Stack<T, A> &q)
{
    Queue<T, A>::adapter += q.adapter;
    return *this;
}

template<typename T, template <typename> class A>
Stack<T, A>& Stack<T, A>::operator= (const Stack<T, A> &q)
{
    Queue<T, A>::adapter = q.adapter;
    return *this;
}

#endif // STACK_HPP
