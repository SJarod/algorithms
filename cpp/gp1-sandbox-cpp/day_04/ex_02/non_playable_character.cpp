#include "non_playable_character.h"

#include <iostream>

using namespace day_04::ex_02;

non_playable_character::non_playable_character()
{
    std::cout << "Npc is born !" << std::endl;
}

int non_playable_character::print_life()
{
    std::cout << life << std::endl;
    return life;
}

void non_playable_character::attacked(int attack)
{
    life -= attack;
}

std::string non_playable_character::to_string() const
{
    return "day_04::ex_01::non_playable_character";
}

non_playable_character& non_playable_character::operator++()
{
    ++life;
    return *this;
}

non_playable_character::~non_playable_character()
{
    std::cout << "Npc is dead !" << std::endl;
}