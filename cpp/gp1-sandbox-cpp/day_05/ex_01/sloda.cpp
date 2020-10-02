#include "sloda.h"

sloda::sloda()
{
    name = "sloda";
    std::cout << name << " created" << std::endl;
}

sloda::~sloda()
{
    std::cout << name << " destroyed" << std::endl;
}

void sloda::print() const
{
    animal::print();
    std::cout << "who is mixed with a panda" << std::endl;
}