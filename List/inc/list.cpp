#include <iostream>
#include "list.hpp"
#include <assert.h>
template <typename T>
// constructors.

list<T>::list()
{
    head = nullptr;
    tail = nullptr;
    m_size = 0;
}

template <typename T>
list<T>::list(const list& other)
{
    if (other.head == NULL) {
        head = tail = NULL;
    } else {
        head = new node<T>;
        tail = head;
        head->data = other.head->data;

        node<T>* tmp = other.head->next;
        while (tmp){
            insert_back(tmp.data);
            tmp = tmp.next;
        }
    }
    m_size = other.m_size;
}


template <typename T>
list<T>::~list()
{
    node<T>* temp = head;
    while (temp) {
        head = head -> next;
        delete temp;
        temp = head;
    }
    delete head;
}

// operators

template <typename T>
list<T>& list<T>::operator= (const list& other)
{
    node<T>* temp = head;
    while (temp) {
        head = head -> next;
        delete temp;
        temp = head;
    }
    delete head;
    if (other.head == NULL) {
        head = tail = NULL;
    } else {
        head = new node<T>;
        tail = head;
        head->data = other.head->data;

        node<T>* tmp = other.head->next;
        while (tmp){
            insert_back(tmp->data);
            tmp = tmp->next;
        }
    }
    m_size = other.m_size;
    return *this;
}

//other methods.

template <typename T>
int list<T>:: get_size()
{
    return m_size;
}

template <typename T>
bool list<T>::is_empty()
{
    return head == NULL;
}

template <typename T>
void list<T>::reverse()
{
    //DONE
    std::cout <<"\nReverse: ";
    node<T>* tmp = new node<T>;
    node<T>* curr = new node<T>;
    node<T>* prev = new node<T>;
    curr = head;
    prev = NULL;
    while (curr != NULL) {
        tmp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = tmp;
    }
    head = prev;
}

template <typename T>
void list<T>::display()
{
    //DONE
    if (head == NULL) {
        std::cout <<"Empty\n";
    }
    node<T>* temp = head;
    while (temp != NULL) {
        std::cout << temp.data << " ";
        temp = temp.next;
    }
    std::cout << std::endl;
}

//creator and deletion functions.

template <typename T>
void list<T>::insert_front(T item)
{
    //DONE
    node<T>* temp = new node<T>;
    temp -> data = item;
    temp -> next = head;
    head = temp;
    ++m_size;
}

template <typename T>
void list<T>::insert_position(int pos, T item)
{
    //DONE-but remove that position's value.
    node<T>* temp = new node<T>;
    node<T>* curr = new node<T>;
    curr = head;
    if (pos > m_size) {
        std::cout <<"Your input out of range\n";
    }
    for(int i = 1; i < pos; ++i) {
        curr = curr->next;
    }
    temp -> data = item;
    temp -> next = curr -> next;
    curr -> next = temp;
    ++m_size;
}

template <typename T>
void list<T>::insert_back(T item) //push_back()
{
    //DONE
    node<T>* temp = new node<T>;
    temp -> data = item;
    temp -> next = NULL;
    if (head == NULL) {
        head = tail = temp;
	    temp = NULL;
    } else {
	    tail -> next = temp;
	    tail = temp;
    } ++m_size;
}

template <typename T>
void list<T>::delete_front()
{
    //DONE
    node<T>* temp = new node<T>;
    temp = head;
    head = head->next;
    --m_size;
    delete temp;
}

template <typename T>
void list<T>::delete_position(const int& pos)
{
    //DONE
    node<T>* prev = new node<T>;
    node<T>* curr = new node<T>;
    curr = head;
    if (pos > m_size) {
        std::cout<<"Your input is out of range\n";
        return;
    }
    int i = 1;
    while (i < pos) {
        prev = curr;
        curr = curr->next;
        ++i;
    }
    prev->next = curr->next;
    --m_size;
}

template <typename T>
void list<T>::delete_back() //pop_back()
{
    //DONE
    node<T>* prev = new node<T>;
    node<T>* curr = new node<T>;
    curr = head;
    while (curr->next != NULL) {
        prev = curr;
        curr = curr->next;
    }
    tail = prev;
    tail->next = NULL;
    --m_size;
    delete curr;
}

