#pragma once

// #include "diesel.h"
// #include "fuel.h"

#include <iostream>

namespace day_04
{
    class diesel;
    class fuel;

    class engine
    {
        protected:
            std::string name;
            float       weight = 0;
            int         consomation = 0;
            int         power = 0;

        public:
            engine();
            engine(int);
            ~engine();

            std::string get_name() const;
            float       get_weight() const;
            int         get_consomation() const;
            int         get_power() const;

            operator std::string() const;
    };
}