#include <iostream>
#include "BTree.hpp"

int main ()
{
    BT<int> b;
    b.insert(4);
    b.insert(5);
    b.insert(1);
    b.inorder();
    return 0;
}
