#pragma once

#include "part.h"

#include <iostream>

namespace day_04
{
    class wheel
    {
        protected:
            std::string name;
            float       weight;
            float       size;

        public:
            wheel();
            ~wheel();

            std::string get_name() const;
            float       get_weight() const;

            operator std::string() const;
    };
}