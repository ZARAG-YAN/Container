#ifndef L_LIST_H
#define L_LIST_H
#include <iostream>
template <class T>
struct node
{
    <T> data;
    node* next;
};

template <class T>
class list
{
    private:
        node<T>* head;
        node<T>* tail;
        T m_size;

    public:
        // constructors
        list();
        list(const list&);
        ~list();
        //operators.
        list& operator= (const list&);

        //other methods.
        int get_size();
        bool is_empty();
        void reverse();
        void display();

        //creator and deletion functions.

        void insert_front(const T&);//push_front()
        void insert_position(const int&, const T&);
        void insert_back(const T&);//push_back()

        void delete_front();//pop_front()
        void delete_position(const int&);
        void delete_back();//pop_back()
};
#include "list.tpp"
#endif //L_LIST_H
