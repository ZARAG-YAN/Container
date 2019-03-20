#include <iostream>
#include <l_list.hpp>

int main()
{
    l_list list;
    /*for (int i =0; i < 4; ++i) {
        list.insert_end(i);    
    }*/
    //list.insert_start(4);
    list.insert_start(78);
    std::cout <<"size = "<<list.get_size() <<"\n";
    if (list.is_empty()) { 
        std::cout <<"empty \n";
    } else {
        std::cout <<"NOT empty \n";
    }
    list.insert_start(7777);
    //list.insert_start(7);
    std::cout <<"size = "<<list.get_size() <<"\n";
    std::cout <<"print ";
    list.display();

    return 0;
}
