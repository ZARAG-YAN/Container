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
        void destroy(node<T>* root);
        
        // Traversal.
        void inorder_helper(node<T>* root);
        void preorder_helper(node<T>* root);
        void postorder_helper(node<T>* root);
        
        // Other methods.
        void insert_helper(node<T>*& root, T item);
        void find_helper(node<T>*, T);
        void find_parent(node<T>* root, node<T>*& parent, T item, node<T>*& remove_node);

        // find minimum or maximum data functions.
        node<T>* find_min_helper(node<T>* root);
        node<T>* find_max_helper(node<T>* root);
        node<T>* left_right(node<T>* root);
        
        // remove.
        void remove_root(node<T>*, node<T>*);
        void remove_helper(node<T>*, node<T>*, T, node<T>*);

    public:

        // Constructors.
        BT();
        ~BT();
        node<T>* m_parent;
        node<T>* m_r_node;//memeber_remove_node
        int m_count;

	    // Traversal.
        void inorder();
        void preorder();
        void postorder();

        // Other methods.
        void insert(T);
        void find(T);
        void find_min();
        void find_max();
        void remove(T);
        //void print_parent(T);
};
#endif //BTREE_H

// Constructors.
template <typename T>
BT<T>::BT()
    : m_root(NULL)
    , m_parent(NULL)
    , m_r_node(NULL)
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

//Other methods.
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

// find minimum or maximum functions.
template <typename T>
node<T>* BT<T>::find_min_helper(node<T>* root)
{
    if (NULL == root) {
	    std::cout <<"\nTree is empty \n";
	    return root;
    }
    while (NULL != root-> left) {
	    root = root->left;
    }
    return root;
}

template <typename T>
void BT<T>::find_min()
{
    node<T>* tmp = find_min_helper(m_root);
    std::cout <<"\nMaximum data is "<<tmp->data;
    std::cout << std::endl;
    return;
}

template <typename T>
node<T>* BT<T>::find_max_helper(node<T>* root)
{
    if (NULL == root) {
	    std::cout <<"\nTree is empty \n";
	    return root;
    }
    while (NULL != root-> right) {
	    root = root-> right;
    }
    return root;
}

template <typename T>
void BT<T>::find_max()
{
    node<T>* tmp = find_max_helper(m_root);
    std::cout <<"\nMaximum data is "<<tmp->data;
    std::cout << std::endl;
    return;
}


template <typename T>
node<T>* BT<T>::left_right(node<T>* root)
{
    if (NULL == root-> right) {
        return root;
    }
    left_right(root-> right);
}


template <typename T>
void BT<T>::find_parent(node<T>* root, node<T>*& parent, T item, node<T>*& r_node)
{
    if (item == m_root->data) {
        parent = m_root;
        m_r_node = m_root;
	    return;
    }
    if (NULL == root) {
        std::cout <<item<<" not found:\n";
        return;
    }
    if (item == root-> data) {
        return;
    }
    if (item < root-> data) {
	    parent = root;
        find_parent(root-> left, parent, item, r_node);
    } else {
	    parent = root;
        find_parent(root-> right, parent, item, r_node);
    }
    if (item < parent->data) {
	    r_node = parent-> left;
    } else {
	    r_node = parent-> right;
    }
}

/*
template <typename T>
void BT<T>::print_parent(T item)
{
    find_parent(m_root, m_parent, item, m_r_node);
    std::cout <<"m_parent of "<< item <<" is equal to "<< m_parent->data << std::endl;
    std::cout <<"m_r_node "<< item <<" is "<< m_r_node->data << std::endl;
}
*/

//remove methods.
template <typename T>
void BT<T>::remove_root(node<T>* root, node<T>* parent)
{
    std::cout <<"\nRemove Root \n";
    if (NULL == root->left) {
        std::cout <<"Root have one (right) child\n";
        node<T>* tmp = root->left;
        delete root;
        m_root = tmp;
        --m_count;
        return;
    }
    if (NULL == root->right) {
        std::cout <<"Root have one (left) child\n";
        node<T>* tmp = root->right;
        delete root;
        m_root = tmp;
        --m_count;
        return;
    }
    node<T>* max = left_right(root->left);
    if (max == root->left && NULL == max->right) {
        max->right = root->right;
        delete root;
        m_root = max;
        --m_count;
        return ;
    }
    node<T>* tmp_l = root->left;
    node<T>* tmp_r = root->right;
    find_parent(root, parent, max->data, m_r_node);
    parent->right = max->left;
    max->left = parent;
    max->right = tmp_r;
    max->left = tmp_l;
    delete root;
    m_root = max;
    --m_count;
    return;
}


template <typename T>
void BT<T>::remove_helper(node<T>* root, node<T>* parent, T item, node<T>* r_node)
{
    if (NULL == root) {
	    std::cout <<"\nTree is empty\n";
	    return;
    }
    if (item == root->data) {
        remove_root(root, parent);
        return;
    }
    find_parent(root, parent, item, r_node);// after call we have m_parent and remove_node

    // case 1: no child
    if (NULL == r_node-> left && NULL == r_node-> right) {
        delete r_node;
        r_node = NULL;
        --m_count;
        if (item < parent->data) {
	        parent-> left = NULL;
        } else {
	        parent-> right = NULL;
	}
    // case 2: one child
    } else if (NULL == r_node-> left) {
        if (item < parent->data) {
	        parent-> left = r_node-> right;
        } else {
	        parent-> right = r_node-> right;
	}
	delete r_node;
    r_node = NULL;
    --m_count;
    } else if (NULL == r_node-> right) {
        if (item < parent->data) {
	        parent-> left = r_node-> left;
        } else {
	        parent-> right = r_node-> left;
	}
	delete r_node;
    r_node = NULL;
    --m_count;
    // case 3: two child
    } else {
        node<T>* tmp = left_right(r_node->left);
        if (r_node->data < parent->data) {
            parent->left = tmp;
        } else {
            parent->right = tmp;
        }
        tmp-> right = r_node->right;
        delete r_node;
        r_node = NULL;
        --m_count;
        return ;
    }
}

template <typename T>
void BT<T>::remove(T item)
{
    std::cout << "Remove "<< item;
    remove_helper(m_root, m_parent, item, m_r_node);
    std::cout << std::endl;
    return;
}


