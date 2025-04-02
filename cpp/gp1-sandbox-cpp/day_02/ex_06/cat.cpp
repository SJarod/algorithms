#include "cat.h"
#include "sloth.h"

#include <iostream>

int     day_02::ex_06::cat::count = 1;

day_02::ex_06::cat::cat()
{
    std::cout << "Cat " << catName << "[" << count << "]" << " is alive !" << std::endl;

    // if (isSleeping == true)
    // {
    //     std::cout << "Sloth " << catName << "[" << count << "]" << " falls asleep." << std::endl;
    // }

    catNum = count;

    ++count;
}

day_02::ex_06::cat::cat(const std::string& name)
{
    catName = name;

    std::cout << "Cat " << catName << " [" << count << "]" << " is alive !" << std::endl;

    catNum = count;

    ++count;
}

day_02::ex_06::cat::cat(const cat& s)
{
    catName = s.catName;

    std::cout << "Cat " << catName << " [" << count << "]" << " is alive !" << std::endl;

    catNum = count;

    ++count;
}

day_02::ex_06::cat::cat(const day_02::ex_06::sloth& s)
{
    catName = s.get_name();

    std::cout << "Cat " << catName << " [" << count << "]" << " is alive !" << std::endl;

    catNum = count;

    ++count;
}

day_02::ex_06::cat::~cat()
{
    std::cout << "Cat " << catName << " [" << catNum-- << "]" << " died! Why did you do that?!" << std::endl;
}

void day_02::ex_06::cat::start_moving()
{
    if (isSleeping == true)
    {
        std::cout << "Cat " << catNum << " stops sleeping." << std::endl;
        isSleeping = false;

    }

    if (isMoving == false)
    {
        std::cout << "Cat " << catNum << " starts moving." << std::endl;
        isMoving = true;
    }
    else
    {
        std::cout << "Cat " << catNum << " is already moving." << std::endl;
    }
}

void day_02::ex_06::cat::start_sleeping()
{
    if (isMoving == true)
    {
        std::cout << "Cat " << catNum << " stops moving." << std::endl;
        isMoving = false;
    }

    if (isSleeping == false)
    {
        std::cout << "Cat " << catNum << " falls asleep." << std::endl;
        isSleeping = true;
    }
    else
    {
        std::cout << "Cat " << catNum << " is already sleeping." << std::endl;
    }
}

int day_02::ex_06::cat::get_nb_cat()
{
    return count - 1;
}

std::string day_02::ex_06::cat::get_name() const
{
    return catName;
}

day_02::ex_06::cat& day_02::ex_06::cat::operator=(const cat& copy)
{
    catName = copy.catName;
    return *this;
}

day_02::ex_06::cat& day_02::ex_06::cat::operator=(const day_02::ex_06::sloth& copy)
{
    catName = copy.get_name();
    return *this;
}

std::ostream& operator<<(std::ostream& stream, const day_02::ex_06::cat& copy)
{
    stream << copy.get_name();
    return stream;
}