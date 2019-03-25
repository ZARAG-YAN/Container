#include <iostream>
#include <BTree.hpp>

BT::BT()
    : m_root(nullptr)
    , m_size(0)
{
}

BT::~BT()
{


}

void BT::insert(int item)
{
    inert(node* m_root, item);
}

void BT""insert_helper(node* m_root, int item)
{
    if (m_root == NULL) {
        m_root -> data = item;
        return;
    }
    node* node = new node;

    if ( item <= data) {
        insert_helper(m_root -> left, item);
    } else {
        insert_helper(m_root -> right, item);
    }
}

void BT::inorder(node* m_root)
{
    if (m_root != NULL) {
        inorder(m_root -> left);
        std::cout << m_root -> data << " ";
        inorder(m_root -> right);
    }
}

void BT::preorder(node* m_root)
{
    if (m_root != NULL) {
        std::cout << m_root -> data << " ";
        preorder(m_root -> left);
        preorder(m_root -> right);
    }
}
void BT::postorder(node* m_root)
{
    if (m_root != NULL) {
        postorder(m_root -> left);
        postorder(m_root -> right);
        std::cout << m_root -> data << " ";
    }
}
