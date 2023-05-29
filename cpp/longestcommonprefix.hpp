#pragma once

#include <vector>
#include <string>
#include <algorithm>

inline std::string longestCommonPrefix(std::vector<std::string>&& strs)
{
    std::sort(strs.begin(), strs.end(), [](const std::string& a, const std::string& b) -> bool { return a.size() < b.size(); });
    std::string prefix;

    for (int i = 0; i < strs[0].size(); ++i)
    {
        char c = '\0';
        for (int j = 0; j < strs.size(); ++j)
        {
            if (strs[0][i] == strs[j][i])
            {
                c = strs[0][i];
            }
            else
            {
                c = '\0';
                break;
            }
        }

        if (c != '\0')
            prefix += c;
    }

    return prefix;
}