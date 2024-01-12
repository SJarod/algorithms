#pragma once

#include <set>

#include "GraphNode.h"

// create a set with unique nodes from the graph (given a node from the graph)
void graph_node_set(std::set<Node*>& unique, Node* node)
{
	unique.emplace(node);
	//unique.insert(node);
	for (const auto& n : node->neighbors)
	{
		// if neighbor node was not added to unique set yet
		if (unique.find(n) == unique.end())
			graph_node_set(unique, n);
	}
}

void print_graph(Node* node)
{
	std::set<Node*> toPrint;
	graph_node_set(toPrint, node);

	for (const auto& n : toPrint)
	{
		std::cout << n->val << " (" << n << ") | ";
		if (!n->neighbors.empty())
		{
			std::cout << n->neighbors[0]->val;
			std::cout << " (" << n->neighbors[0] << ")";
		}
		for (int i = 1; i < n->neighbors.size(); ++i)
		{
			std::cout << ", " << n->neighbors[i]->val;
			std::cout << " (" << n->neighbors[i] << ")";
		}
		std::cout << std::endl;
	}
}

void delete_graph(Node* node)
{
	std::set<Node*> toDelete;
	graph_node_set(toDelete, node);

	for (const auto& n : toDelete)
	{
		delete n;
	}
}

Node* cloneGraph(Node* node)
{
	std::set<Node*> toClone;
	graph_node_set(toClone, node);

	std::vector<Node*> clone(toClone.size(), nullptr);

	// create nodes
	int i = 0;
	for (const auto& n : toClone)
	{
		// create node with value and vector of neightbors (with nullptr value)
		clone[i] = new Node(n->val, std::vector<Node*>(n->neighbors.size(), nullptr));
		++i;
	}

	// link cloned nodes to adjacent cloned nodes based
	// on the toClone set
	i = 0;
	for (const auto& n : toClone)
	{
		int j = 0;
		for (const auto& nn : n->neighbors)
		{
			clone[i]->neighbors[j] = clone[nn->val - 1];
			++j;
		}
		++i;
	}

	return clone.empty() ? nullptr : clone[0];
}

void exercice_three()
{
	Node one(1);
	Node two(2);
	Node three(3);
	Node four(4);

	one.neighbors = { &two, &four };
	two.neighbors = { &one, &three };
	three.neighbors = { &two, &four };
	four.neighbors = { &one, &three };

	print_graph(&one);
	std::cout << std::endl;
	Node* clone = cloneGraph(&one);
	print_graph(clone);
	delete_graph(clone);
}