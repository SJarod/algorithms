#pragma once

#include <iostream>

namespace day_02::ex_06
{
    class sloth
    {
        private:
            static int  count;
            int         slothNum = 1;
            std::string slothName;
            bool        isSleeping = true;
            bool        isMoving = false;

        public:
            sloth();
            sloth(const sloth& s);
            sloth(const std::string& name);

            void        start_moving();
            void        start_sleeping();
            static int  get_nb_sloth();
            std::string get_name() const;

            sloth&          operator=(const sloth& copy);
            
            ~sloth();
    };
}

std::ostream&   operator<<(std::ostream& stream, const day_02::ex_06::sloth& copy);