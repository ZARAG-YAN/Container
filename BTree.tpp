// Constructors.
template <typename T>
BT<T>::BT()
    : m_root(nullptr)
//    , m_parent(nullptr)
    , m_count(0)
{
}

template <typename T>
BT<T>::~BT()
{
    destroy( m_root); 
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
void BT<T>::insert_helper(node<T>* m_root, T item)
{
    std::cout << "\nInsert helper ";
    if (m_root == NULL) {
        m_root->data = item;
        return;
    }
    if (item < m_root->data) {
        m_root->left = insert_helper(m_root->left, item);
    } else {
        m_root->right = insert_helper(m_root->right, item);
    }
}
// Traversal orders.
template <typename T>
void BT<T>::inorder(node<T>* m_root)
{
    std::cout << "\nInorder: ";
    if (m_root != NULL) {
        inorder(m_root-> left);
        std::cout << m_root-> data << " ";
        inorder(m_root-> right);
    }
}
template <typename T>
void inorder()
{
    inorder(m_root);
}

template <typename T>
void BT<T>::preorder(node<T>* m_root)
{
    std::cout << "\nPreorder: ";
    if (m_root != NULL) {
        std::cout << m_root-> data << " ";
        preorder(m_root-> left);
        preorder(m_root-> right);
    }
}
template <typename T>
void preorder()
{
    preorder(m_root);
}

template <typename T>
void BT<T>::postorder(node<T>* m_root)
{
    std::cout << "\nPostroder: ";
    if (m_root != NULL) {
        postorder(m_root-> left);
        postorder(m_root-> right);
        std::cout << m_root-> data << " ";
    }
}

template <typename T>
void postorder()
{
    postorder(m_root);
}
/*void BT<T>::print()
{


}*/
