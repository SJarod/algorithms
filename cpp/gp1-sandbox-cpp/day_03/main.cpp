#include <iostream>
#include <string>
#include "vector2D.h"
using namespace day_03;
int main(int, char*[])
{
    const vector2D v1(2.0f, 3.0f);
    vector2D v2(1.2f, 4.5f);
    vector2D v3 = v1.add(v2);
    std::cout << "v3 : " << v3 << std::endl;
    v2.add(v1).add(v3);
    std::cout << "v1 : " << v1 << std::endl;
    std::cout << "v2 : " << v2 << std::endl;
    std::cout << "v3 : " << v3 << std::endl;
    vector2D v4(0.5f, 6.3f);
    v4.scale(2.0f);
    std::cout << "v4 : " << v4 << std::endl;
    vector2D v5 = v1.scale(3.0f);
    std::cout << "v5 : " << v5 << std::endl;
    std::cout << "Copy of v1 normalized : " << v1.normalize() << std::endl;
    v5.normalize();
    std::cout << "v5 normalized : " << v5 << std::endl;
    std::cout << "v1 == v1 : " << (v1 == v1) << std::endl;
    std::cout << "v1 == v5 : " << (v1 == v5) << std::endl;
    std::cout << "v1 != v1 : " << (v1 != v1) << std::endl;
    std::cout << "v1 != v5 : " << (v1 != v5) << std::endl;
    std::cout << "v1 < v5 : " << (v1 < v5) << std::endl;
    std::cout << "v1 <= v5 : " << (v1 <= v5) << std::endl;
    std::cout << "v1 > v5 : " << (v1 > v5) << std::endl;
    std::cout << "v1 >= v5 : " << (v1 >= v5) << std::endl;
    return EXIT_SUCCESS;
}