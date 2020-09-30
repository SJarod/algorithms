#include "engine.h"
#include "diesel.h"
#include "fuel.h"

#include <iostream>
#include <string>

using namespace day_04;

engine::engine()
{

}

engine::engine(const diesel& en)
{
    name = en.get_name();
    weight = en.get_weight();
    consomation = en.get_consomation();
    power = en.get_power();
}

engine::engine(const fuel& en)
{
    name = en.get_name();
    weight = en.get_weight();
    consomation = en.get_consomation();
    power = en.get_power();
}

engine::~engine()
{
    std::cout << "Destroying part " << name << std::endl;
}

std::string engine::get_name() const
{
    return name;
}

float engine::get_weight() const
{
    return weight;
}

int engine::get_consomation() const
{
    return consomation;
}

int engine::get_power() const
{
    return power;
}

// engine& engine::operator=(const diesel& en)
// {
//     name = en.get_name();
//     weight = en.get_weight();
//     consomation = en.get_consomation();
//     power = en.get_power();

//     return *this;
// }

// engine& engine::operator=(const fuel& en)
// {
//     name = en.get_name();
//     weight = en.get_weight();
//     consomation = en.get_consomation();
//     power = en.get_power();

//     return *this;
// }

engine::operator std::string() const
{
    return name + ": weight=" + std::to_string(weight) + ", consomation=" + std::to_string(consomation) + ", power=" + std::to_string(power);
}