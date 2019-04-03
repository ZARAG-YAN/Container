#include <iostream>
#include "BTree.hpp"
#include <cstdlib>
//#include <ctime>

int main ()
{
    BT<int> b;
   // srand(time(0));
    for (int i = 0; i <= 10; ++i) {
        int n = rand() % 60 + 1;
        b.insert(n);
    }
    std::cout << std::endl;
    std::cout <<"\nCount of nodes = "<< b.m_count;
    std::cout << std::endl;
    std::cout <<"\nInorder: ";
    b.inorder();
    std::cout << std::endl;

    //b.remove(44);
    b.remove(56);

    std::cout <<"\nCount of nodes = "<< b.m_count;
    std::cout << std::endl;


    std::cout <<"\nInorder: ";
    b.inorder();

    return 0;
}
