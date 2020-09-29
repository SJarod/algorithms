#include "student.h"

#include <iostream>

int day_04::ex_01::student::nb_student = 0;

day_04::ex_01::student::student()
{
    student_id = nb_student++;
    std::cout << "student " << student_id << " created" << std::endl;
}

day_04::ex_01::student::~student()
{
    std::cout << "student " << student_id << " destroyed" << std::endl;
}

day_04::ex_01::student& day_04::ex_01::student::operator=(const student& copy)
{
    std::cout << "student " << student_id << " become " << copy.student_id << std::endl;
    student_id = copy.student_id;
    return *this;
}