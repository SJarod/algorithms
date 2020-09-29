#pragma once

#include "student.h"

namespace day_04::ex_01
{
    class classroom
    {
        private:
            student* classmates;
            int nb_student;

        public:
            classroom();
            classroom(int num);
            classroom(const classroom& copy);

            ~classroom();
    };
}