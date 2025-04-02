#include "rectangle.h"

#include <iostream>

rectangle::rectangle(float a, float b, float c)
{
    scale = a;
    width = b;
    height = c;
    name = "Rectangle";
}

rectangle::~rectangle()
{
    
}

float rectangle::get_base_area() const
{
    return width * height;
}

float rectangle::get_area() const
{
    return get_base_area() * scale;
}

float rectangle::get_width() const
{
    return width;
}

float rectangle::get_height() const
{
    return height;
}