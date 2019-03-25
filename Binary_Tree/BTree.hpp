#include <iostream>

struct node
{
    int data;
    node* left;
    node* right;
};

class BT
{
private:
    node* m_root;
    int m_size;
    void insert_helper(node* root, int item);
public:
    BT();
    BT(const BT& other);
    ~BT();
    void insert(int item);
    void unorder(node*root);
    void preorder(node*root);
    void postorder(node*root);
    void finde(node* root);

};
