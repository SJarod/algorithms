#pragma once

#include <iostream>

namespace day_03
{
    class vector2D
    {
        private:
            float x;
            float y;

        public:
            vector2D();
            vector2D(float a);
            vector2D(float a, float b);

            static const vector2D zero;
            static const vector2D up;
            static const vector2D down;
            static const vector2D left;
            static const vector2D right;

            float& X();
            float& Y();
            float X() const;
            float Y() const;

            vector2D&   operator=(const vector2D& copy);
            float&      operator[](int num);
            float&      operator[](std::string str);

            ~vector2D();
    };

    std::ostream& operator<<(std::ostream& stream, const vector2D& copy);
}