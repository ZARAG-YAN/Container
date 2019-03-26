#include <iostream>
#include <list.hpp>
//#include <l_list.cpp>

int main()
{
    list<int> l1;
    for (int i = 0; i < 5; ++i) {
        l1.insert_front(2*i);
    }
    l1.display();
    l1.insert_position(5,77);
    l1.delete_position(2);
    l1.reverse();
    l1.display();
    return 0;
}
