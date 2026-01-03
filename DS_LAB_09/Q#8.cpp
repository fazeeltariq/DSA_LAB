#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    Node *left;
    Node *right;
    int val;
    Node (int data) {
        left = right = NULL;
        val = data;
    }
};

class BST {
private:
    Node *root;
public:
    int count = 0;
    BST () {
        root = NULL;
    }
    
    Node* insert (Node* root, int val) {
        if (root == NULL) {
            return new Node (val);
        }

        if (root->val > val) {
            root->left = insert (root->left, val);
        }
        else if(root->val < val) {
            root->right = insert (root->right, val);
        }
        return root;
    }

    void insert (int val) {
        root = insert (root, val);
    }

    Node *search (Node *root, int val) {
        if (root == NULL || root->val == val) {
            return root;
        }
        if (root->val > val) {
             return search (root->left, val);
        }
        else if (root->val < val) {
            return search (root->right, val);
        }
        return NULL;
    }

    bool search (int val) {
        if (search (root, val) == NULL) {
            cout << "\nValue not present: ";
            return false;
        }
        else  {
            return true;
        }
    }

    Node *findsuccessor (Node *root) {
        Node *temp = root;
        while (temp != NULL && temp->left != NULL)
        {
            temp = temp->left;
        }
        return temp;
    }

    Node *deleteNode (Node *root, int val) {
        if(root == NULL) {
            return root;
        }
        if (root->val > val) {
            root->left = deleteNode (root->left, val);
        }
        else if (root->val <  val) {
            root->right = deleteNode (root->right, val);
        }
        else {
            if (root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            }
            else if (root->left == NULL) {
                Node *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL) {
                Node *temp = root->left;
                delete root;
                return temp;
            }
            else {
                Node *successor = findsuccessor (root->right);
                root->val = successor->val;
                root->right = deleteNode (root->right, successor->val);
            }

        }
        return root;
    }
    void deleteNode (int val) {
        root = deleteNode (root,val);
    }

    void inordertraversal (Node *root) {
        if (root == NULL) return;

        inordertraversal (root->left);
        cout << root->val << " ";
        inordertraversal (root->right);
    }

    void inorder () {
        inordertraversal (root);
    }

    void countTreesinGivenRange(Node *root, int a, int b) {
        if (root == NULL) return;

        if (root->val >= a && root->val <= b) {
            count++;
        }

        countTreesinGivenRange(root->left, a, b);
        countTreesinGivenRange(root->right, a, b);
    }

    int countInGivenRange (int a, int b) {
        count = 0; // reset before counting
        countTreesinGivenRange (root,a,b);
        return count;
    }
};

int main() {
    BST binarytree;
    binarytree.insert(5);
    binarytree.insert(4);
    binarytree.insert(6);
    binarytree.insert(3);
    binarytree.insert(7);

    cout << "\nInorder traversal:\n";
    binarytree.inorder();

    int a = 0, b = 6;
    int total = binarytree.countInGivenRange(a,b);
    cout << "\n\nTotal nodes in given range [" << a << ", " << b << "] are: " << total << endl;
}
