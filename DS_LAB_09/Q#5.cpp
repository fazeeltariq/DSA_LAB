#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class BinaryTree {
public:
    Node* root;
    BinaryTree() {
        root = NULL;
    }
};



bool isBST(Node* root, int minVal = INT_MIN, int maxVal = INT_MAX) {
    if (root == NULL)
        return true;

    if (root->data <= minVal || root->data >= maxVal)
        return false;

    return isBST(root->left, minVal, root->data) && isBST(root->right, root->data, maxVal);
}


int main() {
    BinaryTree tree;


    tree.root = new Node(10);
    tree.root->left = new Node(5);
    tree.root->right = new Node(20);
    tree.root->right->left = new Node(25);
    tree.root->right->right = new Node(30);

    cout << "BST created successfully!" << endl;
    
    if (isBST (tree.root)) {
        cout << "\nTree is binary Tree: ";
    }    
    else {
        cout << "\ntree is not Binary Tree: ";
    }

    return 0;
}
