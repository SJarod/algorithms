#include <iostream>
#include <vector>

#include "rand.hpp"

template<typename T>
inline std::vector<T> generate_vector(unsigned int size, T min, T max)
{
    std::vector<T> out(size);
    for (int i = 0; i < size; ++i)
    {
        out[i] = random<T>(min, max);
    }
    return out;
}

template<typename T>
inline void print_vector(std::vector<T> v)
{
    for (auto a : v)
    {
        std::cout << a << ", ";
    }
    std::cout << std::endl;
}
