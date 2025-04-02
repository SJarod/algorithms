#include "classroom.h"
#include "student.h"

#include <iostream>

day_04::ex_01::classroom::classroom()
{

}

day_04::ex_01::classroom::classroom(int num)
{
    classmates = new student[num];
    nb_student = num;
}

day_04::ex_01::classroom::classroom(const classroom& copy)
{
    classmates = new student[copy.nb_student];
    nb_student = copy.nb_student;

    for (int i = 0; i < nb_student; ++i)
    {
        classmates[i] = copy.classmates[i];
    }
}

day_04::ex_01::classroom::~classroom()
{
    delete[] classmates;
}