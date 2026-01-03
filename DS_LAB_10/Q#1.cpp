#include <iostream>
using namespace std;

struct Node{
   int data;
   Node *left;
   Node *right;
   int height;
   Node(int val)
   {
      data = val;
      left = right = NULL;
      height = 1;
   }
};

int get_height(Node *node)
{
   if (node == NULL)
      return 0;
   return node->height;
}

int get_balance(Node *node)
{
   if (node == NULL)
      return 0;
   return get_height(node->left) - get_height(node->right);
}

void update_height(Node *node)
{
   int l_h = get_height(node->left);
   int r_h = get_height(node->right);

   node->height = 1 + max(l_h, r_h);
}

Node *rotate_right(Node *y){
   Node *x = y->left;
   Node *t1 = x->right;

   x->right = y;
   y->left = t1;
   update_height(y);
   update_height(x);
   return x;
}

Node *rotate_left(Node *x){
   Node *y = x->right;
   Node *T2 = y->left;
   y->left = x;
   x->right = T2;
   update_height(x);
   update_height(y);

   return y;
}

Node *createBST_A() {
   Node *root = new Node(10);
   root->left = new Node(6);
   root->left->left = new Node(4);
   root->left->right = new Node(8);
   return root;
}

Node *createBST_B() {
   Node *root = new Node(10);
   root->right = new Node(16);
   root->right->left = new Node(12);
   root->right->right = new Node(18);
   return root;
}

Node *convertToAVL(Node *node) {
   if (node == NULL)
      return NULL;

   node->left=convertToAVL(node->left);
   node->right=convertToAVL(node->right);

   node->height = 1 + max(get_height(node->left), get_height(node->right));

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

void inorder(Node *root)
{
   if (!root)
      return;

   inorder(root->left);
   cout << root->data << " ";
   inorder(root->right);
}

int main()
{
   Node *bstA = createBST_A();
   Node *bstB = createBST_B();

   cout << "Original BST A : ";
   inorder(bstA);

   bstA = convertToAVL(bstA);
   cout << "\nConverted AVL A : ";
   inorder(bstA);

   cout << "\n\nOriginal BST B  ";
   inorder(bstB);

   bstB = convertToAVL(bstB);
   cout << "\nConverted AVL B  ";
   inorder(bstB);

   cout << endl;
   return 0;
}
