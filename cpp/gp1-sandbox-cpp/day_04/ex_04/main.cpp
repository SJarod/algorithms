#include <iostream>
#include "diesel.h"
#include "fuel.h"
#include "big_wheel.h"
#include "small_wheel.h"
#include "car.h"
using namespace day_04;
int main()
{
car my_car;
std::cout << "Car weight : " << my_car.get_total_weight() << std::endl;
my_car.print_parts();
my_car.set_engine(new diesel);
std::cout << "Car weight : " << my_car.get_total_weight() << std::endl;
my_car.print_parts();
my_car.set_wheels(new big_wheel, new big_wheel, new small_wheel, new small_wheel);
std::cout << "Car weight : " << my_car.get_total_weight() << std::endl;
my_car.print_parts();
my_car.set_engine(new fuel);
std::cout << "Car weight : " << my_car.get_total_weight() << std::endl;
my_car.print_parts();
return 0;
}