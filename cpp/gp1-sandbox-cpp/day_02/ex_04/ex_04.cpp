#include "ex_04.h"

#include <iostream>

int     day_02::ex_04::sloth::count = 1;

day_02::ex_04::sloth::sloth()
{
    std::cout << "Sloth " << count << " is alive !" << std::endl;

    if (isSleeping == true)
    {
        std::cout << "Sloth " << count << " falls asleep." << std::endl;
    }

    slothNum = count;

    ++count;
}

day_02::ex_04::sloth::~sloth()
{
    std::cout << "Sloth " << slothNum-- << " died! Why did you do that?!" << std::endl;
}

void day_02::ex_04::sloth::start_moving()
{
    if (isSleeping == true)
    {
        std::cout << "Sloth " << slothNum << " stops sleeping." << std::endl;
        isSleeping = false;

    }

    if (isMoving == false)
    {
        std::cout << "Sloth " << slothNum << " starts moving." << std::endl;
        isMoving = true;
    }
    else
    {
        std::cout << "Sloth " << slothNum << " is already moving." << std::endl;
    }
}

void day_02::ex_04::sloth::start_sleeping()
{
    if (isMoving == true)
    {
        std::cout << "Sloth " << slothNum << " stops moving." << std::endl;
        isMoving = false;
    }

    if (isSleeping == false)
    {
        std::cout << "Sloth " << slothNum << " falls asleep." << std::endl;
        isSleeping = true;
    }
    else
    {
        std::cout << "Sloth " << slothNum << " is already sleeping." << std::endl;
    }
}