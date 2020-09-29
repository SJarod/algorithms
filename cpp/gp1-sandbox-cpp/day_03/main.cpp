#include <iostream>
#include <string>
#include "vector2D.h"
using namespace day_03;
int main(int, char*[])
{
const vector2D v1(2.0f, 1.5f);
vector2D v2(0.5f, 3.0f);
std::cout << "v1 + v2 : " << (v1 + v2) << std::endl;
v2 += v1;
std::cout << "v2 : " << v2 << std::endl;
std::cout << "v1 - v2 : " << (v1 - v2) << std::endl;
v2 -= v1;
std::cout << "v2 : " << v2 << std::endl;
std::cout << "-v1 : " << (-v1) << std::endl;
std::cout << "v1 * 5.0f : " << (v1 * 5.0f) << std::endl;
std::cout << "5.0f * v1 : " << (5.0f * v1) << std::endl;
std::cout << "v1 / 2.0f : " << (v1 / 2.0f) << std::endl;
std::cout << "2.0f / v1 : " << (2.0f / v1) << std::endl;
v2 *= 2.0f;
std::cout << "v2 : " << v2 << std::endl;
v2 /= 2.0f;
std::cout << "v2 : " << v2 << std::endl;
v2++; // v2.x *= (length + 1) / length; v2.y *= (length + 1) / length;
std::cout << "v2 : " << v2 << std::endl;
v2--; // v2.x *= (length - 1) / length; v2.y *= (length - 1) / length;
std::cout << "v2 : " << v2 << std::endl;
std::cout << "dot product between v1 and v2 : " << (v1,v2) << std::endl;
return EXIT_SUCCESS;
}