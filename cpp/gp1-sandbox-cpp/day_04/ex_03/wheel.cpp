#include "wheel.h"

#include <iostream>
#include <string>

using namespace day_04;

wheel::wheel()
{

}

wheel::~wheel()
{

}

wheel::operator std::string() const
{
    return name + ": weight=" + std::to_string(weight) + ", size=" + std::to_string(size);
}