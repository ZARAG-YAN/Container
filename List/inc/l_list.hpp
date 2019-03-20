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
        int m_size;
	node* head;
	node* tail;
	
    public:
// constructors
	l_list()
	{
	  head = nullptr;
	  tail = nullptr;
	  m_size = 0;
	}

	l_list(int);
	~l_list();

//other methods.
	int get_size();
	bool is_empty();
	void reverse();
	void display();

//creator and deletion functions.

	void insert_start(const int);//push_front()
	void insert_posistion(const int, const int);
	void insert_end(const int);//push_back()

	void delete_start();//pop-front()
	void delete_posistion(const int);
	void delete_end();//pop_back()
};
#endif //L_LIST_H
