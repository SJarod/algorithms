#include "circle.h"

#include <iostream>

circle::circle(float a, float b)
{
    scale = a;
    radius = b;
    name = "Circle";
}

circle::~circle()
{

}

float circle::get_base_area() const
{
    return PI * radius * radius;
}

float circle::get_area() const
{
    return get_base_area() * scale;
}

float circle::get_radius() const
{
    return radius;
}