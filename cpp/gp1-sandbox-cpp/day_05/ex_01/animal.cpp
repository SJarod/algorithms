#include "animal.h"

#include <iostream>

animal::animal()
{
    std::cout << name << " created" << std::endl;
}

animal::animal(const sloda* s)
{

}

animal::~animal()
{
    std::cout << name << " destroyed" << std::endl;
}

void animal::print() const
{
    std::cout << "I am an " << name << std::endl;
}