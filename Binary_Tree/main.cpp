#include <iostream>
#include "BTree.hpp"
#include <cstdlib>
#include <ctime>

int main ()
{
    BT<int> b;
    srand(time(0));
    for (int i = 0; i <= 8; ++i) {
        int n = rand() % 40 + 1;
        b.insert(n);
    }
    std::cout << std::endl;
    std::cout <<"\nCount = "<< b.m_count;
    std::cout << std::endl;
    std::cout <<"\nInorder: ";
    b.inorder();

    std::cout <<"\nPreorder: ";
    b.preorder();

    std::cout <<"\nPostorder: ";
    b.postorder();

    return 0;
}
