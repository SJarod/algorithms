#include "panda.h"

#include <iostream>

panda::panda()
{
    name = "panda";
    std::cout << name << " created" << std::endl;
}

panda::~panda()
{
    std::cout << name << " destroyed" << std::endl;
}