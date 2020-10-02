#pragma once

#include <iostream>

class animal
{
    class sloda;

    protected:
        std::string name = "animal";

    public:
        animal();
        animal(const sloda* s);
        ~animal();

        virtual void    print() const;
};