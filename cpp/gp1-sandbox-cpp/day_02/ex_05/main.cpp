#include <iostream>
#include <string>

#include "ex_05.h"

int main(int, char*[])
{
    using namespace day_02::ex_05;

    std::string tmp = "bobette";

    sloth s1(tmp);
    sloth s2(s1);

    tmp = "george";

    sloth s3(tmp);

    s2 = s3;

    std::cout << "nb sloth: " << sloth::get_nb_sloth() << std::endl;
    std::cout << "Sloth [1] name: " << s1 << std::endl;
    std::cout << "Sloth [2] name: " << s2.get_name() << std::endl;
    std::cout << "Sloth [3] name: " << s3 << std::endl;
    
    return EXIT_SUCCESS;
}