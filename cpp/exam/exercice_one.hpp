#pragma once

#include <iostream>
#include <vector>

#include "TreeNode.h"

void print_vector(const std::vector<int>& v)
{
	std::cout << v[0];
	for (int i = 1; i < v.size(); ++i)
		std::cout << ", " << v[i];
	std::cout << std::endl;
}

// recursive
std::vector<int> inorderTraversal(TreeNode* root)
{
	std::vector<int> out;

	if (root->left)
		out = inorderTraversal(root->left);
	out.push_back(root->val);

	if (root->right)
	{
		auto rightOut = inorderTraversal(root->right);
		for (const auto& i : rightOut)
			out.push_back(i);
	}

	return out;
}

void exercice_one()
{
	// example 1

	{
		TreeNode one(1); // root
		TreeNode two(2);
		TreeNode three(3);

		one.right = &two;
		two.left = &three;

		auto v = inorderTraversal(&one);
		print_vector(v);
	}

	// example 2

	{
		TreeNode one(1);
		TreeNode two(2);
		TreeNode three(3);
		TreeNode four(4);
		TreeNode five(5);
		TreeNode six(6);

		one.left = &two;
		one.right = &three;
		two.left = &four;
		two.right = &five;
		three.right = &six;

		auto v = inorderTraversal(&one);
		print_vector(v);
	}

	// test 1

	{
		TreeNode one(1);
		TreeNode two(2);
		TreeNode three(3);
		TreeNode four(4);
		TreeNode five(5);
		TreeNode six(6);
		TreeNode seven(7);

		one.left = &two;
		two.left = &three;
		two.right = &four;
		four.left = &five;
		four.right = &six;
		six.left = &seven;

		auto v = inorderTraversal(&one);
		print_vector(v);
	}

	// test 2

	{
		TreeNode one(1);
		TreeNode two(2);
		TreeNode three(3);
		TreeNode four(4);
		TreeNode five(5);
		TreeNode six(6);
		TreeNode seven(7);
		TreeNode eight(8);
		TreeNode nine(9);

		one.left = &two;
		one.right = &three;
		two.left = &four;
		three.left = &five;
		three.right = &six;
		six.left = &seven;
		six.right = &eight;
		seven.left = &nine;

		auto v = inorderTraversal(&one);
		print_vector(v);
	}

	// test 3

	{
		TreeNode one(1);
		TreeNode two(2);
		TreeNode three(3);
		TreeNode four(4);
		TreeNode five(5);

		one.right = &two;
		two.left = &three;
		three.left = &four;
		four.left = &five;

		auto v = inorderTraversal(&one);
		print_vector(v);
	}
}