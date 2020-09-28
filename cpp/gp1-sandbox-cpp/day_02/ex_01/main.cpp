#include "ex_01.h"

#include <iostream>

int main()
{
    int a = 10;
    int b = 4;

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;

    day_02::ex_01::swap(a, b);

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;

    return 0;
}