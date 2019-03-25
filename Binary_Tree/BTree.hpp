#include <iostream>
template <typename T>
struct node
{
    int data;
    node* left;
    node* right;
};

template <class T>
class BT
{
    private:
        node<T>* m_root;
        int m_size;
        void insert_helper(node<T>* root, T item);
    public:
        BT();
        BT(const BT& other);
        ~BT();
        void insert(T item);
        void inorder(node<T>* root);
        void preorder(node<T>* root);
        void postorder(node<T>* root);
        void find(node<T>* root);

};
