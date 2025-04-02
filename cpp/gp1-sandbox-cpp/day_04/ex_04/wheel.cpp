#include "wheel.h"
#include "small_wheel.h"
#include "big_wheel.h"

#include <iostream>
#include <string>

using namespace day_04;

wheel::wheel()
{

}

wheel::wheel(int a)
{
    name = "NoWheel";
    weight = a;
}

wheel::wheel(const small_wheel& w)
{
    name = w.get_name();
    weight = w.get_weight();
    size = w.get_size();
}

wheel::wheel(const big_wheel& w)
{
    name = w.get_name();
    weight = w.get_weight();
    size = w.get_size();
}

wheel::~wheel()
{
    std::cout << "Destroying part " << name << std::endl;
}

wheel::operator std::string() const
{
    return name + ": weight=" + std::to_string(weight) + ", size=" + std::to_string(size);
}

std::string wheel::get_name() const
{
    return name;
}

float wheel::get_weight() const
{
    return weight;
}

float wheel::get_size() const
{
    return size;
}