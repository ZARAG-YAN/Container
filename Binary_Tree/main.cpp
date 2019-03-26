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
    std::cout << std::endl;
    std::cout <<"\nCount of Nodes = "<< b.m_count;
    std::cout << std::endl;

    b.p_p(24);
    b.p_p(13);
    b.p_p(27);
    b.p_p(24);
    b.p_p(24);
    
    std::cout <<"\nCount of Nodes = "<< b.m_count;
    std::cout << std::endl;

    std::cout <<"\nInorder: ";
    b.inorder();

    std::cout <<"\nPreorder: ";
    b.preorder();

    std::cout <<"\nPostorder: ";
    b.postorder();

    return 0;
}
