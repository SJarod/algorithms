#include <iostream>
#include <string>

#include "vector2D.h"

using namespace day_03;

int main(int, char*[])
{
    vector2D v1 = vector2D::zero;
    std::cout << "v1 : " << v1 << std::endl;

    v1 = vector2D::up;
    std::cout << "v1 : " << v1 << std::endl;

    v1 = vector2D::down;
    std::cout << "v1 : " << v1 << std::endl;

    v1 = vector2D::left;
    std::cout << "v1 : " << v1 << std::endl;

    v1 = vector2D::right;
    std::cout << "v1 : " << v1 << std::endl;

    float f = v1[1] = 20.0f;
    f = v1[0] = 2.0f * f;

    std::cout << "v1 : " << v1 << ", f: " << f << std::endl;

    float x = v1['x'] = 78.0f;
    float y = v1['y'] = 67.0f;

    std::cout << "x : " << x << ", y: " << y << std::endl;
    std::cout << "v1 : " << v1 << std::endl;

    x = v1["x"] = 12.0f;
    y = v1["y"] = 34.0f;

    std::cout << "x : " << x << ", y: " << y << std::endl;
    std::cout << "v1 : " << v1 << std::endl;
    
    return EXIT_SUCCESS;
}