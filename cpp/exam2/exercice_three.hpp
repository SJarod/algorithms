#pragma once

#include <algorithm>

#include "TreeNode.h"

/*
Exercice 3 : Balanced Binary Tree
A partir d’un arbre binaire donné, déterminer s’il est équilibré ou height-balanced.
Un arbre binaire équilibré est un arbre pour lequel la profondeur des deux sous-arbres de chaque
nœud ne diffère jamais de plus de un.
“A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node
never differs by more than one.”
Exemple 1 :

C’est un arbre équilibré.
Exemple 2 :

Ce n’est pas un arbre équilibré.
Remarque : un arbre vide est considéré comme équilibré.
Vous utiliserez la structure de liste fournie dans le fichier TreeNode.h
Le rendu sera effectué sous la forme d’une fonction ayant le prototype suivant :
bool isBalanced(TreeNode* root)
Vous validerez votre fonction avec des tests issus des exemples 1 et 2.
*/

bool is_node_final(const TreeNode* node)
{
    return !(node->left || node->right);
}

int tree_depth(const TreeNode* node)
{
    if (is_node_final(node))
        return 0;

    int depthLeft = 0, depthRight = 0;
    if (node->left)
        depthLeft = tree_depth(node->left);
    if (node->right)
        depthRight = tree_depth(node->right);
    return 1 + std::max(depthLeft, depthRight);
}

bool isBalanced(TreeNode* root)
{
    int depthLeft = 0, depthRight = 0;
    if (root->left)
        depthLeft = tree_depth(root->left);
    if (root->right)
        depthRight = tree_depth(root->right);

    return std::abs(depthLeft - depthRight) <= 1;
}

void exercice_three()
{
    // example 1
    {
        printf("example 1\n");
        TreeNode e(7);
        TreeNode d(15);
        TreeNode c(20, &d, &e);
        TreeNode b(9);
        TreeNode a(3, &b, &c);
        printf("is balanced : %d\n", isBalanced(&a));

        printf("\n");
    }
    // example 2
    {
        printf("example 2\n");
        TreeNode g(4);
        TreeNode f(4);
        TreeNode e(3);
        TreeNode d(3, &f, &g);
        TreeNode c(2);
        TreeNode b(2, &d, &e);
        TreeNode a(1, &b, &c);
        printf("is balanced : %d\n", isBalanced(&a));

        printf("\n");
    }
}