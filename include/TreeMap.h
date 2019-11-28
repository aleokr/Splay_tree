#include <iostream>
#include <chrono>
#include <utility>
#include "TreeNode.h"

#ifndef TREE_H
#define TREE_H

template<typename KeyType, typename ValueType>
class TreeMap
{
  public:
    TreeNode <KeyType, ValueType> *root=NULL;

    using key_type = KeyType;
    using mapped_type = ValueType;
    using value_type = std::pair<const key_type, mapped_type>;

    TreeMap() = default;
    ~TreeMap()= default;

    void destroy (TreeNode<KeyType, ValueType>* node );
    bool isEmpty(); //true jezeli slownik jest pusty

    void insert(const key_type& k, const mapped_type &value); // dodaje wpis do słownika
    void insert(const value_type &key_value); // dodaje wpis przez podanie pary klucz-wartość
    ValueType value(const key_type& k); //zwraca wartośc dla podanego klucza
    bool contains(const key_type& k);// zwraca wartość czy istnieje w slowniku podany klucz
    size_t size(); // liczba wpisow w slowniku
    ValueType& operator[](const key_type& k); //zwraca referencje na wartosc dla podanego klucza, jezeli elementu nie ma w slowniku, dodaje go

};

template<typename KeyType, typename ValueType>
TreeNode<KeyType, ValueType>* rightRotate(TreeNode<KeyType, ValueType> *node);

template<typename KeyType, typename ValueType>
TreeNode<KeyType, ValueType>* leftRotate(TreeNode<KeyType, ValueType> *node);

template<typename KeyType, typename ValueType>
TreeNode<KeyType, ValueType>* splay(TreeNode<KeyType, ValueType> *root, KeyType key);

#endif
