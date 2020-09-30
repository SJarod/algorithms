#pragma once

#include "entity.h"

#include <iostream>

namespace day_04::ex_02
{
    class non_playable_character : public entity
    {
        private:
            int life = 5;

        public:
            non_playable_character();

            int     print_life();
            void    attacked(int attack);
            std::string to_string() const override;

            non_playable_character& operator++();

            ~non_playable_character();
    };
}