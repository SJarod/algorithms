#include "part.h"
#include "engine.h"
#include "wheel.h"

#include <iostream>

using namespace day_04;

part::part()
{

}

part::part(const engine& e)
{
    name = e.get_name();
    weight = e.get_weight();
    consomation = e.get_consomation();
    power = e.get_power();
}

part::part(const wheel& w)
{
    name = w.get_name();
    weight = w.get_weight();
}

part::~part()
{

}

std::string part::get_name() const
{
    return name;
}

float part::get_weight() const
{
    return weight;
}

// part::operator std::string() const
// {
//     return name;
// }