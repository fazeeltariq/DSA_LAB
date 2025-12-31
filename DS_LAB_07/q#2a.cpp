#include <iostream>
using namespace std;

class Node {
    public:
    string URL;
    Node* next;
    Node (string val) {
        URL = val;
        next = NULL;
    }
};

class Stack {
private:
    Node* top;
public:
    Stack() {
        top = nullptr;
    }
    void push(string value) {
        Node* newNode = new Node(value);
        if(top == NULL) {
            top = newNode;
            return;
        }
        cout << "\nWebiste: " << value << " added to Stack: ";
        newNode->next = top;
        top = newNode;
    }
    void pop() {
        if (isEmpty()) {
            cout << "Stack is underFlow \n";
            return ;
        }
        cout << "\nWebsite " << top->URL << " removed from Stack: ";
        Node* temp = top;
        top = top->next;
        temp->next = NULL;
        delete temp;
        temp = NULL;
    }

    bool isEmpty() {
        return top == NULL;
    }

    string top_element() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return " ";
        }
        return top->URL;
    }

    void display() {
        if (isEmpty()) {
            cout<<"Stack is empty\n";
            return;
        }
        Node* temp = top;
        cout << "Stack elements: ";
        while (temp != nullptr) {
            cout << temp->URL << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main ()
{
    Stack browserHistory;

    // adding items to the linked list head
    browserHistory.push("Google");
    browserHistory.push("Facebook");
    browserHistory.push("Twitter");
    browserHistory.push("LinkedIn");
    browserHistory.push("Instagram");
    cout <<  endl;
    browserHistory.display();

    // going back two steps:
    cout << "\nClick back twice:\n";
    browserHistory.pop();
    browserHistory.pop();

    cout << "\nCurrent page: "<<browserHistory.top_element() << endl;
    cout << endl;
    browserHistory.display();
}
