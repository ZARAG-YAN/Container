#include "array.hpp"
#include <cstring>
#include <math.h>
array::array(int n, int v)
 : arr(nullptr)
 , size(0)
{
    arr = new int[n];
    assert(arr);
    for (int i = 0; i < n; ++i) {
	    arr[i] = v;
    }
    size = n;
}

array::array(const array& p)
 : arr(nullptr)
 , size(0)
{
    size = p.size;
    arr = new int [size];
    for (int i = 0; i < size; ++i) {
        arr[i] = p.arr[i];
    }
}

array::~array()
{
	delete [] arr;
	arr = nullptr;
}

void array::print_array() const
{
	for (int i = 0; i < size; i++) {
	    std::cout << arr[i] << "  ";
	}
	std::cout << std::endl;
}


int& array::operator[](int i)
{
    return arr[i];
}

int& array::at(int i)
{
	if(i < 0 || i >= size) {
        throw std::out_of_range("Index is out of range");
    }
    return arr[i];
}

array& array::operator=(const array& p)
{
    if (this == &p) {
	return *this;
    } else {
        delete [] arr;
	this->size = p.size;
	this->arr = new int[this->size];
	for (int i = 0; i < size; i++) {
	    this->arr[i] = p.arr[i];
	}
	return *this;
    }
}

bool array::operator==(array i)
{
    if (size != i.size) {
        return false;
    } else {
        if (*arr == *(i.arr)) {
	    return true;
        } else {
            return false;
        }
   }
}

void array::resize(int i)
{
    if (i < 0) {
        std::cout << "Index is out of range" << std::endl;
	    return;
    }
    int *new_arr = new int[i];
    if (i >= size) {
	    for (int j = size; j < i; j++) {
		    new_arr[j] = 0;
	    }
	    for(int j = 0; j < size; j++) {
		    new_arr[j] = arr[j];
	    }
    }
    else {
	    for(int j = 0; j < i; j++) {
		    new_arr[j] = arr[j];
	    }
    }
    size = i;
    delete [] arr;
    arr = new_arr;

}

void array::push_back(int v)
{
    resize(++size);
    arr[size - 1] = v;
}

void array::pop_back()
{
    resize(--size);
}

int array::capacity()
{
    int size1 = size;
    double n = log2(size);
        if (n - int(n) == 0) {
            size1 = pow(2,n);
        } else {
            ++n;
            size1 = pow(2,int(n));
        }
    return size1;
}

void array::shift(int p, int d)
{
    if (1 == d) {
        for (int i = size - 1; i > p - 1; ++i) {
            arr[i] = arr[i - 1];
        }
    } else if (0 == d) {
	     for (int i = p; i < size; ++i) {
            arr[i] = arr[i + 1];
        }
    }
}

int array::array_size()const
{
    return size;
}

void array::empty()const
{
   if( size == 0) {
       std::cout <<"TRUE\n";
   } else {
       std::cout <<"FALSE\n";
   }
}

void array::insert(int p)
{
    resize(size + 1);
    shift(p, 0);
    std::cout <<"Insert your number\n";
    for (int i = p; i < p + 1; ++i) {
        std::cin >> arr[i];
    }
}

void array::erase(int p)
{
   shift(p, 1);
   resize(size - 1);
}
