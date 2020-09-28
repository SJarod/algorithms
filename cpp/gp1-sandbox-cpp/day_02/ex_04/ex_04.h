#pragma once

namespace day_02::ex_04
{
    class sloth
    {
        private:
            static int  count;
            int         slothNum = 1;
            bool        isSleeping = true;
            bool        isMoving = false;

        public:
            sloth();

            void start_moving();
            void start_sleeping();

            ~sloth();
    };
}