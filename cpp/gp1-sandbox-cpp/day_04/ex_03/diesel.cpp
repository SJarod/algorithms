#include "diesel.h"

using namespace day_04;

diesel::diesel()
{
    
}

diesel::~diesel()
{
    
}

std::string diesel::get_name() const
{
    return name;
}

float diesel::get_weight() const
{
    return weight;
}

int diesel::get_consomation() const
{
    return consomation;
}

int diesel::get_power() const
{
    return power;
}