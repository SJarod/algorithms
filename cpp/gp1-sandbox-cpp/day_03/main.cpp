#include <iostream>
#include <string>

#include "vector2D.h"

using namespace day_03;

int main(int, char*[])
{
    vector2D v1;
    std::cout << "v1 : " << v1 << std::endl;

    const vector2D v2(1.0f, 2.5f);
    std::cout << "v2.X() : " << v2.X() << ", v2.Y() : " << v2.Y() << std::endl;

    vector2D v3 = v2;
    std::cout << "v3 : " << v3 << std::endl;

    v3.X() = v3.Y() = 1.2f;
    std::cout << "v3 : " << v3 << std::endl;

    vector2D v4(0.2f, 10.0f);
    std::cout << "v4 : " << v4 << std::endl;

    v4 = v3;
    std::cout << "v4 : " << v4 << std::endl;

    vector2D v5 = 3.0f;
    std::cout << "v5 : " << v5 << std::endl;

    return EXIT_SUCCESS;
}