#include <iostream>
#include "l_list.hpp"

// constructors.
l_list::l_list(int item)
 : head(nullptr)
 , tail(nullptr)
 , m_size(0)
{
    head->data = item;
    head->next = NULL;
    tail->data = head->data;
    tail->next = NULL;
    ++m_size;
}

l_list::~l_list()
{
    tail = NULL;
    node* temp = head->next;
    while (temp) {
        delete head;
	head = temp;      
    }
}

//other methods.

int l_list:: get_size() 
{
    return m_size;
}

bool l_list::is_empty()
{
    if (head == NULL) {
        return true;
    } return false;
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
    node* temp = new node;
    temp = head;
    while (temp != NULL) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
}
//creator and deletion functions.

void l_list::insert_start(const int item)
{
    node* temp = new node;
    temp->data = item;
    temp->next = head;
    head = temp;
    ++m_size;
}

void l_list::insert_posistion(const int pos, const int item)
{  
    node* temp = new node;
    node* curr = new node;
    node* prev = new node;
    curr = head;
    for(int i = 1; i < pos; ++i) {
        prev = curr;
        curr = curr->next;
    }
    temp->data = item;
    prev->next = temp;
    temp->next = curr;
}

void l_list::insert_end(int item) //push_back()
{
    node* temp = new node;
    temp->data = item;
    temp->next = NULL;
    if (head == NULL) {
        head = temp;   
	tail = temp;
	temp = NULL;
    } else {
	tail->next = temp;
	tail = temp;
    } ++m_size;
}

void l_list::delete_start()
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
    int i = 1;
    while (i < pos) {
        prev = curr;
        curr = curr->next;
        ++i;
    }
    prev->next = curr->next;
    --m_size;
}

void l_list::delete_end()//pop_back()
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

