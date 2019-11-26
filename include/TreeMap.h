#include <iostream>
#include <chrono>
#include <utility>
#include "TreeNode.h"

template<typename KeyType, typename ValueType>
class TreeMap
{
  public:
    TreeNode <KeyType, ValueType> *root=NULL;

    using key_type = KeyType;
    using mapped_type = ValueType;
    using value_type = std::pair<const key_type, mapped_type>;

    TreeMap() = default;    
    ~TreeMap() = default;   

    bool isEmpty();
    void insert(const key_type& k, const mapped_type &value);
    void insert(const value_type &key_value);

    // /*!
    //  * zwraca referencje na wartosc dla podanego klucza
    //  *
    //  * jezeli elementu nie ma w slowniku, dodaje go
    //  */
    // mapped_type& operator[](const key_type& key)
    // {
    //     throw std::runtime_error("TODO: operator[]");
    // }

    /*!
     * zwraca wartosc dla podanego klucza
     */
    // const mapped_type& value(const key_type& key);
    // {
    //     throw std::runtime_error("TODO: value");
    // }

    // /*!
    //  * zwraca informacje, czy istnieje w slowniku podany klucz
    //  */
    bool contains(const key_type& k);// const {
    //     throw std::runtime_error("TODO: contains");
    // }

    // /*!
    //  * zwraca liczbe wpisow w slowniku
    //  */
    // size_t size() const {
    //     throw std::runtime_error("TODO: size");
    // }

};

template<typename KeyType, typename ValueType>
TreeNode<KeyType, ValueType>* rightRotate(TreeNode<KeyType, ValueType> *node);

template<typename KeyType, typename ValueType>
TreeNode<KeyType, ValueType>* leftRotate(TreeNode<KeyType, ValueType> *node);

template<typename KeyType, typename ValueType>
TreeNode<KeyType, ValueType>* splay(TreeNode<KeyType, ValueType> *root, KeyType key);