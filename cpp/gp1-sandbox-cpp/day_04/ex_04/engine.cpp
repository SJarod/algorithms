#include "engine.h"
#include "diesel.h"
#include "fuel.h"

#include <iostream>
#include <string>

using namespace day_04;

engine::engine()
{

}

engine::engine(int a)
{
    name = "NoEngine";
    weight = a;
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

engine::operator std::string() const
{
    return name + ": weight=" + std::to_string(weight) + ", consomation=" + std::to_string(consomation) + ", power=" + std::to_string(power);
}