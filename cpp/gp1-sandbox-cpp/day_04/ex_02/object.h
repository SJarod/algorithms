#pragma once

#include "entity.h"

#include <iostream>

namespace day_04::ex_02
{
    class entity;

    class object
    {
        private:
            int hp = 0;

        public:
            object(const entity& en){};

            std::string to_string() const;
    };
}