#include <vector>

std::vector<int> merge_vectors_ascending(std::vector<int>& a, std::vector<int>& b)
{
    std::vector<int> out;

    int i = 0, j = 0;
    while (i < a.size() && j < b.size())
    {
        if (a[i] > b[j])
            out.push_back(b[j++]);
        else
            out.push_back(a[i++]);
    }
    while (i < a.size())
    {
        out.push_back(a[i++]);
    }
    while (j < b.size())
    {
        out.push_back(b[j++]);
    }

    return out;
}

void merge_sort(std::vector<int>& arr)
{
    int half = arr.size() / 2;

    std::vector<int> left, right;
    left.assign(arr.begin(), arr.begin() + half);
    right.assign(arr.begin() + half, arr.end());

    if (left.size() > 1)
        merge_sort(left);
    if (right.size() > 1)
        merge_sort(right);

    std::vector<int> merged = merge_vectors_ascending(left, right);

    for (int k = 0; k < merged.size(); ++k)
    {
        arr[k] = merged[k];
    }
}
