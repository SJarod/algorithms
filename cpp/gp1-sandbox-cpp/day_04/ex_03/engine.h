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
        private:
            std::string name;
            float       weight;
            int         consomation;
            int         power;

        public:
            engine();
            engine(const diesel& en);
            engine(const fuel& en);
            ~engine();

            std::string get_name() const;
            float       get_weight() const;
            int         get_consomation() const;
            int         get_power() const;

            // engine&     operator=(const diesel& en);
            // engine&     operator=(const fuel& en);

            operator std::string() const;
    };
}