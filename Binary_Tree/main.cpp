#include <iostream>
#include "BTree.hpp"
#include <cstdlib>
//#include <ctime>

int main ()
{
    BT<int> b;
   // srand(time(0));
    for (int i = 0; i <= 8; ++i) {
        int n = rand() % 40 + 1;
        b.insert(n);
    }
    b.insert(14);
    b.insert(19);
    b.insert(6);
    std::cout << std::endl;
    std::cout <<"\nCount of Nodes = "<< b.m_count;
    std::cout << std::endl;
    std::cout <<"\nInorder: ";
    b.inorder();
    std::cout << std::endl;

    b.remove(24);

    std::cout <<"\nCount of Nodes = "<< b.m_count;
    std::cout << std::endl;


    std::cout <<"\nInorder: ";
    b.inorder();

    return 0;
}
