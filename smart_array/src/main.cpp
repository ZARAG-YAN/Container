#include "array.hpp"

int main()
{
    array b(0,0);
    std::cout <<"push-back\n";
    for (int i = 1; i < 9; ++i) {
        b.push_back(i);
    }
    b.print_array();
    std::cout <<"size "<<b.array_size();
    std::cout <<"\nCapacity ";
    std::cout << b.capacity();
    std::cout << std::endl;

}

