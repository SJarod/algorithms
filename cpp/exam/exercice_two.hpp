#pragma once

#include <iostream>
#include <vector>

#include "ListNode.h"

void print_list_node(ListNode* l)
{
	std::cout << l->val;
	if (l->next)
	{
		std::cout << ", ";
		print_list_node(l->next);
	}
	else
	{
		std::cout << std::endl;
	}
}

ListNode* new_list(int a...)
{
	throw;
}

ListNode* new_list(const std::vector<int>& v)
{
	ListNode* out = nullptr;
	ListNode* prev = nullptr;
	for (const auto& i : v)
	{
		ListNode* node = new ListNode;
		node->val = i;
		if (!out)
		{
			out = node;
			prev = node;
		}
		else
		{
			prev->next = node;
			prev = node;
		}
	}

	return out;
}

void delete_list(ListNode* l)
{
	if (l->next)
		delete_list(l->next);
	delete l;
}

int get_number_from_list(ListNode* l)
{
	int out = 0;
	if (l->next)
	{
		out = get_number_from_list(l->next);
	}
	return out * 10 + l->val;
}

ListNode* create_list_from_number(int n)
{
	int nn = n % 10;
	ListNode* node = new ListNode;
	node->val = nn;

	if (n - nn > 0)
		node->next = create_list_from_number(n / 10);

	return node;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	int a = get_number_from_list(l1);
	int b = get_number_from_list(l2);

	return create_list_from_number(a + b);
}

void exercice_two()
{
	// test 1

	{
		ListNode two(2);
		ListNode four(4);
		ListNode three(3);

		two.next = &four;
		four.next = &three;

		ListNode five(5);
		ListNode six(6);
		ListNode four2(4);

		five.next = &six;
		six.next = &four2;

		print_list_node(&two);
		print_list_node(&five);

		auto r = addTwoNumbers(&two, &five);
		print_list_node(r);
		delete_list(r);
	}

	// test 2

	{
		ListNode zero(0);

		ListNode zero2(0);

		print_list_node(&zero);
		print_list_node(&zero2);

		auto r = addTwoNumbers(&zero, &zero2);
		print_list_node(r);
		delete_list(r);
	}

	// test 3

	{
		ListNode* l1 = new_list({ 9, 9, 9, 9, 9, 9, 9 });

		ListNode* l2 = new_list({ 9, 9, 9, 9 });

		print_list_node(l1);
		print_list_node(l2);

		auto r = addTwoNumbers(l1, l2);
		print_list_node(r);

		delete_list(l1);
		delete_list(l2);
		delete_list(r);
	}
}