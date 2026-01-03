#include<bits/stdc++.h>
using namespace std;

class Student {
public:
    int rollno;
    Student() {}

    Student(int r) {
        rollno = r;
    }
};

class Node {
public:
    Student data;
    Node* left;
    Node* right;
    int height;  

    Node(Student val) {
        data = val;
        left = right = NULL;
        height = 1;
    }
};

class AVLTree {
private:
    Node *root;
public:
   
    AVLTree() {
        root = NULL;
    }
    int get_height(Node* node) {
        if (node == NULL)
            return 0;
        return node->height;
    }
    int get_balance(Node *node) {
        if (node == NULL) return 0;
        return get_height(node->left) - get_height(node->right);
    }

    void update_height(Node *node) {
        int l_h = get_height(node->left);
        int r_h = get_height(node->right);
        node->height = 1 + max(l_h, r_h);
    }

    Node *rotate_right(Node *y) {
        Node *x = y->left;
        Node *t1 = x->right;

        x->right = y;
        y->left = t1;
        update_height(y);
        update_height(x);
        return x;
    }

    Node* rotate_left(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;
        y->left = x;
        x->right = T2;

        update_height(x);
        update_height(y);
        return y;
    }

    Node* balance_node(Node* node) {
        int balance = get_balance(node);
        if (balance > 1 && get_balance(node->left) >= 0)
            return rotate_right(node);

        if (balance > 1 && get_balance(node->left) < 0) {
            node->left = rotate_left(node->left);
            return rotate_right(node);
        }

        if (balance < -1 && get_balance(node->right) <= 0)
            return rotate_left(node);

        if (balance < -1 && get_balance(node->right) > 0) {
            node->right = rotate_right(node->right);
            return rotate_left(node);
        }

        return node;
    }

    Node* insert(Node* root, Student val) {
        if (root == NULL) {
            return new Node(val);
        }
        if (root->data.rollno > val.rollno) {
            root->left = insert(root->left, val);
        }
        else if (root->data.rollno < val.rollno) {
            root->right = insert(root->right, val);
        }
        update_height(root);
        return balance_node(root);
    }

    void insert(Student s) {
        root = insert(root, s);
    }
    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data.rollno << " ";
        inorder(node->right);
    }
    void display() {
        inorder(root);
    }
    int get_tree_height() {
        return get_height(root);
    }
};

int main()
{
    AVLTree tree;
    tree.insert(Student(10));
    tree.insert(Student(20));
    tree.insert(Student(30));
    tree.insert(Student(40));
    tree.insert(Student(50));

    cout << "AVL Tree before inseting 15: ";
    tree.display();

    tree.insert(Student(15));

    cout << "\nAVL Tree after inserting 15: ";
    tree.display();
    cout << "\nHeight of AVL tree after insertion:: " << tree.get_tree_height() << endl;

    return 0;
}
