#pragma once

#include "TreeNode.h"
#include "utils.hpp"

/*
Exercice 4 : Validate Binary Search Tree
A partir du nœud root d’un arbre binaire, déterminer s’il s’agit d’un arbre binaire de recherche
valide (BST).
Un BST valide est défini par les critères suivants :
- le sous-arbre de gauche d’un noeud ne contient que des nœuds avec des clés de
valeur inférieure
- le sous-arbre de droite d’un noeud ne contient que des nœuds avec des clés de valeur
supérieure
- les sous arbres gauche et droite doivent également être des BST
Exemple 1 :

Input: root = [2,1,3]
Output: true
Exemple 2 :

Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
Vous utiliserez la structure de liste fournie dans le fichier TreeNode.h
Le rendu sera effectué sous la forme d’une fonction ayant le prototype suivant :
bool isValidBST(TreeNode* root)
Vous validerez votre fonction avec des tests issus des exemples 1 et 2.
*/

bool is_valid_search_node(const TreeNode* node)
{
    if (!node)
        return true;

    bool leftValid = node->left && node->left->val <= node->val || !node->left;
    bool rightValid = node->right && node->right->val >= node->val || !node->right;
    return leftValid && rightValid;
}

bool is_valid_search_node_recurse(const TreeNode* node)
{
    if (!is_valid_search_node(node))
        return false;

    if (node->left && !is_valid_search_node_recurse(node->left))
        return false;
    if (node->right && !is_valid_search_node_recurse(node->right))
        return false;

    return true;
}

bool isValidBST(TreeNode* root)
{
    return is_valid_search_node_recurse(root);
}

void exercice_four()
{
    // example 1
    {
        printf("example 1\n");
        TreeNode c(3);
        TreeNode b(1);
        TreeNode a(2, &b, &c);
        printf("is valid BST : %d\n", isValidBST(&a));

        printf("\n");
    }
    // example 2
    {
        printf("example 2\n");
        TreeNode e(6);
        TreeNode d(3);
        TreeNode c(4, &d, &e);
        TreeNode b(1);
        TreeNode a(5, &b, &c);
        printf("is valid BST : %d\n", isValidBST(&a));

        printf("\n");
    }
}