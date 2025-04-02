#include <iostream>

#include "sloda.h"

int main()
{
    std::cout << "Simple animal:" << std::endl;

    {
        animal my_animal;
        my_animal.print();
    }
    
    std::cout << std::endl << "Simple sloth:" << std::endl;
    
    {
        sloth my_sloth;
        my_sloth.print();
        const animal& a = my_sloth;
        a.print();
    }

    std::cout << std::endl << "Simple panda:" << std::endl;

    {
        panda my_panda;
        my_panda.print();
        const animal& a = my_panda;
        a.print();
    }

    std::cout << std::endl << "Simple soda:" << std::endl;
    sloda * s = new sloda;
    std::cout << "======" << std::endl;
    animal * a = s;
    a->print();
    std::cout << "======" << std::endl;
    s->panda::print();
    delete a;
}