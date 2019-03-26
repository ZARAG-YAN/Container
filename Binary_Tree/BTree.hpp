#ifndef BTREE_H
#define BTREE_H
#include <iostream>
template <typename T>
struct node
{
    T data;
    node<T>* left;
    node<T>* right;
    node()
     :left(NULL)
     ,right(NULL)
    {
    }

};

template <typename T>
class BT
{
    private:
        node<T>* m_root;
        node<T>* m_parent;
        void destroy(node<T>* address);
        void insert_helper(node<T>*& address, T item);
        void inorder_helper(node<T>* address);
        void preorder_helper(node<T>* address);
        void postorder_helper(node<T>* address);
        void find_parent(node<T>* address, node<T>*& parent, T item);

    public:

        // Constructors.
        BT();
        ~BT();
        int m_count;

	    // Traversal.
        void inorder();
        void preorder();
        void postorder();

        // Other methods.
        // void find(node<T>*, T);
        // void print();
        void insert(T item);
};
#endif //BTREE_H

// Constructors.
template <typename T>
BT<T>::BT()
    : m_root(NULL)
    , m_parent(NULL)
    , m_count(0)
{
}

template <typename T>
BT<T>::~BT()
{
    destroy(m_root);
}

template <typename T>
void BT<T>::destroy(node<T>* address)
{
    if (NULL != address) {
        destroy(address->left);
        destroy(address->right);
        delete address;
        address = NULL;
    }
}

// Insertions.
template <typename T>
void BT<T>::insert(T item)
{
    std::cout <<"\nInsert  "<< item;
    insert_helper(m_root, item);
    ++m_count;
}


template <typename T>
void BT<T>::insert_helper(node<T>*& address, T item)
{
    if (NULL == address) {
        address = new node<T>;
        address->data = item;
        return;
    }
    if (item < address->data) {
        insert_helper(address->left, item);
    } else {
        insert_helper(address->right, item);
    }
}

// Traversal orders.
template <typename T>
void BT<T>::inorder_helper(node<T>* address)
{
    if (NULL != address) {
        inorder_helper(address-> left);
        std::cout << address-> data << " ";
        inorder_helper(address-> right);
    }
}

template <typename T>
void BT<T>::inorder()
{
    inorder_helper(m_root);
    std::cout << std::endl;
}


template <typename T>
void BT<T>::preorder_helper(node<T>* address)
{
    if (NULL != address) {
        std::cout << address-> data << " ";
        preorder_helper(address-> left);
        preorder_helper(address-> right);
    }
}

template <typename T>
void BT<T>::preorder()
{
    preorder_helper(m_root);
    std::cout << std::endl;
}


template <typename T>
void BT<T>::postorder_helper(node<T>* address)
{
    if (NULL != address) {
        preorder_helper(address-> left);
        preorder_helper(address-> right);
        std::cout << address-> data << " ";
    }
}

template <typename T>
void BT<T>::postorder()
{
    postorder_helper(m_root);
    std::cout << std::endl;
}
template <typename T>
void BT<T>::find_parent(node<T>* address, node<T>*& parent, T item)
{
    if (NULL == address) {
        std::cout <<"\nTree is empty\n";
        return;
    }
    if (item < address-> data) {
        parent = address;
        address = address-> left;
    } else {
        parent = address;
        address = address-> right;
    }

}





