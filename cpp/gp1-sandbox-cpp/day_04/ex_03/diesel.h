#pragma once

#include "engine.h"

#include <iostream>

namespace day_04
{
    class diesel : public engine
    {
        private:
            std::string name = "Diesel";
            float       weight = 500.f;
            int         consomation = 2;
            int         power = 3;

        public:
            diesel();
            ~diesel();

            std::string get_name() const;
            float       get_weight() const;
            int         get_consomation() const;
            int         get_power() const;
    };
}