#pragma once

template <typename T>
void swap(T* a, T* b)
{
    T c = *a;
    *a = *b;
    *b = c;
}

template <typename T>
T add(T a, T b)
{
    return a + b;
}