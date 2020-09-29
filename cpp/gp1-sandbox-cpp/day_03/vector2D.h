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

            float&  X();
            float&  Y();
            float   X() const;
            float   Y() const;

            vector2D    add(const vector2D& vect) const;
            vector2D    scale(const float scale) const;
            vector2D    normalize() const;
            vector2D&   add(const vector2D& vect);
            vector2D&   scale(const float scale);
            vector2D&   normalize();

            float   dot_product(const vector2D& vect) const;
            float   cross_product(const vector2D& vect) const;
            float   length() const;

            vector2D&       operator=(const vector2D& copy);
            float&          operator[](int num);
            float&          operator[](std::string str);

            bool            operator==(const vector2D& copy) const;
            bool            operator!=(const vector2D& copy) const;
            bool            operator<(const vector2D& copy) const;
            bool            operator<=(const vector2D& copy) const;
            bool            operator>(const vector2D& copy) const;
            bool            operator>=(const vector2D& copy) const;

            ~vector2D();
    };

    std::ostream&   operator<<(std::ostream& stream, const vector2D& copy);
    vector2D&       operator>>(std::istream& stream, vector2D& newVect);
    std::string&    operator+(std::string& baseStr, const vector2D& copy);
    std::string&    operator+=(std::string& baseStr, const vector2D& copy);
}