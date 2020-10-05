#include "sloda.h"

sloda::sloda()
{
    name = "sloda";
    std::cout << name << " created" << std::endl;
}

sloda::~sloda()
{
    std::cout << "sloda destroyed" << std::endl;
}

void sloda::print() const
{
    sloth::print();
    std::cout << "who is mixed with a panda" << std::endl;
}