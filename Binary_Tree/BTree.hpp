#ifndef BTREE_H
#define BTREE_H
#include <iostream>
template <typename T>
struct node
{
    T data;
    node* left;
    node* right;
};

template <typename T>
class BT
{
    private:
        node<T>* m_root;
        int m_count;
        void destroy(node<T>* m_root);
        node<T>* insert_helper(node<T>* m_root, T item);
        void inorder_helper(node<T>* m_root);
        void preorder_helper(node<T>* m_root);
        void postorder_helper(node<T>* m_root);
        
    public:
        
        // Constructors.
        BT();
        ~BT();

	// Traversal.
        void inorder();
        void preorder();
        void postorder();

        // Other methods.
        //void find(node<T>* root, T item);
        // void print();
        void insert(T item);
};
#endif //BTREE_H

// Constructors.
template <typename T>
BT<T>::BT()
    : m_root(nullptr)
    , m_count(0)
{
}

template <typename T>
BT<T>::~BT()
{
    destroy(m_root);
}

template <typename T>
void BT<T>::destroy(node<T>* m_root)
{
    if (m_root != NULL) {
        destroy(m_root->left);
        destroy(m_root->right);
        delete m_root;
        m_root = NULL;
    }
}

// Insertions.
template <typename T>
void BT<T>::insert(T item)
{
    std::cout <<"\nInsert "<< item;
    insert_helper(m_root, item);
    ++m_count;
}


template <typename T>
node<T>* BT<T>::insert_helper(node<T>* m_root, T item)
{
    std::cout << "\nInsert helper ";
    if (m_root == NULL) {
        m_root->data = item;
        return m_root;
    }
    if (item < m_root->data) {
        m_root->left = insert_helper(m_root->left, item);
    } else {
        m_root->right = insert_helper(m_root->right, item);
    }
}

// Traversal orders.
template <typename T>
void BT<T>::inorder_helper(node<T>* m_root)
{
    std::cout << "\nInorder: ";
    if (m_root != NULL) {
        inorder_helper(m_root-> left);
        std::cout << m_root-> data << " ";
        inorder_helper(m_root-> right);
    }
}
template <typename T>
void BT<T>::inorder()
{
    inorder_helper(m_root);
}


template <typename T>
void BT<T>::preorder_helper(node<T>* m_root)
{
    std::cout << "\nPreorder: ";
    if (m_root != NULL) {
        std::cout << m_root-> data << " ";
        preorder_helper(m_root-> left);
        preorder_helper(m_root-> right);
    }   
}
template <typename T>
void BT<T>::preorder()
{
    preorder_helper(m_root);
}

template <typename T>
void BT<T>::postorder_helper(node<T>* m_root)
{
    std::cout << "\nPostroder: ";
    if (m_root != NULL) {
        postorder_helper(m_root-> left);
        postorder_helper(m_root-> right);
        std::cout << m_root-> data << " ";
    }   
}

template <typename T>
void BT<T>::postorder()
{
    postorder_helper(m_root);
}

