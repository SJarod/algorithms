#pragma once
#include "circle.h"
#include "rectangle.h"
#include "shape.h"

class compound_shape : public shape
{
    private:
        int num_shape = 0;
        float scale;
        float base_area = 0;
        shape* sh;

    public:
        compound_shape() = default;
        compound_shape(float a, unsigned int b);
        ~compound_shape();

        void set_shape(int num, shape* s);

        float get_base_area() const override;
        float get_area() const override;
};