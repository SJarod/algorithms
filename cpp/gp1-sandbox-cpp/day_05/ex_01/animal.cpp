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
    std::cout << "animal destroyed" << std::endl;
}

void animal::print() const
{
    std::cout << "I am an animal" << std::endl;

    if (name != "animal")
        std::cout << "and I am also a " << name << std::endl;
}