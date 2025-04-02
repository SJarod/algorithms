#pragma once

namespace day_01::ex_06
{
    namespace __a
    {
        int a;
    }

    namespace __b
    {
        //reference to a in namespace __a
        using __a::a;
    }
}