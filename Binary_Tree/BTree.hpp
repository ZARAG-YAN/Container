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
/*    template <class U>
    friend std::ostream& operator<< (std::ostream& out, const BT<U>& tree);*/
    private:
        node<T>* m_root;
        void destroy(node<T>* address);
        void insert_helper(node<T>*& address, T item);
        void inorder_helper(node<T>* address);
        void preorder_helper(node<T>* address);
        void postorder_helper(node<T>* address);
        void find_helper(node<T>*, T);
        void find_parent(node<T>* root, node<T>*& parent, T item);

    public:

        // Constructors.
        BT();
        ~BT();
        node<T>* m_parent;
        int m_count;

	    // Traversal.
        void inorder();
        void preorder();
        void postorder();

        // Other methods.
        void insert(T);
        void find(T);
        void p_p(T);
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
void BT<T>::find_helper(node<T>* root, T item)
{
    if (NULL == root) {
        std::cout <<item<<" not found:\n";
        return;
    }
    if (item == root-> data) {
        std::cout <<item <<" found: \n";
        return;
    }
    if (item < root-> data) {
        find_helper(root-> left, item);
    } else {
        find_helper(root-> right, item);
    }
}


template <typename T>
void BT<T>::find(T item)
{
    find_helper(m_root, item);
}


template <typename T>
void BT<T>::find_parent(node<T>* root, node<T>*& parent, T item)
{
    if (NULL == root) {
        std::cout <<item<<" not found:\n";
        return;
    }
    if (item == root-> data) {
        std::cout <<item <<" found: \n";
        return;
    }
    if (item < root-> data) {
        m_parent = root;
        find_helper(root-> left, item);
    } else {
        m_parent = root;
        find_helper(root-> right, item);
    }
}

template <typename T>
void BT<T>::p_p(T item)
{
    find_parent(m_root, m_parent, item);
    std::cout <<"m_parent of "<< item <<"is equal to "<<*m_parent;
}
/*
template <class U>
std::ostream& operator<< (std::ostream& out, const BT<U>& tree)
{
    out << tree.m_parent;
    return out;
}
*/




