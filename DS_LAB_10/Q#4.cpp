#include <iostream>
using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int val) {
        key = val;
        left = right = nullptr;
        height = 1;
    }
};

class AVLTree {
private:
    Node* root;

    int height(Node* n) {
        if (n == nullptr)
            return 0;
        return n->height;
    }

    int getBalance(Node* n) {
        if (n == nullptr)
            return 0;
        return height(n->left) - height(n->right);
    }

    Node* rightRotate(Node* y) {
        cout << "Performing Right Rotation on node: " << y->key << endl;
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    Node* leftRotate(Node* x) {
        cout << "Performing Left Rotation on node:: " << x->key << endl;
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    Node* insert(Node* node, int key) {
        if (node == nullptr) {
            cout << "Inserting new node: " << key << endl;
            return new Node(key);
        }

        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else
            return node; 

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = getBalance(node);
        cout << "Node " << node->key << " -> Balance Factor: " << balance << endl;

        if (balance > 1 && key < node->left->key) {
            cout << "Unbalanced at node " << node->key << " Left Left Case\n";
            return rightRotate(node);
        }

        if (balance < -1 && key > node->right->key) {
            cout << "Unbalanced at node " << node->key << " (Right Right Case\n";
            return leftRotate(node);
        }

        if (balance > 1 && key > node->left->key) {
            cout << "Unbalanced at node " << node->key << " Left Right Case\n";
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && key < node->right->key) {
            cout << "Unbalanced at node " << node->key << " (Right Left Case)\n";
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void inorder(Node* root) {
        if (root != nullptr) {
            inorder(root->left);
            cout << root->key << " ";
            inorder(root->right);
        }
    }

    int calculateHeight(Node* root) {
        if (root == nullptr) return 0;
        return 1 + max(calculateHeight(root->left), calculateHeight(root->right));
    }

public:
    AVLTree() {
        root = nullptr;
    }

    void insert(int key) {
        cout << "\n Inserting value: " << key << endl;
        root = insert(root, key);
        cout << "Tree height after insertion of " << key << " is " << calculateHeight(root) << endl;
    }

    void displayInorder() {
        cout << "Inorder Traversal of AVL Tree: ";
        inorder(root);
        cout << endl;
    }

    void showHeight() {
        cout << "Current Height of Tree: " << calculateHeight(root) << endl;
    }
};

int main() {
    AVLTree tree;

    cout << "Inserting (10, 5, 15, 3, 7):" << endl;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);

    cout << "\nInsert 12 and check balancing " << endl;
    tree.insert(12);

    cout << "\nDisplay balance factors and height ===" << endl;
    tree.showHeight();

    tree.displayInorder();

    return 0;
}
