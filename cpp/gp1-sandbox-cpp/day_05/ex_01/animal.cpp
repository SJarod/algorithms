#include "animal.h"

#include <iostream>

animal::animal()
{
    std::cout << name << " created" << std::endl;
}

animal::~animal()
{
    std::cout << "animal destroyed" << std::endl;
}

void animal::print() const
{
    std::cout << "I am an animal" << std::endl;
}