#include "vector2D.h"

#include <iostream>
#include <string>
#include <math.h>

const day_03::vector2D day_03::vector2D::zero   ( 0.f,  0.f);
const day_03::vector2D day_03::vector2D::up     ( 0.f,  1.f);
const day_03::vector2D day_03::vector2D::down   ( 0.f, -1.f);
const day_03::vector2D day_03::vector2D::left   (-1.f,  0.f);
const day_03::vector2D day_03::vector2D::right  ( 1.f,  0.f);

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

day_03::vector2D day_03::vector2D::add(const vector2D& vect) const
{
    return vector2D(x + vect.X(), y + vect.Y());
}

day_03::vector2D day_03::vector2D::scale(const float scale) const
{
    return vector2D(x * scale, y * scale);
}

day_03::vector2D day_03::vector2D::normalize() const
{
    float magnitude = length();
    if (magnitude == 0)
    {
        return zero;
    }

    return scale(1 / magnitude);
}

day_03::vector2D& day_03::vector2D::add(const day_03::vector2D& vect)
{
    x += vect.x;
    y += vect.y;

    return *this;
}

day_03::vector2D& day_03::vector2D::scale(const float scale)
{
    x *= scale;
    y *= scale;

    return *this;
}

day_03::vector2D& day_03::vector2D::normalize()
{
    float magnitude = length();
    if (magnitude == 0)
    {
        return *this;
    }

    x /= magnitude;
    y /= magnitude;

    return *this;
}

float day_03::vector2D::dot_product(const day_03::vector2D& vect) const
{
    return this->X() * vect.X() + this->Y() * vect.Y();
}

float day_03::vector2D::cross_product(const day_03::vector2D& vect) const
{
    return this->X() * vect.Y() - this->Y() * vect.X();
}

float day_03::vector2D::length() const
{
    return sqrtf(powf(this->x, 2) + powf(this->y, 2));
}

day_03::vector2D& day_03::vector2D::operator=(const vector2D& copy)
{
    x = copy.x;
    y = copy.y;

    return *this;
}

float& day_03::vector2D::operator[](int num)
{
    if (num == 0 || num == 'x')
    {
        return x;
    }
    else
    {
        return y;
    }
}

float& day_03::vector2D::operator[](std::string str)
{
    if (str == "x")
    {
        return x;
    }
    else
    {
        return y;
    }
}

bool day_03::vector2D::operator==(const vector2D& copy) const
{
    return this->X() == copy.X() && this->Y() == copy.Y();
}

bool day_03::vector2D::operator!=(const vector2D& copy) const
{
    return this->X() != copy.X() || this->Y() != copy.Y();
}

bool day_03::vector2D::operator<(const vector2D& copy) const
{
    return length() < copy.length();
}

bool day_03::vector2D::operator<=(const vector2D& copy) const
{
    return this->length() <= copy.length();
}

bool day_03::vector2D::operator>(const vector2D& copy) const
{
    return this->length() > copy.length();
}

bool day_03::vector2D::operator>=(const vector2D& copy) const
{
    return this->length() >= copy.length();
}

std::string& day_03::operator+(std::string& baseStr, const vector2D& copy)
{
    std::string str = std::to_string(copy.X());
    baseStr += "x:";
    baseStr += str;
    baseStr += ", y:";

    str = std::to_string(copy.Y());
    baseStr += str;
    return baseStr;
}

std::string& day_03::operator+=(std::string& baseStr, const vector2D& copy)
{
    std::string str = std::to_string(copy.X());
    baseStr += "x:";
    baseStr += str;
    baseStr += ", y:";

    str = std::to_string(copy.Y());
    baseStr += str;
    return baseStr;
}

std::ostream& day_03::operator<<(std::ostream& stream, const day_03::vector2D& copy)
{
    stream << copy.X() << "," << copy.Y();
    return stream;
}

day_03::vector2D& day_03::operator>>(std::istream& stream, day_03::vector2D& newVect)
{
    std::string value;
    stream >> value;

    newVect[0] = std::stof(value);
    
    std::string coma;
    stream >> coma;
    if (coma != ",")
    {
        newVect = day_03::vector2D::zero;
        return newVect;
    }

    stream >> value;
    newVect[1] = std::stof(value);

    return newVect;
}