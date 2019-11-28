#include "TreeMap.h"
#include <iostream>

using namespace std;

template<typename KeyType, typename ValueType>
bool TreeMap<KeyType, ValueType>::isEmpty(){
    if(this-> root == NULL)
    return true;
    else
    return false;
}

template<typename KeyType, typename ValueType>
TreeNode<KeyType, ValueType>* rightRotate(TreeNode<KeyType, ValueType> *node)
{
    TreeNode<KeyType, ValueType> *y = node->left;
    node ->left= y->right;
    y->right=node;
    return (y);
}

template<typename KeyType, typename ValueType>
TreeNode<KeyType, ValueType>* leftRotate(TreeNode<KeyType, ValueType> *node)
{
    TreeNode<KeyType, ValueType> *y = node->right;
    node ->right= y->left;
    y->left=node;
    return (y);
}

template<typename KeyType, typename ValueType>
void destroy (TreeNode<KeyType, ValueType>* node ){
        if ( node ){
            destroy( node->left );
            destroy( node->right );
            delete node;
        }
}

template<typename KeyType, typename ValueType>
TreeNode<KeyType, ValueType>* splay(TreeNode<KeyType, ValueType> *root, KeyType key){

    if (root == NULL || root->key == key)
        return root;

    if (root->key > key)   {
        if (root->left == NULL) return root;
        if (root->left->key > key)   {
            root->left->left = splay(root->left->left, key);
            root = rightRotate(root);
        }
        else if (root->left->key < key) {
            root->left->right = splay(root->left->right, key);
            if (root->left->right != NULL)
                root->left = leftRotate(root->left);
        }
        return (root->left == NULL)? root: rightRotate(root);
    }
    else
    {
        if (root->right == NULL) return root;
        if (root->right->key > key)
        {
            root->right->left = splay(root->right->left, key);
            if (root->right->left != NULL)
                root->right = rightRotate(root->right);
        }
        else if (root->right->key < key)
        {
            root->right->right = splay(root->right->right, key);
            root = leftRotate(root);
        }
        return (root->right == NULL)? root: leftRotate(root);
    }
}

template<typename KeyType, typename ValueType>
void TreeMap<KeyType, ValueType>::insert(const key_type& k, const mapped_type &value){
    if (this->root == NULL)
    {
        this->root =  new TreeNode<KeyType, ValueType>(k, value);
        return;
    }
    TreeNode<KeyType, ValueType> *curr = this -> root;
    while (curr != NULL)
    {
        if (k < curr -> key)
        {
            if (curr -> left == NULL)
            {
                TreeNode<KeyType, ValueType> *newNode = new TreeNode<KeyType, ValueType>(k, value);
                curr -> left = newNode;
                newNode -> parent = curr;
                splay(newNode, k);
                return;
            }
            else curr = curr -> left;
        }
        else if (k > curr -> key)
        {
            if (curr -> right == NULL)
            {
                TreeNode<KeyType, ValueType> *newNode = new TreeNode<KeyType, ValueType>(k, value);
                curr -> right = newNode;
                newNode -> parent = curr;
                splay(newNode, k);
                return;
            }
            else curr = curr -> right;
        }
        else
        {
            splay(curr, k);
            return;
        }
    }


}

template<typename KeyType, typename ValueType>
void TreeMap<KeyType, ValueType>::insert(const value_type &key_value){
    this->insert(key_value.first, key_value.second);
}

template<typename KeyType, typename ValueType>
bool TreeMap<KeyType, ValueType>::contains(const key_type& k){
    TreeNode< KeyType, ValueType> *ret = NULL;
    TreeNode< KeyType, ValueType> *curr = this -> root;
    TreeNode< KeyType, ValueType> *prev = NULL;
    while (curr != NULL)
    {
        prev = curr;
        if (k < curr -> key) curr = curr -> left;
        else if (k > curr -> key) curr = curr -> right;
        else
        {
            ret = curr;
            break;
        }
    }
    if (ret != NULL) splay(ret, k);
    else if (prev != NULL) splay(prev, k);
    if(ret!=NULL) return true;
    else return false;
}

template<typename KeyType, typename ValueType>
ValueType TreeMap<KeyType, ValueType>::value(const key_type& k){
    TreeNode< KeyType, ValueType> *ret = NULL;
    TreeNode< KeyType, ValueType> *curr = this -> root;
    TreeNode< KeyType, ValueType> *prev = NULL;
    while (curr != NULL)
    {
        prev = curr;
        if (k < curr -> key) curr = curr -> left;
        else if (k > curr -> key) curr = curr -> right;
        else
        {
            ret = curr;
            break;
        }
    }
    if (ret != NULL) splay(ret, k);
    else if (prev != NULL) splay(prev, k);
    if(ret!=NULL) return ret->value;
    else return 0;
}

template<typename KeyType, typename ValueType>
size_t TreeMap<KeyType, ValueType>::size(){
    return sizeof(this);
}

template<typename KeyType, typename ValueType>
ValueType& TreeMap<KeyType, ValueType>::operator[](const KeyType& k)
{
    TreeNode< KeyType, ValueType> *ret = NULL;
    TreeNode< KeyType, ValueType> *curr = this -> root;
    TreeNode< KeyType, ValueType> *prev = NULL;

    while (curr != NULL)
    {
        prev = curr;
        if (k < curr -> key) curr = curr -> left;
        else if (k > curr -> key) curr = curr -> right;
        else
        {
            ret = curr;
            break;
        }
    }
    if (ret != NULL) splay(ret, k);
    else if (prev != NULL) splay(prev, k);

    if(ret!=NULL) return ret->value;
    else
    {
        mapped_type valNull=mapped_type(); //jakakolwiek wartosc
        this->insert(k, valNull);
        ret = NULL;
        curr = this -> root;
        prev = NULL;

        while (curr != NULL)
        {
            prev = curr;
            if (k < curr -> key) curr = curr -> left;
            else if (k > curr -> key) curr = curr -> right;
            else
            {
                ret = curr;
                break;
            }
        }
        if (ret != NULL) splay(ret, k);
        else if (prev != NULL) splay(prev, k);
        return ret->value;
    }

}


template class TreeMap<int, int>;
template class TreeMap<std::string, std::string>;
