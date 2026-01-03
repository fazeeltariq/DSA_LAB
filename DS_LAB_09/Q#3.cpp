#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


class Student {
public:
    int score;
    int rollno;
    string name;

    Student () {}
    Student (string n, int s, int r) {
        name = n;
        score = s;
        rollno = r;
    }
    void display () {
        cout << "\nName: " << name << " | Roll No: " << rollno << " | Score: " << score;
    }
};

class Node {
public:
    Node *left;
    Node *right;
    Student student;
    Node (Student data) {
        left = right = NULL;
        student = data;
    }
};

class BST {
private:
    Node *root;
public:
    
    BST () {
        root = NULL;
    }
    
    Node* insert (Node* root, Student student) {
        if (root == NULL) {
            return new Node (student);
        }

        if (root->student.name > student.name) {
            root->left = insert (root->left, student);
        }
        else if(root->student.name > student.name) {
            root->right = insert (root->right, student);
        }
        return root;
    }

    void insert (Student val) {
        root = insert (root, val);
    }

    Node *search (Node *root, Student val) {
        if (root == NULL || root->student.name == val.name) {
            return root;
        }
        if (root->student.name > val.name) {
             return search (root->left, val);
        }
        else if (root->student.name < val.name) {
            return search (root->right, val);
        }
        return NULL;
    }

    bool search (Student val) {
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

    Node *deleteNode (Node *root, Student val) {
        if(root == NULL) {
            return root;
        }
        if (root->student.name > val.name) {
            root->left = deleteNode (root->left, val);
        }
        else if (root->student.name <  val.name) {
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
                root->student.name = successor->student.name;
                root->right = deleteNode (root->right, successor->student);
            }

        }
        return root;
    }
    void deleteNode (Student val) {
        root = deleteNode (root,val);

    }

    Node* getStudentBelow10(Node* root) {
    if (root == NULL)
        return NULL;

    if (root->student.score < 10)
        return root;

    Node* leftResult = getStudentBelow10(root->left);
    if (leftResult != NULL)
        return leftResult;

    return getStudentBelow10(root->right);
}


    void deleteStudentsbelow10 () {
        while (getStudentBelow10 (root) != NULL)
        {
            Node *temp = getStudentBelow10 (root);
            deleteNode (temp->student);
        }
        cout << "\nAll students with score below 10 deleted: ";
    }

    void preordertraversal (Node *root) {
        if (root == NULL) return;

       root->student.display();
        cout << "\n";
        preordertraversal (root->left);
        preordertraversal (root->right);
    }

    void inordertraversal (Node *root) {
        if (root == NULL) return;

        inordertraversal (root->left);
         root->student.display();
        cout << "\n";
        inordertraversal (root->right);
    }

    void postordertraversal (Node *root) {
        if (root == NULL) return;

        postordertraversal (root->left);
        postordertraversal (root->right);
        root->student.display();
        cout << "\n";
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
 
};
int main()
{
    srand(time(0));
    BST binarytree;

    Student students[10] = {
        {"Ali", 12, 101},
        {"Sara", 8, 102},
        {"Hassan", 15, 103},
        {"Ayesha", 22, 104},
        {"Bilal", 9, 105},
        {"Fazeel", 19, 106},
        {"Noor", 30, 107},
        {"Omer", 4, 108},
        {"Fatima", 18, 109},
        {"Zain", 25, 110}
    };

    cout << "\nInserting 7 random students into BST.\n";
    bool used[10] = {false};
    int count = 0;

    while (count < 7) {
        int idx = rand() % 10;
        if (!used[idx]) {
            binarytree.insert(students[idx]);
            used[idx] = true;
            count++;
        }
    }

    cout << "\nPreorder Traversal: ";
    binarytree.preoder();

   
    binarytree.deleteStudentsbelow10();

    cout << "\nAfter deleting students with score below 10:\n";
    cout << "Inorder Traversal: ";
    binarytree.inorder();


    Student target("Fazeel", 0, 0);
    cout << "\n\nSearching for student 'Fazeel': ";
    binarytree.search(target);

    cout << "\n";
    return 0;
    
    
}
