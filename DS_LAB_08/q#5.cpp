#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() {
        head = tail = NULL;
    }
    void insert(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;    
    }
    void display() {
        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

void swap(Node* n1, Node* n2) {
    int temp = n1->data;
    n1->data = n2->data;
    n2->data = temp;
}

Node* partition(Node* st, Node* end) {
    int pivot = end->data;
    Node* placeindex = st;
    Node* temp = st;

    while (temp != end) {
        if (temp->data < pivot) {
            swap(temp, placeindex);
            placeindex = placeindex->next;
        }
        temp = temp->next;
    }
    swap(placeindex, end);
    return placeindex;
}

void quickSort(Node* st, Node* end) {
    if (st == NULL || st== end || end == NULL) {
        return;
    }

    Node* pivotindex = partition(st, end);

    Node* temp = st;
    while (temp != NULL && temp->next != pivotindex) {
        temp = temp->next;
    }

    if (temp != NULL)
        quickSort(st, temp);

    if (pivotindex != NULL && pivotindex->next != NULL)
        quickSort(pivotindex->next, end);
}

int main() {
    LinkedList list;

    list.insert(1);
    list.insert(2);
    list.insert(5);
    list.insert(0);
    list.insert(52);
    list.insert(33);
    list.insert(15);

    cout << "Original Linked List: ";
    list.display();

    quickSort(list.head, list.tail);

    cout << "Sorted Linked List: ";
    list.display();

    return 0;
}
