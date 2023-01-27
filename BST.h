using namespace std;

template <class T>
struct node
{
    T key;
    node<T> *left, *right;
};

template <class T>
node<T> *create_node(T key)
{
    node<T> *new_node = new node<T>;
    if (!new_node)
    {
        cout << "Not enough memory!" << endl;
    }
    new_node->key = key;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

template <class T>
class BST
{
private:
    node<T> *root;

public:
    BST(T key)
    {
        root = create_node(key);
    }

    node<T> *insert_node(int key, node<T> *root)
    {
        // base case
        if (!root)
        {
            return create_node(key);
        }
        // finding the appropiate node
        if (key < root->key)
            root->left = insert_node(key, root->left);
        else if (key > root->key)
            root->right = insert_node(key, root->right);
        return root;
    }
    void insert_node(int key)
    {
        this->insert_node(key, this->root);
    }
    void inorder(node<T> *root)
    {
        if (!root)
        {
            return;
        }
        inorder(root->left);
        cout << root->key << ", ";
        inorder(root->right);
        return;
    }
    void inorder()
    {
        this->inorder(this->root);
    }
    void preorder(node<T> *root)
    {
        if (!root)
        {
            return;
        }
        cout << root->key << ", ";
        preorder(root->left);
        preorder(root->right);
        return;
    }
    void preorder()
    {
        this->preorder(this->root);
    }
    void postorder(node<T> *root)
    {
        if (!root)
        {
            return;
        }
        postorder(root->left);
        postorder(root->right);
        cout << root->key << ", ";
        return;
    }
    void postorder()
    {
        this->postorder(this->root);
    }
    node<T> *find_min()
    {
        if (!root)
        {
            cout << "No tree";
            return -1;
        }
        node<T> *temp = root;
        while (temp->left)
        {
            temp = temp->left;
        }
        return temp;
    }
    node<T> *find_max()
    {
        if (!root)
        {
            cout << "No tree";
            return -1;
        }
        node<T> *temp = root;
        while (temp->right)
        {
            temp = temp->right;
        }
        return temp;
    }
    void findPredecessor(Node *root, int key, Node *&pred)
    {
        // base case
        if (root == NULL)
        {
            pred = NULL;
            return;
        }

        // if the root is our key node then the predecessor will be the largest node in its left subtree
        if (root->data == key)
        {
            if (root->left != NULL)
            {
                pred = find_max(root->left);
            }
        }

        // if our key value is less than the root node value then we'll search in left subtree for key node
        else if (key < root->data)
        {
            findPredecessor(root->left, key, pred);
        }

        // if our key value is more than the root node value then we'll search in right subtree for key node
        else if (key > root->data)
        {
            // update predecessor to the current node before recursing in the right subtree
            pred = root;
            findPredecessor(root->right, key, pred);
        }
        return;
    }

    node<T> *delete_node(T key, node<T> *root)
    {
        // base case
        if (root == NULL)
        {
            return NULL;
        }
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        // find the node to be deleted
        if (key < root->key)
            root->left = delete_node(key, root->left);
        else if (key > root->key)
            root->left = delete_node(key, root->right);
        // deletetion Stratergy
        else
        {
            node<T> *pred;
            findPredecessor(root, key, pred);
            root->key == pred->key;
            root->left = delete_node(pred->data, root->left);
        }
        return root;
    }
    void delete_node(T key)
    {
        delete_node(key, root);
    }
    node<T> *ret_root()
    {
        return root;
    }
    friend ostream &operator<<(ostream &os, BST<T> &temp);
};

template <class T>
ostream &operator<<(ostream &os, BST<T> &temp)
{
    os >> temp->key >> endl;
    return os;
}