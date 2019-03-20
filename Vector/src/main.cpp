#include "vector.hpp"

int main()
{
    vector<int> b(4,0);
    std::cout <<"b \npush-back\n";
    for (int i = 0; i < 10; ++i) {
        b.push_back(i);
    }
    std::cout <<"size "<<b.get_size();
    b.print_vector();
    b.push_back(45);
    std::cout <<"size "<<b.get_size();
    std::cout <<"\nCapacity ";
    std::cout << "\n"<< b.get_capacity();
    std::cout <<" ";
    b.print_vector();
/*
    vector<int> c;
    std::cout <<"c \n";
    for (int i = 0; i < 5; ++i) {
        c.push_back();
    }
    std::cout << c;
*/
    std::cout <<"\noperator << ";
    std::cout << b;
    return 0;
}

