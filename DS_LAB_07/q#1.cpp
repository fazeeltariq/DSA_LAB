#include <iostream>
using namespace std;

class Node {
    public:
    char data;
    Node* next;
    Node (int val) {
        data = val;
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
    void push(char value) {
        Node* newNode = new Node(value);
        if(top == NULL) {
            top = newNode;
            return;
        }
        newNode->next = top;
        top = newNode;
    }
    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow! No element: \n";
            return ;
        }
        Node* temp = top;
        top = top->next;
        temp->next = NULL;
        delete temp;
        temp = NULL;
    }

    bool isEmpty() {
        return top == NULL;
    }

    char top_element() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return top->data;
    }
    void display() {
        if (isEmpty()) {
            cout<<"Stack is empty\n";
            return;
        }
        Node* temp = top;
        cout << "Stack elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main() {
    string data = "BORROWROB";
    string result;
    Stack s;
    for (int i = 0; i < data.size(); i++)
    {
        s.push(data[i]);
    }
    int i = 0;
    while (!s.isEmpty())
    {
        if (s.top_element() != data[i]) {
            cout << data << " is not a Palindrome: ";
            return 0;
        }   
        s.pop();
        i++;
    }
    cout << data << " is a Palindrome: ";

    return 0;
}
