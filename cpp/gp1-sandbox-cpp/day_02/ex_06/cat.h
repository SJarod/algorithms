#pragma once

#include <iostream>

#include "sloth.h"

namespace day_02::ex_06
{
    class sloth;
    
    class cat
    {
        private:
            static int  count;
            int         catNum = 1;
            std::string catName;
            bool        isSleeping = true;
            bool        isMoving = false;

        public:
            cat();
            cat(const cat& s);
            cat(const day_02::ex_06::sloth& s);
            cat(const std::string& name);

            void        start_moving();
            void        start_sleeping();
            static int  get_nb_cat();
            std::string get_name() const;

            cat&        operator=(const cat& copy);
            cat&        operator=(const day_02::ex_06::sloth& copy);
            
            ~cat();
    };
}

std::ostream&   operator<<(std::ostream& stream, const day_02::ex_06::cat& copy);