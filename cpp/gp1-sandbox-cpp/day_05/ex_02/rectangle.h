#pragma once
#include "shape.h"

class rectangle : public shape
{
    private:
        float scale, width, height;

    public:
        rectangle() = default;
        rectangle(float a, float b, float c);
        ~rectangle();

        float get_base_area() const override;
        float get_area() const override;

        float get_width() const;
        float get_height() const;
};