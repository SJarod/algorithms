#pragma once

#include "engine.h"

#include <iostream>

namespace day_04
{
    class engine;

    class part
    {
        private:
            std::string name;
            float       weight;
            int         consomation;
            int         power;

        public:
            part();
            part(const engine& e);
            ~part();

            std::string get_name() const;
            float       get_weight() const;

            // virtual operator std::string() const;
    };
}