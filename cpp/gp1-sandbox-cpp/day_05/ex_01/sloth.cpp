#include "sloth.h"

#include <iostream>

sloth::sloth()
{
    name = "sloth";
    std::cout << name << " created" << std::endl;
}

sloth::~sloth()
{
    std::cout << "sloth destroyed" << std::endl;
}

void sloth::print() const
{
    animal::print();
    std::cout << "and I am also a sloth" << std::endl;
}