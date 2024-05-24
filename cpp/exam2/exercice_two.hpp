#pragma once

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