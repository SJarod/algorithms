#include "entity.h"

#include <iostream>

using namespace day_04::ex_02;

int entity::life()
{
    return hp;
}

std::string entity::to_string() const
{
    return "day_04::ex_01::entity";
}