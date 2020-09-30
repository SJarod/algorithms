#pragma once

#include "part.h"

#include <iostream>

namespace day_04
{
    class wheel : public part
    {
        private:
            std::string name;
            float       weight;
            float       size;

        public:
            wheel();
            ~wheel();

            operator std::string() const;
    };
}