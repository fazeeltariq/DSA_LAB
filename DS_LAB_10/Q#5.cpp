#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* createBST() {
   
    Node* root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);
    root->right->left = new Node(25);
    root->right->right = new Node(35);
    return root;

}


void inordertraversal(Node* root) {
    if (!root) return ;

    inordertraversal(root->left);
    cout << root->data << " ";
    inordertraversal(root->right);
}


static int count = 0;

int inorder(Node* root, int k) {
    if (!root) return -1;

    int left = inorder(root->left, k);
    if (left != -1) return left;

    count++;
    if (count == k)
        return root->data;

    return inorder(root->right, k);
}

static int counti = 0;

int reverseInorder(Node* root, int k) {
    if (!root) return -1;

    int right = reverseInorder(root->right, k);
    if (right != -1) return right;

    counti++;
    if (counti == k)
        return root->data;

    return reverseInorder(root->left, k);
}

int main() {
    Node* root = createBST();

    cout <<"\nTree is: \n";
    inordertraversal(root);
    int k = 3;

    int kthsmallest = inorder(root,k);

    cout << "\nThe k-th smallest element is: " << kthsmallest;
    cout << endl;


    k = 2;
    cout << "Reverse Inorder Traversal of BST: ";
    int kthlargest = reverseInorder(root,k);

    cout << "\nThe k-th largest element is: " << kthlargest;
    cout << endl;


    return 0;
}
