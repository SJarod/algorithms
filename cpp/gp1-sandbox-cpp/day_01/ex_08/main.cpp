#include <iostream>

#include "ex_08.h"

int main(int, char*[])
{
    day_01::ex_08::print("printed char const *");
    day_01::ex_08::print(-123);
    day_01::ex_08::print(123u);
    day_01::ex_08::print(9.2);
    day_01::ex_08::print(3.4f);

    return EXIT_SUCCESS;
}