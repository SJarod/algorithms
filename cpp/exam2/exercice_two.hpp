#pragma once

#include <vector>

#include "utils.hpp"

/*
Exercice 2 : Search Insert Position
A partir d’un tableau trié par ordre croissant d’entiers distincts et d’une valeur cible,
renvoyez l’index de la valeur cible si elle y a été trouvée.
Si la valeur cible ne s’y trouve pas, renvoyez l’index où elle aurait dû être insérée en respectant
l’ordre croissant.
La version naïve de complexité O(n) étant plutôt évidente, il est demandé d’implémenter une
version optimisée avec une complexité O(log n).
Exemple 1 :
Input: nums = [1,3,5,6], target = 5
Output: 2
Exemple 2 :
Input: nums = [1,3,5,6], target = 2
Output: 1
Exemple 3 :
Input: nums = [1,3,5,6], target = 7
Output: 4
*/

/**
 * Recursive search insert position function
 */
int search_insert_position_private(const std::vector<int>& nums, const int segmentStartIndex, const int target)
{
    // split array for binary search

    if (nums.size() == 1)
        return segmentStartIndex + (target > nums[nums.size() - 1]);
        
    // segment 1
    std::vector<int> s1(nums.begin(), nums.begin() + nums.size() / 2);
    // segmen 2
    std::vector<int> s2(nums.begin() + nums.size() / 2, nums.begin() + nums.size());

    int result = -1;
    if (target <= s1[s1.size() - 1])
        result = search_insert_position_private(s1, segmentStartIndex, target);
    else
        result = search_insert_position_private(s2, segmentStartIndex + nums.size() / 2, target);

    return result;
}

int searchInsert(std::vector<int>& nums, int target)
{
    return search_insert_position_private(nums, 0, target);
}

void exercice_two()
{
    // example 1
    {
        printf("example 1\n");
        std::vector<int> a = { 1, 3, 5, 6 };
        int target = 5;
        printf("vector : ");
        print_vector(a);
        printf("target : %d\n", target);
        printf("index : %d\n", searchInsert(a, target));
        printf("\n");
    }
    // example 2
    {
        printf("example 2\n");
        std::vector<int> a = { 1, 3, 5, 6 };
        int target = 2;
        printf("vector : ");
        print_vector(a);
        printf("target : %d\n", target);
        printf("index : %d\n", searchInsert(a, target));
        printf("\n");
    }
    // example 3
    {
        printf("example 3\n");
        std::vector<int> a = { 1, 3, 5, 6 };
        int target = 7;
        printf("vector : ");
        print_vector(a);
        printf("target : %d\n", target);
        printf("index : %d\n", searchInsert(a, target));
        printf("\n");
    }
}