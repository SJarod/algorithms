#pragma once

namespace day_04::ex_01
{
    class student
    {
        private:
            static int nb_student;
            int student_id;

        public:
            student();

            student&    operator=(const student& copy);

            ~student();
    };
}