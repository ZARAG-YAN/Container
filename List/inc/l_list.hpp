#ifndef L_LIST_H
#define L_LIST_H
#include <iostream>

struct node
{
    int data;
    node* next;
};

class l_list
{
private:
	node* head;
	node* tail;
    int m_size;

public:
// constructors
	l_list();
	~l_list();

//other methods.
	int get_size();
	bool is_empty();
	void reverse();
	void display();

//creator and deletion functions.

	void insert_front(const int);//push_front()
	void insert_posistion(const int, const int);
	void insert_back(const int);//push_back()

	void delete_front();//pop_front()
	void delete_posistion(const int);
	void delete_back();//pop_back()
};
#endif //L_LIST_H
