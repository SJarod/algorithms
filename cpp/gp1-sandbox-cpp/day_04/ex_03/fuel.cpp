#include "fuel.h"

#include <iostream>

using namespace day_04;

fuel::fuel()
{
    
}

fuel::~fuel()
{

}

std::string fuel::get_name() const
{
    return name;
}

float fuel::get_weight() const
{
    return weight;
}

int fuel::get_consomation() const
{
    return consomation;
}

int fuel::get_power() const
{
    return power;
}