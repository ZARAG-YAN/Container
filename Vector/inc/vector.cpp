#include "vector.hpp"
#include <iostream>
#include <math.h>
#include <assert.h>
#include <cstdlib>

//constructors
template <class T>
vector<T>::vector()
{
  arr = nullptr;
  m_size = 0;
  m_capacity = 8;
}

template <class T>
vector<T>::vector(int s, T v )
 : arr(nullptr)
 , m_size(s)
{
    v = 0;
    m_capacity = 8;
    if (m_size > m_capacity) {
        capacity(m_size);
        arr = new T[m_capacity];
        assert(arr);
        for (int i = 0; i < m_size; ++i) {
            arr[i] = v;
        }
    } else {
        arr = new T[m_capacity];
        assert(arr);
        for (int i = 0; i < m_size; ++i) {
            arr[i] = v;
        }
    }
}

template <class T>
vector<T>::vector(const vector<T>& o)
{
    m_capacity = o.m_capacity;
    m_size = o.m_size;
    arr = new T[m_capacity];
    assert(arr);
    for (int i = 0; i < m_size; ++i) {
        arr[i] = o.arr[i];
    }
}

template <class T>
vector<T>::~vector()
{
    delete[] arr;
    arr = nullptr;
}

//other methods
template <class T>
void vector<T>::print_vector() const
{
    for (int i = 0; i < m_size; ++i) {
        std::cout << arr[i] <<" ";
    }
    std::cout << std::endl;
}

template <class T>
int vector<T>:: get_size() const
{
    return m_size;
}

template <class T>
int vector<T>:: get_capacity() const
{
    return m_capacity;
}

//operators
template <class T>
T& vector<T>::operator[] (int i)
{
    return arr[i];
}

template <class T>
const T& vector<T>::operator[] (int i) const
{
    return arr[i];
}

template <class T>
T& vector<T>::at(int i)
{
    if (i < 0 || i > m_size) {
    throw std::out_of_range("Index is out of range");
    }
    return arr[i];
}

template <class T>
std::ostream& operator<< (std::ostream& out, const vector<T>& vec)
{
    out << "[ ";
    for (int i = 0; i < vec.m_size; ++i) {
    out << vec[i] << ", ";
    }
    out << "]"<< std::endl;
    return out;
}

template <class T>
vector<T>& vector<T>:: operator= (const vector<T>& o)
{
   if (&o == this) {
        return *this;
    } else {
        delete [] arr;
        this -> m_size = o.m_size;
	    this -> m_capacity = o.m_capacity;
        this -> arr = new T[this -> m_size];
        for (int i = 0; i < m_size; i++) {
            this -> arr[i] = o.arr[i];
        }
        return *this;
    }
}

template <class T>
bool vector<T>::operator== (vector<T> o)
{
    if (m_size != o.m_size) {
        return false;
    } else {
        for (int i = 0; i < m_size; ++i) {
            if (arr[i] != o.arr[i]) {
                return false;
            }
        }
    } return true;
}

//other methods
template <class T>
void vector<T>::clear()
{
    if (empty()) {
        return;
    } else {
        T* clear_arr = new T[m_capacity];
        assert(clear_arr);
        delete [] arr;
        arr = clear_arr;
    }
}

template <class T>
bool vector<T>:: empty() const
{
    if (0 == m_size) {
        return true;
    } else {
        return false;
    }
}


template <class T>
void vector<T>::resize(int i)
{
    if (i < 0) {
        throw std::out_of_range("Index is out of range");
        std::cout << std::endl;
        return;
    }
    T *new_arr = new T[m_capacity];
    if (i >= m_capacity) {
        capacity(i);
        T *new_arr = new T[m_capacity];
        for (int j = m_size; j < i; j++) {
            new_arr[j] = 0;
        }
        for (int j = 0; j < i; j++) {
            new_arr[j] = arr[j];
        }
    } else if (i >= m_size) {
             for (int j = m_size; j < i; j++) {
                new_arr[j] = 0;
             }
             for (int j = 0; j < m_size; j++) {
                new_arr[j] = arr[j];
             }
           } else {
                for (int j = 0; j < i; j++) {
                   new_arr[j] = arr[j];
                }
           }
    m_size = i;
    delete [] arr;
    arr = new_arr;
}
//insertion and deleteion
template <class T>
void vector<T>::insert(int p, const T v)
{
    resize(m_size + 1);
    shift(p, 0);
    for (int i = p; i < p + 1; ++i) {
        arr[i] = v;
    }
}

template <class T>
void vector<T>::erase(int p)
{
   shift(p, 1);
   resize(m_size - 1);
}


template <class T>
void vector<T>::push_back(const T v)
{
    resize(++m_size);
    arr[m_size - 1] = v;
}

template <class T>
void vector<T>:: pop_back()
{
    assert(m_size = 0);
    --m_size;
}

//private functions
template <class T>
int vector<T>::capacity(int s)
{
    double n = log2(s);
        if (n - int(n) == 0) {
            m_capacity = pow(2,n);
        } else {
            ++n;
            m_capacity = pow(2,int(n));
        }
    return m_capacity;
}

template <class T>
void vector<T>::shift(int p, int d)
{
    if (1 == d) {
        for (int i = m_size - 1; i > p - 1; ++i) {
            arr[i] = arr[i - 1];
        }
    } else if (0 == d) {
             for (int i = p; i < m_size; ++i) {
            arr[i] = arr[i + 1];
        }
    }
}

