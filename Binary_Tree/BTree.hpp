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
        void destroy(node<T>* root);
        void insert_helper(node<T>*& root, T item);
        void inorder_helper(node<T>* root);
        void preorder_helper(node<T>* root);
        void postorder_helper(node<T>* root);
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
void BT<T>::destroy(node<T>* root)
{
    if (NULL != root) {
        destroy(root->left);
        destroy(root->right);
        delete root;
        root = NULL;
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
void BT<T>::insert_helper(node<T>*& root, T item)
{
    if (NULL == root) {
        root = new node<T>;
        root->data = item;
        return;
    }
    if (item < root->data) {
        insert_helper(root->left, item);
    } else {
        insert_helper(root->right, item);
    }
}

// Traversal orders.
template <typename T>
void BT<T>::inorder_helper(node<T>* root)
{
    if (NULL != root) {
        inorder_helper(root-> left);
        std::cout << root-> data << " ";
        inorder_helper(root-> right);
    }
}

template <typename T>
void BT<T>::inorder()
{
    inorder_helper(m_root);
    std::cout << std::endl;
}


template <typename T>
void BT<T>::preorder_helper(node<T>* root)
{
    if (NULL != root) {
        std::cout << root-> data << " ";
        preorder_helper(root-> left);
        preorder_helper(root-> right);
    }
}

template <typename T>
void BT<T>::preorder()
{
    preorder_helper(m_root);
    std::cout << std::endl;
}


template <typename T>
void BT<T>::postorder_helper(node<T>* root)
{
    if (NULL != root) {
        preorder_helper(root-> left);
        preorder_helper(root-> right);
        std::cout << root-> data << " ";
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
    parent = root;
    if (NULL == root) {
        std::cout <<item<<" not found:\n";
        return;
    }
    if (item == root-> data) {
        std::cout <<item <<" found: \n";
        return;
    }
    if (item < root-> data) {
	parent = root;
        find_parent(root-> left, parent, item);
    } else {
	parent = root;
        find_parent(root-> right, parent, item);
    }
}

template <typename T>
void BT<T>::p_p(T item)
{
    find_parent(m_root, m_parent, item);
    std::cout <<"m_parent of "<< item <<" is equal to "<< m_parent->data << std::endl;
}


/*
template <class U>
std::ostream& operator<< (std::ostream& out, const BT<U>& tree)
{
    out << tree.m_parent;
    return out;
}
*/




