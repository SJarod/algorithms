#include "panda.h"

#include <iostream>

panda::panda()
{
    name = "panda";
    std::cout << name << " created" << std::endl;
}

panda::~panda()
{
    std::cout << "panda destroyed" << std::endl;
}

void panda::print() const
{
    animal::print();
    std::cout << "and I am also a panda" << std::endl;
}