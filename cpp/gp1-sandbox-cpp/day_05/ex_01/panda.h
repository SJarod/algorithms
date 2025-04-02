#pragma once

#include "animal.h"

class panda : virtual public animal
{
    private:

    public:
        panda();
        ~panda() override;

        void print() const override;
};