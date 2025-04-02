#pragma once
#include "shape.h"

#define PI 3.14

class circle : public shape
{
    private:
        float scale, radius;

    public:
        circle() = default;
        circle(float a, float b);
        ~circle();

        float get_base_area() const override;
        float get_area() const override;

        float get_radius() const;
};