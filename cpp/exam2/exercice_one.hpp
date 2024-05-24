#pragma once

#include <iostream>
#include <vector>
#include <cassert>

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
    std::vector<int> temp1;
    temp1.assign(nums1.begin(), nums1.begin() + m);
    std::vector<int> temp2;
    temp2.assign(nums2.begin(), nums2.begin() + n);

    auto changeValue = [&](int i, int val) {
        nums1[i++] = val;
    };

    int i = 0;
    for (int a : temp1)
    {
        for (int b : temp2)
        {
            if (a >= b)
            {
                changeValue(i, b);
                break;
            }
            else
            {
                changeValue(i, a);
            }
        }
    }
}

void print_vector(const std::vector<int>& v)
{
    assert(!v.empty());
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
    }
}