// Binary search tree: every value in a node's left subtree is smaller than
// the node, and every value in its right subtree is larger. Insert, search and delete follow one path from the
// root, so they cost O(h): O(log n) when balanced, O(n) when the tree
// degenerates into a chain (for example, inserting sorted values).
#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BST
{
private:
    Node *root;

    Node *insert(Node *node, int value)
    {
        if (node == nullptr)
            return new Node(value);
        if (value < node->data)
            node->left = insert(node->left, value);
        else if (value > node->data)
            node->right = insert(node->right, value);
        return node; // duplicates are ignored
    }

    Node *findMin(Node *node) const
    {
        while (node->left != nullptr)
            node = node->left;
        return node;
    }

    // Three cases: leaf, one child, two children. With two children, copy
    // the in-order successor (smallest value in the right subtree) into this
    // node and delete the successor instead.
    Node *remove(Node *node, int value)
    {
        if (node == nullptr)
            return nullptr;
        if (value < node->data)
        {
            node->left = remove(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = remove(node->right, value);
        }
        else
        {
            if (node->left == nullptr)
            {
                Node *right = node->right;
                delete node;
                return right;
            }
            if (node->right == nullptr)
            {
                Node *left = node->left;
                delete node;
                return left;
            }
            Node *successor = findMin(node->right);
            node->data = successor->data;
            node->right = remove(node->right, successor->data);
        }
        return node;
    }

    void inorder(Node *node) const
    {
        if (node == nullptr)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void preorder(Node *node) const
    {
        if (node == nullptr)
            return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node *node) const
    {
        if (node == nullptr)
            return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    int height(Node *node) const
    {
        if (node == nullptr)
            return 0;
        return 1 + max(height(node->left), height(node->right));
    }

    void destroy(Node *node)
    {
        if (node == nullptr)
            return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

public:
    BST() : root(nullptr) {}

    // Copying would share nodes and delete them twice, so it is disabled.
    BST(const BST &) = delete;
    BST &operator=(const BST &) = delete;
    ~BST() { destroy(root); }

    void insert(int value) { root = insert(root, value); }
    void remove(int value) { root = remove(root, value); }

    bool search(int value) const
    {
        Node *current = root;
        while (current != nullptr)
        {
            if (value == current->data)
                return true;
            current = value < current->data ? current->left : current->right;
        }
        return false;
    }

    void inorder() const { inorder(root); cout << endl; }
    void preorder() const { preorder(root); cout << endl; }
    void postorder() const { postorder(root); cout << endl; }
    int height() const { return height(root); }

    // Breadth-first: visit the tree level by level using a queue.
    void levelOrder() const
    {
        if (root == nullptr)
            return;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            Node *node = q.front();
            q.pop();
            cout << node->data << " ";
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        cout << endl;
    }
};

int main()
{
    /*
             50
           /    \
         30      70
        /  \    /  \
       20  40  60  80
    */
    BST tree;
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    for (int v : values)
        tree.insert(v);

    cout << "In-order (sorted): ";
    tree.inorder();
    cout << "Pre-order:         ";
    tree.preorder();
    cout << "Post-order:        ";
    tree.postorder();
    cout << "Level-order:       ";
    tree.levelOrder();
    cout << "Height: " << tree.height() << endl;

    cout << "Search 60: " << (tree.search(60) ? "found" : "not found") << endl;
    cout << "Search 65: " << (tree.search(65) ? "found" : "not found") << endl;

    tree.remove(20); // leaf
    tree.remove(70); // two children
    tree.remove(50); // root
    cout << "After removing 20, 70, 50 (in-order): ";
    tree.inorder();
    cout << "Level-order: ";
    tree.levelOrder();

    return 0;
}
