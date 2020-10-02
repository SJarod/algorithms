#include "car.h"

using namespace day_04;

car::car()
{

}

car::~car()
{

}

int car::get_total_weight() const
{
    return e.get_weight() + w.get_weight() + w1.get_weight() + w2.get_weight() + w3.get_weight();
}

void car::print_parts() const
{
    std::cout << "Engine: " + e.get_name() + ", Wheel1: " + w.get_name() + ", Wheel2: " + w1.get_name() + ", Wheel3: " + w2.get_name() + ", Wheel4: " + w3.get_name() << std::endl;
}

void car::set_engine(engine* e)
{
    if (this->e.get_name() != "NoEngine")
    {
        this->e.~engine();
    }

    this->e = *e;
}

void car::set_wheels(wheel* w, wheel* w1, wheel* w2, wheel* w3)
{
    this->w = *w;
    this->w1 = *w1;
    this->w2 = *w2;
    this->w3 = *w3;
}