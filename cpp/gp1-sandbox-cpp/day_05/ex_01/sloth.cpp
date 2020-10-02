#include "sloth.h"

#include <iostream>

sloth::sloth()
{
    name = "sloth";
    std::cout << name << " created" << std::endl;
}

sloth::~sloth()
{
    std::cout << name << " destroyed" << std::endl;
}