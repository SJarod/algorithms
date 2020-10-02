#include "wheel.h"

#include <iostream>
#include <string>

using namespace day_04;

wheel::wheel()
{

}

wheel::~wheel()
{
    std::cout << "Destroying part " << name << std::endl;
}

wheel::operator std::string() const
{
    return name + ": weight=" + std::to_string(weight) + ", size=" + std::to_string(size);
}

std::string wheel::get_name() const
{
    return name;
}

float wheel::get_weight() const
{
    return weight;
}