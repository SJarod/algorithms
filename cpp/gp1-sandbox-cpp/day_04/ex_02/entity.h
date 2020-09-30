#pragma once

#include "object.h"

#include <iostream>

namespace day_04::ex_02
{
    class entity
    {
        private:
            int hp = 0;

        public:
            int life();
            virtual std::string to_string() const;
    };
}