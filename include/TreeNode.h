#include <iostream>
#include <chrono>
#include <utility>

#ifndef NODE_H
#define NODE_H

template<typename KeyType, typename ValueType>
class TreeNode
{
    public:
    KeyType key;
    ValueType value;
    TreeNode* parent;
    TreeNode* left;
    TreeNode* right;


    TreeNode(KeyType key, ValueType value);
    ~TreeNode();
};

#endif
