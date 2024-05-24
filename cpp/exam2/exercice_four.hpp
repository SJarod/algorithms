#pragma once

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