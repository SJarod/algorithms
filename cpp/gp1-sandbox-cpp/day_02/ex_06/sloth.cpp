#include "sloth.h"
#include "cat.h"

#include <iostream>

int     day_02::ex_06::sloth::count = 1;

day_02::ex_06::sloth::sloth()
{
    std::cout << "Sloth " << slothName << "[" << count << "]" << " is alive !" << std::endl;

    // if (isSleeping == true)
    // {
    //     std::cout << "Sloth " << slothName << "[" << count << "]" << " falls asleep." << std::endl;
    // }

    slothNum = count;

    ++count;
}

day_02::ex_06::sloth::sloth(const std::string& name)
{
    slothName = name;

    std::cout << "Sloth " << slothName << " [" << count << "]" << " is alive !" << std::endl;

    slothNum = count;

    ++count;
}

day_02::ex_06::sloth::sloth(const sloth& s)
{
    slothName = s.slothName;

    std::cout << "Sloth " << slothName << " [" << count << "]" << " is alive !" << std::endl;

    slothNum = count;

    ++count;
}

day_02::ex_06::sloth::~sloth()
{
    std::cout << "Sloth " << slothName << " [" << slothNum-- << "]" << " died! Why did you do that?!" << std::endl;
}

void day_02::ex_06::sloth::start_moving()
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

void day_02::ex_06::sloth::start_sleeping()
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

int day_02::ex_06::sloth::get_nb_sloth()
{
    return count - 1;
}

std::string day_02::ex_06::sloth::get_name() const
{
    return slothName;
}

day_02::ex_06::sloth& day_02::ex_06::sloth::operator=(const sloth& copy)
{
    slothName = copy.slothName;
    return *this;
}

// day_02::ex_06::sloth& day_02::ex_06::sloth::operator=(const cat& copy)
// {
//     slothName = copy.get_nb_cat();
//     return *this;
// }

std::ostream& operator<<(std::ostream& stream, const day_02::ex_06::sloth& copy)
{
    stream << copy.get_name();
    return stream;
}