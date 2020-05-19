#include <iostream>
#include "BTree.hpp"
#include <cstdlib>
//#include <ctime>

int main ()
{
    BT<int> b;
    //Inserted the following numbers: 44, 47, 58, 56, 54, 56, 47, 13, 10, 2, 3
    //srand(time(0));
    for (int i = 0; i <= 10; ++i) {
        int n = rand() % 60 + 1;
        b.insert(n);
    }
    std::cout << std::endl;
    std::cout <<"Count of nodes = "<< b.m_count << std::endl;
    std::cout <<"Inorder: ";
    b.inorder();
    std::cout << std::endl;

    b.remove(44);
    std::cout <<"Count of nodes = "<< b.m_count << std::endl;

    b.remove(13);
    b.remove(56);

    b.insert(44);
    b.print_parent(58);

    b.remove(47);
    b.print_parent(58);
    std::cout <<"Count of nodes = "<< b.m_count << std::endl;

    std::cout <<"\nInorder: ";
    b.inorder();

    std::cout <<"\nPreorder: ";
    b.preorder();

    std::cout <<"\nPostorder: ";
    b.postorder();

    return 0;
}
