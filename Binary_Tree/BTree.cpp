#include <iostream>
#include <BTree.hpp>

BT<T>::BT()
    : m_root(nullptr)
    , m_size(0)
{
}

BT<T>::~BT()
{


}

void BT<T>::insert(T item)
{
    insert_helper(node<T>* m_root, item);
}

void BT<T>::insert_helper(node<T>* m_root, T item)
{
    if (m_root == NULL) {
        m_root -> data = item;
        return;
    }
    node<T>* node = new node<T>;

    if ( item <= data) {
        insert_helper(m_root -> left, item);
    } else {
        insert_helper(m_root -> right, item);
    }
}

void BT<T>::inorder(node<T>* m_root)
{
    if (m_root != NULL) {
        inorder(m_root -> left);
        std::cout << m_root -> data << " ";
        inorder(m_root -> right);
    }
}

void BT<T>::preorder(node<T>* m_root)
{
    if (m_root != NULL) {
        std::cout << m_root -> data << " ";
        preorder(m_root -> left);
        preorder(m_root -> right);
    }
}
void BT<T>::postorder(node<T>* m_root)
{
    if (m_root != NULL) {
        postorder(m_root -> left);
        postorder(m_root -> right);
        std::cout << m_root -> data << " ";
    }
}
