#include <iostream>

#include "diesel.h"
#include "fuel.h"
#include "big_wheel.h"
#include "small_wheel.h"

using namespace day_04;

int main()
{
    diesel diesel_engine;
    fuel fuel_engine;

    {
        const engine& e = diesel_engine;
        std::cout << "Engine to string : " << std::string(e) << std::endl;

        const part& p = e;
        std::cout << "Part name : " << p.get_name() << ", weight : " << p.get_weight() << std::endl;
    }

    {
        const engine& e = fuel_engine;
        std::cout << "Engine to string : " << std::string(e) << std::endl;

        const part& p = e;
        std::cout << "Part name : " << p.get_name() << ", weight : " << p.get_weight() << std::endl;
    }

    std::cout << std::string(diesel_engine) << std::endl;
    std::cout << std::string(fuel_engine) << std::endl;

    big_wheel my_big_wheel;
    small_wheel my_small_wheel;

    {
        const wheel& w = my_big_wheel;
        std::cout << "Wheel to string : " << std::string(w) << std::endl;

        const part& p = w;
        std::cout << "Part name : " << p.get_name() << ", weight : " << p.get_weight() << std::endl;
    }

    {
        const wheel& w = my_small_wheel;
        std::cout << "Wheel to string : " << std::string(w) << std::endl;
        
        const part& p = w;
        std::cout << "Part name : " << p.get_name() << ", weight : " << p.get_weight() << std::endl;
    }

    std::cout << std::string(my_big_wheel) << std::endl;
    std::cout << std::string(my_small_wheel) << std::endl;

    return EXIT_SUCCESS;
}