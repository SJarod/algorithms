#include "ex_01.h"

#include <iostream>

int main()
{
    int a = 2;
    int b = 4;
    swap<int>(&a, &b);

    std::cout << a << b << std::endl;
    std::cout << add<int>(a, b) << std::endl;

    return 0;
}