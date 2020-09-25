#include <iostream>
#include "ex_06.h"

int main(int, char*[])
{
    day_01::ex_06::__a::a = 5;
    day_01::ex_06::__b::a = 7;

    std::cout << day_01::ex_06::__a::a << std::endl;

    return EXIT_SUCCESS;
}