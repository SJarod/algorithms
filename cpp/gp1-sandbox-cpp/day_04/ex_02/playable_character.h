#pragma once

#include "entity.h"
#include "non_playable_character.h"

#include <iostream>

namespace day_04::ex_02
{
    class playable_character : public entity
    {
        private:
            int life = 20;
            int attack = 4;

        public:
            int print_life();
            std::string to_string() const override;

            playable_character& operator++();
            playable_character  operator*(non_playable_character& pnj) const;
    };
}