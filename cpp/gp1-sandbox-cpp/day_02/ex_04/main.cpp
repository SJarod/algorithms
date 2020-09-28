#include <iostream>

#include "ex_04.h"

int main(int, char*[])
{
    day_02::ex_04::sloth s;
    
    s.start_moving();
    s.start_moving();
    s.start_sleeping();
    s.start_sleeping();
    s.start_moving();

    return EXIT_SUCCESS;
}