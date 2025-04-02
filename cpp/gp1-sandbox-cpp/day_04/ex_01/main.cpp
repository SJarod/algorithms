#include <iostream>
#include "student.h"
#include "classroom.h"
using namespace day_04::ex_01;
int main()
{
    std::cout << "s0 and s1 : " << std::endl;
    {
        student s0;
        student s1;
    }
    std::cout << std::endl << "s2 and s3 : " << std::endl;
    {
        student s2;
        student s3;
        s3 = s2;
    }
    std::cout << std::endl << "class1 : " << std::endl;
    {
        classroom class1(4);
    }
    std::cout << std::endl << "class2 and class3 : " << std::endl;
    {
        classroom class2(2);
        classroom class3 = class2;
    }
    return 0;
}