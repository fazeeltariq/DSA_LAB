#include <iostream>
#include <queue>
using namespace std;

class Product {
public:
    int productID;
    int quantity;

    Product () {}
    Product (int id, int qty) {
        productID = id;
        quantity = qty;
    }
    void display () {
     cout << "Product ID: " << productID << " | Quantity: " << quantity << endl;
    }
};

class Node {
public:
    Node *left;
    Node *right;
    Product product;

    Node (Product p) {
        product = p;
        left = right = NULL;
    }
};

class BST {
private:
    Node *root;
public:
    
    BST () {
        root = NULL;
    }
    
    Node* insert (Node* root, Product p) {
        if (root == NULL) {
            return new Node (p);
        }

        if (root->product.productID > p.productID) {
            root->left = insert (root->left, p);
        }
        else if(root->product.productID < p.productID) {
            root->right = insert (root->right, p);
        }
        return root;
    }

    void insert (Product p) {
        root = insert (root, p);
    }

    Node *search (Node *root, Product p) {
        if (root == NULL || root->product.productID == p.productID) {
            return root;
        }
        if (root->product.productID > p.productID) {
             return search (root->left, p);
        }
        else if (root->product.productID < p.productID) {
            return search (root->right, p);
        }
        return NULL;
    }

    bool search (Product p) {
        Node* res = search (root, p);
        if (res == NULL) {
            cout << "\nProduct not found.\n";
            return false;
        }
        else  {
            cout << "\nProduct found — ID: " << root->product.productID << ", Quantity: " << root->product.quantity<< endl;
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

    Node *deleteNode (Node *root, int id) {
        if(root == NULL) {
            return root;
        }
        if (root->product.productID > id) {
            root->left = deleteNode (root->left, id);
        }
        else if (root->product.productID <  id) {
            root->right = deleteNode (root->right, id);
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
                root->product.productID = successor->product.productID;
                root->product.productID = successor->product.productID;
                root->right = deleteNode (root->right, root->product.productID);
            }

        }
        return root;
    }
    void deleteNode (int id) {
        root = deleteNode (root,id);
    }

    void preordertraversal (Node *root) {
        if (root == NULL) return;

        root->product.display();
        preordertraversal (root->left);
        preordertraversal (root->right);
    }

    void inordertraversal (Node *root) {
        if (root == NULL) return;

        inordertraversal (root->left);
        root->product.display();
        inordertraversal (root->right);
    }

    void postordertraversal (Node *root) {
        if (root == NULL) return;

        postordertraversal (root->left);
        postordertraversal (root->right);
        root->product.display();
    }
    
    void preoder () {
        preordertraversal (root);
    }

    void postorder () {
        postordertraversal (root);
    }

    void inorder () {
        inordertraversal (root);
    }


    void updateQuantity (Product p) {
        Node *found = search(root,p);
        if (found == NULL) {
            cout << "\nProduct not found.\n";
        }
        else {
            found->product.quantity = p.quantity;
            cout << "\nQuantity updated successfully.\n";
        }
    }

    Node* MaxQuantity(Node* root, Node* &maxNode) {
        if (root == NULL) return maxNode;
        if (maxNode == NULL || root->product.quantity > maxNode->product.quantity) {
            maxNode = root;
        }
        MaxQuantity(root->left, maxNode);
        MaxQuantity(root->right, maxNode);
        return maxNode;
    }

    void ProdpctWithHighestQuantity() {
        Node* maxi = NULL;
        maxi = MaxQuantity(root, maxi);
        if (maxi != NULL) {
            cout << "\nProduct with highest quantity:\n";
            maxi->product.display();
        }
        else {
            cout << "\nInventory is empty.\n";
        }
    }
};
int main()
{
    BST inventory;
    inventory.insert(Product(101, 30));
    inventory.insert(Product(102, 15));
    inventory.insert(Product(103, 45));
    inventory.insert(Product(104, 20));

    cout << "\nProducts Inventory :\n";
    inventory.inorder();

    cout << "\nSearch for product 103\n";
    inventory.search(Product(103, 0));

    cout << "\nUpdating quantity of product 104 to 60:\n";
    inventory.updateQuantity(Product(104, 60));

    cout << "\nAfter updation Inventory: \n";
    inventory.inorder();

    cout << "\nProduct with hightest Quantity: ";
    inventory.ProdpctWithHighestQuantity();

}
