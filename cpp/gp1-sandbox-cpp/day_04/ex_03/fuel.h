#pragma once

#include "engine.h"

#include <iostream>

namespace day_04
{
    class fuel : public engine
    {
        private:
            std::string name = "Fuel";
            float       weight = 700.f;
            int         consomation = 7;
            int         power = 6;

        public:
            fuel();
            ~fuel();

            std::string get_name() const;
            float       get_weight() const;
            int         get_consomation() const;
            int         get_power() const;
    };
}