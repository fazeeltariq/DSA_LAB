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
public:
    Node *head;
    Node *tail;

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

    void print() {
        Node *temp = head;
        while (temp != NULL) {
            cout << temp->data << " => ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    void bubblesort() {
        bool swapped = true;
        Node *outer = NULL;
        do {
            swapped = false;
            Node *inner = head;
            while (inner->next != outer)
            {
                if (inner->data > inner->next->data) {
                    swapped = true;
                    int temp = inner->data;
                    inner->data = inner->next->data;
                    inner->next->data = temp;
                }
                inner = inner->next;
            }
            outer = inner;
        } while(swapped);

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
    list.bubblesort();
    cout << "\nAfter sorting:\n";
    list.print();
}
