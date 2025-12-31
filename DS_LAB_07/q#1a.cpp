#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node (int val) {
        data = val;
        next = NULL;
    }
};

class TodoList {
private:
    Node* top;
public:
    TodoList() {
        top = nullptr;
    }
    void push(int value) {
        Node* newNode = new Node(value);
        if(top == NULL) {
            top = newNode;
            return;
        }
        cout << "\nTask " << value << " added to TodoList: ";
        newNode->next = top;
        top = newNode;
    }
    void pop() {
        if (isEmpty()) {
            cout << "TodoList is empty! No item \n";
            return ;
        }
        cout << "\nTask " << top->data << " removed from TodoList: ";
        Node* temp = top;
        top = top->next;
        temp->next = NULL;
        delete temp;
        temp = NULL;
    }

    bool isEmpty() {
        return top == NULL;
    }

    int top_element() {
        if (isEmpty()) {
            cout << "TodoList is empty\n";
            return -1;
        }
        return top->data;
    }

    void display() {
        if (isEmpty()) {
            cout<<"TodoList is empty\n";
            return;
        }
        Node* temp = top;
        cout << "TodoList elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main ()
{
    TodoList list;

    // add new tasks
    list.push(101);
    list.push(102);
    list.push(103);
    list.push(104);

    cout << endl;
    list.display();

    // topmost task is:
    cout << "The top element is: " << list.top_element() << endl;

    // poping the tasks:
    list.pop();
    list.pop();
    cout << endl;
    list.display();
}
