#include <vector>

inline void quick_sort_recurse(std::vector<int>& arr, int start, int end)
{
    if (end - start <= 0)
        return;

    int i = start; // processed index
    int ii = i + 1; // swapping index
    while (ii < end)
    {
        if (arr[i] > arr[end])
            std::swap(arr[i], arr[ii++]);
        else
            ii = ++i + 1;
    }

    int p = arr[i] > arr[end] ? i : i + 1;
    std::swap(arr[p], arr[end]);

    quick_sort_recurse(arr, 0, p - 1);
    quick_sort_recurse(arr, p + 1, end);
}

inline void quick_sort(std::vector<int>& arr)
{
    quick_sort_recurse(arr, 0, arr.size() - 1);
}
