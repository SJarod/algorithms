#pragma once

#include <iostream>
#include <vector>
#include <cassert>
#include <deque>
#include <algorithm>

/*
Exercice 1 : Merge Sorted Array
A partir de deux tableaux d’entiers nums1 et nums2, triés dans l’ordre croissant, et de deux
entiers m et n, représentant respectivement le nombre d’éléments dans les tableaux nums1 et
nums2.
Vous devez fusionner les tableaux nums1 et nums2 en un seul tableau et celà dans l’ordre
croissant.
Pour le réaliser, nums1 aura une taille de m + n, où les m premiers éléments seront les
éléments à fusionner, et les derniers n éléments seront mis à la valeur 0 et seront ignorés.
nums2 sera lui de taille n.
Exemple 1 :
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
Exemple 2 :
Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].
Exemple 3 :
Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge
result can fit in nums1.
Le rendu sera effectué sous la forme d’une fonction ayant le prototype suivant :
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)

Vous validerez votre fonction avec des tests issus des exemples 1, 2 et 3.
*/

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
{
    std::vector<int> merged(m + n, 0);
    std::deque<int> temp1(nums1.begin(), nums1.begin() + m);
    std::deque<int> temp2(nums2.begin(), nums2.begin() + n);
    for (int i = 0; i < m + n; ++i)
    {
        if (temp1.empty())
        {
            merged[i] = temp2.front();
            temp2.pop_front();
            continue;
        }
        if (temp2.empty())
        {
            merged[i] = temp1.front();
            temp1.pop_front();
            continue;
        }
        if (temp1.front() <= temp2.front())
        {
            merged[i] = temp1.front();
            temp1.pop_front();
        }
        else
        {
            merged[i] = temp2.front();
            temp2.pop_front();
        }
    }
    nums1.assign(merged.begin(), merged.begin() + m + n);
}

/**
 * Merge sorted array function with std::sort
 */
void merge_std(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
{
    for (int i = m, j = 0; i < m + n; ++i, ++j)
    {
        nums1[i] = nums2[j];
    }
    std::sort(nums1.begin(), nums1.begin() + m + n);
}

void print_vector(const std::vector<int>& v)
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

void exercice_one()
{
    // example 1
    {
        printf("example 1\n");
        std::vector<int> nums1 = {1, 2, 3, 0, 0, 0};
        int m = 3;
        std::vector<int> nums2 = {2, 5, 6};
        int n = 3;

        printf("nums1 : ");
        print_vector(nums1);
        printf("nums2 : ");
        print_vector(nums2);

        merge(nums1, m, nums2, n);
        printf("merged : ");
        print_vector(nums1);

        printf("\n");
    }
    // example 2
    {
        printf("example 2\n");
        std::vector<int> nums1 = {1};
        int m = 1;
        std::vector<int> nums2 = {};
        int n = 0;

        printf("nums1 : ");
        print_vector(nums1);
        printf("nums2 : ");
        print_vector(nums2);

        merge(nums1, m, nums2, n);
        printf("merged : ");
        print_vector(nums1);

        printf("\n");
    }
    // example 3
    {
        printf("example 3\n");
        std::vector<int> nums1 = {0};
        int m = 0;
        std::vector<int> nums2 = {1};
        int n = 1;

        printf("nums1 : ");
        print_vector(nums1);
        printf("nums2 : ");
        print_vector(nums2);

        merge(nums1, m, nums2, n);
        printf("merged : ");
        print_vector(nums1);

        printf("\n");
    }
}