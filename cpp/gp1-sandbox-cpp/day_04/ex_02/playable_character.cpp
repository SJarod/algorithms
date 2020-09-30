#include "playable_character.h"
#include "non_playable_character.h"

#include <iostream>

using namespace day_04::ex_02;

int playable_character::print_life()
{
    std::cout << life << std::endl;
    return life;
}

std::string playable_character::to_string() const
{
    return "day_04::ex_01::playable_character";
}

playable_character& playable_character::operator++()
{
    ++life;
    return *this;
}

playable_character  playable_character::operator*(non_playable_character& pnj) const
{
    pnj.attacked(attack);
    return *this;
}