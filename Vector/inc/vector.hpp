#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <assert.h>
#include <cmath>

template <class T>
/*
 * @class vector to create vector.
 * */
class vector
{
    template <class U>
    friend std::ostream& operator<< (std::ostream& out, const vector<U>& vec);
    private:
        /*
         * @param arr - for array
         * @param m_size for vector size.
         * @param m_capacity for vector capacity.
         * */
        int* arr;
        int m_size;
        int m_capacity;

        void shift(int p, int d);
        int capacity(int s);

    public:
        /*
         * @fn vector
         * @brief vector class constructor.
         * */

        vector();
        vector(int, T);
        vector(const vector<T>&);
        ~vector();

        void print_vector() const;
        int get_size() const;
        int get_capacity() const;

        T& operator[] (int i);
        const T& operator[] (int i) const;
        T& at(int i);

        vector<T>& operator= (const vector<T>& );
        bool operator== (vector<T>);

        void clear();
        bool empty()const;

        void resize(int);
        void insert(int, const T);
        void erase(int);

        void push_back(const T);
        void pop_back();
};
#include "vector.tpp"
#endif // ARRAY_H
