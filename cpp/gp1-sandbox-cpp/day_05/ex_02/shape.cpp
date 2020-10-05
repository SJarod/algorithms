#include "shape.h"

#include <iostream>

shape::~shape()
{
    std::cout << name << " destroyed" << std::endl;
}

float shape::get_base_area() const
{
    return 0;
}

float shape::get_area() const
{
    return 0;
}