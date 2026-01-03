#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to check if already visited
bool isVisited(bool visited[], int index) {
    return visited[index];
}

// BFS loop detection
bool detectLoop(Node* root) {
    if (root == NULL) return false;

    bool visited[100] = {false};
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        // Check if visited before → LOOP
        if (isVisited(visited, curr->data)) {
            return true;
        }
        visited[curr->data] = true;

        if (curr->left)
            q.push(curr->left);

        if (curr->right)
            q.push(curr->right);
    }

    return false;
}

int main() {

    // Creating a simple tree (manual)
    Node* a = new Node{1, NULL, NULL};
    Node* b = new Node{2, NULL, NULL};
    Node* c = new Node{3, NULL, NULL};

    a->left = b;
    a->right = c;

    c->right = a;  // makes a cycle

    if (detectLoop(a))
        cout << "\nLoop detected in tree!\n" << endl;
    else
        cout << "No loop found." << endl;
    
    return 0;
}