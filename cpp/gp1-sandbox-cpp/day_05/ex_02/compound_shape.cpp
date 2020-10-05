#include "compound_shape.h"

#include <iostream>

compound_shape::compound_shape(float a, unsigned int b)
{
    name = "Compound shape";
    scale = a;
    num_shape = b;

    sh = new shape[b];
}

compound_shape::~compound_shape()
{
    delete[] sh;
}

void compound_shape::set_shape(int num, shape* s)
{
    base_area += s->get_area();
    sh[num] = *s;
}

float compound_shape::get_base_area() const
{
    return base_area;
}

float compound_shape::get_area() const
{
    return get_base_area() * scale;
}