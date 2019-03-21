#include <iostream>
#include "l_list.hpp"
#include <assert.h>

// constructors.

/*l_list::l_list(int item)
 : head(nullptr)
 , tail(nullptr)
 , m_size(0)
{
    head->data = item;
    head->next = NULL;
    tail = head;
    ++m_size;
}
*/
l_list::l_list()
{
    head = nullptr;
    tail = nullptr;
    m_size = 0;
}

l_list::~l_list()
{
    node* temp = head;
    while (temp) {
        head = head -> next;
        delete temp;
        temp = head;
    }
    delete head;
}

//other methods.

int l_list:: get_size()
{
    return m_size;
}

bool l_list::is_empty()
{
    return head == NULL;
}

void l_list::reverse()
{
    node* tmp = new node;
    node* curr = new node;
    node* prev = new node;
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

void l_list::display()
{
    std::cout <<"Display ";
    node* temp = head;
    while (temp != NULL) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
}
//creator and deletion functions.


void l_list::insert_front(const int item)
{
    node* temp = new node;
    temp -> data = item;
    temp -> next = head;
    head = temp;
    ++m_size;
}

void l_list::insert_posistion(const int pos, const int item)
{
    node* temp = new node;
    node* curr = new node;
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

void l_list::insert_back(int item) //push_back()
{
    node* temp = new node;
    temp->data = item;
    temp->next = NULL;
    if (head == NULL) {
        head = tail = temp;
	    temp = NULL;
    } else {
	    tail->next = temp;
	    tail = temp;
    } ++m_size;
}

void l_list::delete_front()
{
    node* temp = new node;
    temp = head;
    head = head->next;
    --m_size;
    delete temp;
}


void l_list::delete_posistion(const int pos)
{
    node* prev = new node;
    node* curr = new node;
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

void l_list::delete_back()//pop_back()
{
    node* prev = new node;
    node* curr = new node;
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

