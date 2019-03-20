#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <assert.h>

class array
{

private:
	int* arr;
	int size;
public:
        void shift(int, int);


	array() { arr = nullptr; size = 0; }
	array(int n, int v = 0);

	array(const array& p);
	~array();
	void print_array() const;
        int size_() const { return size; }

	int& operator[] (int i);
	const int& operator[] (int i) const { return arr[i]; }
        int& at(int i);

	array& operator= (const array& p);
	bool operator== (array i);
        
        int array_size()const;
        void resize(int i);
        int capacity();
	
	void empty()const;

	void insert(int p, int v);
	void erase(int p);

	void push_back(int);
	void pop_back();

};

#endif // ARRAY_H
