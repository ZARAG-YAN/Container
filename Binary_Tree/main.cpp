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
    b.insert(15);
    b.insert(6);
    b.insert(5);
    std::cout << std::endl;
    std::cout <<"\nCount of Nodes = "<< b.m_count;
    std::cout << std::endl;
    b.inorder();
    b.remove(10);

    std::cout <<"\nInorder: ";
    b.inorder();

    b.insert(10);
    std::cout << std::endl;
    //b.p_p(10);
    b.remove(36);
    //b.p_p(36);
   // b.remove(18);
   // b.p_p(18);

    std::cout <<"\nCount of Nodes = "<< b.m_count;
    std::cout << std::endl;

    std::cout <<"\nInorder: ";
    b.inorder();
/*
    std::cout <<"\nPreorder: ";
    b.preorder();

    std::cout <<"\nPostorder: ";
    b.postorder();
*/
    return 0;
}
