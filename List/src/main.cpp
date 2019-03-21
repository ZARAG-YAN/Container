#include <iostream>
#include <l_list.hpp>
//#include <l_list.cpp>

int main()
{
    int num = 0;
    l_list list;
    list.insert_front(1);
    std::cout <<"Input number \n";
    std::cin >> num;
    list.insert_front(num);
    list.insert_front(3);
  //  list.insert_back(444);
    std::cout <<"size = "<<list.get_size() <<"\n";
    list.display();
    std::cout <<" before display\n";

    return 0;
}
