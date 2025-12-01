#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = prev = NULL;
    }
};

class LinkedList {
private:
    Node *head;
    Node *tail;

public:
    LinkedList() {
        head = tail = NULL;
    }

    void insertAtHead(int val) {
        Node *newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
            return;
        }
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }

    void insertAtTail(int val) {
        Node *newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void deleteAtTail() {
        if (head == NULL) {
            cout << "\nLinked list is empty.";
            return;
        } else if (head == tail) {
            delete head;
            head = tail = NULL;
        } else {
            Node *temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete temp;
        }
    }

    void deleteAtHead() {
        if (head == NULL) {
            cout << "\nLinked list is empty.";
            return;
        } else if (head == tail) {
            delete head;
            head = tail = NULL;
            return;
        } else {
            Node *temp = head;
            head = head->next;
            head->prev = NULL;
            delete temp;
        }
    }

    void print() {
        Node *temp = head;
         cout<<"NULL ";
        while (temp != NULL) {
            cout << "<= "<< temp->data << " =>";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void insertAtPosition(int value, int pos) {
        if (pos < 0) {
            cout << "\nInvalid position.";
            return;
        }
        if (pos == 0) {
            insertAtHead(value);
            return;
        }
        Node *temp = head;
        int currentIndex = 0;
        while (temp != NULL && currentIndex < pos - 1) {
            temp = temp->next;
            currentIndex++;
        }
        if (temp == NULL) {
            cout << "\nPosition out of bounds.";
            return;
        }
        Node *newNode = new Node(value);
        newNode->next = temp->next;
        newNode->prev = temp;

        if(temp->next != NULL) {
            temp->next->prev = newNode;
        }
        else tail = newNode;

        temp->next = newNode;
    }

    void deleteByValue(int val) {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }
        Node *temp = head;
        while (temp != NULL && temp->data != val) {
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Value not found\n";
            return;
        }
        if (temp == head) {
            deleteAtHead();
        } else if (temp == tail) {
            deleteAtTail();
        } else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }
    }

    ~LinkedList() {
        Node *current = head;
        while (current != NULL) {
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main() {
    int arr[5] = {3, 1, 2, 5, 8};
  
    LinkedList list;
    for (int i = 0; i < 5; i++) {
        list.insertAtTail(arr[i]);
    }

    cout << "\nNew linked list: \n";
    list.print();

    cout << "\nInserting value = 11 at position 3: \n";
    list.insertAtPosition(11, 3);
    list.print();

    cout<<"\nRemoved from head: ";
    list.deleteAtHead();
    cout<<"\nRemoved from tail: \n";
    list.deleteAtTail();

    cout<<"\nAfter deletion:\n";
    list.print();
}
