#include <iostream>
#include <l_list.hpp>
//#include <l_list.cpp>

int main()
{
  //  int num = 0;
    l_list list;
    for (int i = 0; i <= 8; ++i) {
        list.insert_back(i);
    }
    std::cout <<"siez = "<<list.get_size();
    list.display();
    std::cout <<"\ninsert pos\n";
    list.insert_position(4,55);
    list.delete_position(4);
    list.delete_position(4);
    list.display();
    std::cout <<"siez = "<<list.get_size();
    return 0;
}
