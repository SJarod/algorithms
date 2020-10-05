#pragma once

#include "sloth.h"
#include "panda.h"

class sloda : public panda, public sloth
{
    private:

    public:
        sloda();
        ~sloda() override;

        void    print() const override;
};