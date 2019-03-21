#include <iostream>
#include <l_list.hpp>
//#include <l_list.cpp>

int main()
{
    l_list list;
    list.insert_front(444);
    std::cout <<"aaaaa\n";
   // list.insert_front(7);

    std::cout <<"size = "<<list.get_size() <<"\n";
    std::cout <<"bbbbb\n";
    list.display();

    return 0;
}
