#pragma once

#include <string>

class shape
{
    protected:
        std::string name;
        float scale;

    public:
        shape() = default;
        ~shape();

        virtual float get_base_area() const;
        virtual float get_area() const;
};