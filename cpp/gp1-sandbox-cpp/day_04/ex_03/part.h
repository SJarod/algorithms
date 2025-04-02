#pragma once

#include <iostream>

namespace day_04
{
    class engine;
    class wheel;

    class part
    {
        private:
            std::string name;
            float       weight = 0;
            int         consomation = 0;
            int         power = 0;
            float       size = 0;

        public:
            part();
            part(const engine& e);
            part(const wheel& w);
            ~part();

            std::string get_name() const;
            float       get_weight() const;

            // virtual operator std::string() const;
    };
}