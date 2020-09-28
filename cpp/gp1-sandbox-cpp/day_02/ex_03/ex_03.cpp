#include "ex_03.h"

#include <iostream>

int day_02::ex_03::sloth::count = 1;

day_02::ex_03::sloth::sloth()
{
    std::cout << "Sloth " << day_02::ex_03::sloth::count++ << " is alive !" << std::endl;
}

day_02::ex_03::sloth::~sloth()
{
    std::cout << "Sloth " << --day_02::ex_03::sloth::count << " died! Why did you do that?!" << std::endl;
}