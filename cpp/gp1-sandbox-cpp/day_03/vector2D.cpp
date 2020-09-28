#include "vector2D.h"

#include <iostream>

day_03::vector2D::vector2D()
{
    x = 0.f;
    y = 0.f;
}

day_03::vector2D::vector2D(float a)
{
    x = a;
    y = a;
}

day_03::vector2D::vector2D(float a, float b)
{
    x = a;
    y = b;
}

day_03::vector2D::~vector2D()
{
    //do nothing
}

float& day_03::vector2D::X()
{
    return x;
}

float& day_03::vector2D::Y()
{
    return y;
}

float day_03::vector2D::X() const
{
    return x;
}

float day_03::vector2D::Y() const
{
    return y;
}

day_03::vector2D& day_03::vector2D::operator=(const vector2D& copy)
{
    x = copy.x;
    y = copy.y;

    return *this;
}

std::ostream& day_03::operator<<(std::ostream& stream, const day_03::vector2D& copy)
{
    stream << copy.X() << "," << copy.Y();
    return stream;
}