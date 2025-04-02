#pragma once

#include <iostream>

class animal
{
    class sloda;

    protected:
        std::string name = "animal";

    public:
        animal();
        virtual ~animal();

        virtual void    print() const;
};