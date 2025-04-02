#pragma once

#include "part.h"

#include <iostream>

namespace day_04
{
    class small_wheel;
    class big_wheel;

    class wheel
    {
        protected:
            std::string name;
            float       weight;
            float       size;

        public:
            wheel();
            wheel(int);
            wheel(const small_wheel& w);
            wheel(const big_wheel& w);
            ~wheel();

            std::string get_name() const;
            float       get_weight() const;
            float       get_size() const;

            operator std::string() const;
    };
}