#include <iostream>
#include <l_list.hpp>
//#include <l_list.cpp>

int main()
{
  //  int num = 0;
    l_list list;
    std::cout <<"Insert numbers\n";
    for (int i = 0; i < 8; ++i) {
        list.insert_front(i);
    }
    std::cout <<"size = "<<list.get_size() <<"\n";
    std::cout <<"\n---Delete---";
    list.display();
    list.delete_front();
    list.delete_back();
    std::cout <<"\n---Delete---\n";
    list.display();
    std::cout <<"\nIs_empty  "<< list.is_empty();
    std::cout <<"\nsize = "<<list.get_size() <<"\n";
    std::cout <<"Reverse\n";
    list.reverse();
    list.display();
    std::cout <<" before display\n";

    return 0;
}
