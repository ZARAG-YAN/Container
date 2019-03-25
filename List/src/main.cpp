#include <iostream>
#include <list.hpp>
//#include <l_list.cpp>

int main()
{
    list<int> l1;
    list<int> a;
    //std::cout <<"make l1 copy\n";
    //a.display();
    //std::cout <<"your copy result\n";
    for (int i = 1; i <= 0 ; ++i) {
        l1.insert_back(i);
    }
        a = l1;
    a.display();
    /*std::cout <<"siez = "<<l1.get_size();
    std::cout << std::endl;
    std::cout <<"l1.display\n";
    l1.display();
    std::cout << std::endl;
    list b = l1;
    std::cout <<"b.size = "<< b.get_size();
    std::cout << std::endl;
    std::cout<<"display b\n";
    b.display();*/
    return 0;
}
