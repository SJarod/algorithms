#pragma once

#include "animal.h"

class sloth : virtual public animal
{
    private:

    public:
        sloth();
        ~sloth() override;

        void print() const override;
};