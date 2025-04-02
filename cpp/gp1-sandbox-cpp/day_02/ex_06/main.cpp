#include <iostream>

#include "sloth.h"
#include "cat.h"

int main()
{
    std::string tmp = "bobette";
    day_02::ex_06::sloth s1(tmp);

    tmp = "george";
    day_02::ex_06::sloth s2(tmp);

    s2 = s2;

    tmp = "bernard";
    day_02::ex_06::cat s3(tmp);

    tmp = "woman";
    day_02::ex_06::cat s4(s3);

    s3 = s4;

    day_02::ex_06::cat s5 = s1;
    std::cout << "Cat " << s5 << std::endl;
    s5 = s2;
    std::cout << "Cat " << s5 << std::endl;

    std::cout << "Slot " << s1 << " and cat " << s3 << " are friends" << std::endl;
    std::cout << "Slot " << s2 << " and cat " << s4 << " are friends" << std::endl;

    return 0;
}