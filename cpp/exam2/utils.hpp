#pragma once

inline void print_vector(const std::vector<int>& v)
{
    if (v.empty())
    {
        printf("{0}\n");
        return;
    }

    printf("%d", v[0]);
    for (int i = 1; i < v.size(); ++i)
    {
        printf(", %d", v[i]);
    }
    printf("\n");
}