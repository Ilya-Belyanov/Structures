#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "absadapter.hpp"
#include "node/node_dll.hpp"

template<typename T>
class Vector: public AbsLineAdapter<T>
{
    const uint32_t _start_size;
    const float _multi_size;

    T *_array;
    uint32_t _capacity;
    uint32_t _size;

public:
    Vector();
    Vector(const Vector<T> &copy);
    template<typename First, typename... Args>
    Vector(First first, Args... args) : Vector()
    {
        push_back(first);
        uint32_t l = sizeof... (Args);
        T items [l] { args... };
        for(uint32_t i = 0; i < l; i++)
            push_back(items[i]);
    }

    ~Vector();

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

    Vector<T> operator+(const Vector<T> &l);
    Vector<T> operator+=(const Vector<T> &l);
    Vector<T>& operator= (const Vector<T> &l);

protected:
    void copy_from_to(const Vector<T> &l, Vector<T> &res);
    void up_memory();
    int last_index();
};

template<typename T>
Vector<T>::Vector() :
   AbsLineAdapter<T>()
 , _start_size(100)
 , _multi_size(1.5)
 , _array(new T[_start_size])
 , _capacity(_start_size)
 , _size(0)
{

}

template<typename T>
Vector<T>::Vector(const Vector<T> &copy) :
   Vector()
{
    copy_from_to(copy, *this);
}

template<typename T>
Vector<T>::~Vector()
{
    delete[] _array;
    _array = nullptr;
}

template<typename T> void Vector<T>::push_back(T data)
{
    if(_size >= _capacity)
        up_memory();
    _array[_size++] = data;
}

template<typename T> void Vector<T>::push_front(T data)
{
    if(_size >= _capacity)
        up_memory();
    for(int i = _size; i >= 1; i--)
        _array[i] = _array[i - 1];
    _array[0] = data;
    _size++;
}

template<typename T> T Vector<T>::pop_front()
{
    if(AbsLineAdapter<T>::empty())
        return T();
    T data = front();
    for(uint32_t i = 1; i < _size; i++)
        _array[i - 1] = _array[i];
    _size--;
    return data;
}

template<typename T> T Vector<T>::pop_back()
{
    if(AbsLineAdapter<T>::empty())
        return T();
    T data = back();
    _size--;
    return data;
}

template<typename T> T Vector<T>::front()
{
    if(_size != 0)
        return _array[0];
    return T();
}

template<typename T> T Vector<T>::back()
{
    if(_size != 0)
        return _array[_size - 1];
    return T();
}

template<typename T> void Vector<T>::insert(uint32_t pos, T data)
{
    if(pos >= _size)
        return;
    _array[pos] = data;
}

template<typename T> void Vector<T>::clear()
{
    _size = 0;
}

template<typename T> uint32_t Vector<T>::size() const
{
    return _size;
}

template<typename T> void Vector<T>::flip()
{
    if(AbsLineAdapter<T>::empty())
        return;
    uint32_t start_id = 0;
    uint32_t end_id = last_index();
    for(uint32_t i = 0; i < float(_size) / 2.0; i++)
    {
        T data = _array[start_id];
        _array[start_id++] = _array[end_id];
        _array[end_id--] = data;
    }
}

template<typename T> Vector<T> Vector<T>::operator+(const Vector<T> &obj)
{
    Vector<T> res;
    copy_from_to(*this, res);
    copy_from_to(obj, res);
    return res;
}

template<typename T> Vector<T> Vector<T>::operator+=(const Vector<T> &obj)
{
    Vector<T> res;
    copy_from_to(obj, res);
    copy_from_to(res, *this);
    return *this;
}

template<typename T> Vector<T>& Vector<T>::operator= (const Vector<T> &obj)
{
    // Проверка на самоприсваивание
    if (this != &obj)
    {
        clear();
        copy_from_to(obj, *this);
    }
    return *this;
}

template<typename T> void Vector<T>::copy_from_to(const Vector<T> &l, Vector<T> &res)
{
    for(uint32_t i = 0; i < l._size; i++)
        res.push_back(l._array[i]);
}

template<typename T> void Vector<T>::up_memory()
{
    _capacity *= _multi_size;
    T *time_array = new T[_capacity];
    for(uint32_t i = 0; i < _size; i++)
        time_array[i] = _array[i];
    delete [] _array;
    _array = time_array;
}

template<typename T> int Vector<T>::last_index()
{
    return int(_size) - 1;
}

#endif // VECTOR_HPP
