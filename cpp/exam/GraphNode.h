#pragma once

#include <vector>

using std::vector;

class Node
{
public:
    int val;
    vector<Node*> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};