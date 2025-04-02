#pragma once

#include "engine.h"
#include "wheel.h"

namespace day_04
{
    class car
    {
        private:
            engine  e = 0;
            wheel   w = 0, w1 = 0, w2 = 0, w3 = 0;

        public:
            car();
            ~car();

            int     get_total_weight() const;
            void    print_parts() const;
            void    set_engine(engine* e);
            void    set_wheels(wheel* w, wheel* w1, wheel* w2, wheel* w3);
    };
}