#include <stdexcept>
#include <cstdlib>

template<typename T>
inline T random(T a, T b)
{
    throw std::runtime_error("implementation");
}

template<>
inline int random<int>(int a, int b)
{
    return a + (std::rand()) / ((RAND_MAX / (b + 1 - a)));
}

template<>
inline float random<float>(float a, float b)
{
    return a + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (b - a)));
}
