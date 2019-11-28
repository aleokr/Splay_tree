#include "TreeNode.h"

template<typename KeyType, typename ValueType>
TreeNode<KeyType, ValueType>::TreeNode(KeyType key, ValueType value)
{
    this -> key = key;
    this -> value = value;
    this -> parent = NULL;
    this -> left = NULL;
    this -> right = NULL;
}

template class TreeNode<int, int>;
template class TreeNode<std::string, std::string>;
