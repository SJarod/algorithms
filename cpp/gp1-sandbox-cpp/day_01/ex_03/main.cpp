#include "ex_03.h"

#include <iostream>

int main()
{
    int a = day_01::ex_03::add(1, -8);
    float b = day_01::ex_03::add(1.1f, 4.3f);
    double c = day_01::ex_03::add(1.325, 3.23);
    unsigned int d = day_01::ex_03::add(1, 1);
    double e = day_01::ex_03::add(1.2);

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << d << std::endl;
    std::cout << e << std::endl;

    return 0;
}