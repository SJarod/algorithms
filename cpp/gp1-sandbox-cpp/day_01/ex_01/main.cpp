#include <iostream>

#include "ex_01.h"

int main()
{
    day_01::ex_01::box::nb_little_boxes = 5;
    day_01::ex_01::box::little_box::nb_little_boxes = 7;

    std::cout << day_01::ex_01::box::nb_little_boxes << std::endl;
    std::cout << day_01::ex_01::box::little_box::nb_little_boxes << std::endl;

    return 0;
}
