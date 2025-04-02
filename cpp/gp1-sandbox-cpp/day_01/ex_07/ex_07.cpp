#include "ex_07.h"

#include <istream>
#include <string>
#include <iostream>

void day_01::ex_07::read()
{
    std::string str;
    std::getline(std::cin, str);
    bool is_number = false;

    for (int i = 0; str[i] != '\0'; ++i)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            is_number = true;
            break;
        }
    }

    if (is_number)
    {
        std::cout << "bad string" << std::endl;
    }
    else
    {
        std::cout << "good job" << std::endl;
    }
}