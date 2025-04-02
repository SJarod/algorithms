#include <iostream>
#include "ex_02.h"

int main()
{
    day_01::ex_02::box::other_box box;

    day_01::ex_02::box::little_box::candies = 12;
    day_01::ex_02::box::nb_little_boxes = 23;
    box.candy = day_01::ex_02::box::other_box::candies::ORANGE;

    std::cout << "nb candies: " << day_01::ex_02::box::little_box::candies << std::endl;
    std::cout << "nb_little_boxes: " << box.nb_little_boxes << std::endl;
    
    box.candy = day_01::ex_02::box::other_box::candies::STRAWBERRY;
}