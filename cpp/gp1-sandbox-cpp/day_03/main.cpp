#include <iostream>
#include <string>

#include "vector2D.h"

using namespace day_03;

int main(int, char*[])
{
    const vector2D v1(12.0f, 97.0f);

    std::string v1string = "v1 : ";
    v1string = v1string + v1;
    v1string += ", v1 again : ";
    v1string += v1;

    std::cout << v1string.c_str() << std::endl;

    std::cout << "dot product : " << v1.dot_product(vector2D(1.0f, -1.0f)) << std::endl;
    std::cout << "length : " << v1.length() << std::endl;
    std::cout << "cross product : " << v1.cross_product(vector2D(1.0f, -1.0f)) << std::endl;

    return EXIT_SUCCESS;
}