#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next;

    Node(int val) {
        this->data = val;
        next = NULL;
    }
};

class CircularList {
    public:
    Node *head;
    Node *tail;

    CircularList() {
        head = tail = NULL;
    }

    void insertAtTail( int val ) {
        Node *newNode = new Node (val);
        if (head == NULL) {
            head = tail = newNode;
            tail->next = head;
            return ;
        }
        tail->next = newNode;
        tail = newNode;
        newNode->next = head;
    }
    void insertAtHead ( int val ) {
        Node *newNode = new Node (val);

        if (head == NULL) {
            head =  tail = newNode;
            tail->next = head;
            return ;
        }
        newNode->next = head;
        head = newNode;
        tail->next = head; 
    }

    void insertAtposition (int val , int pos) {
        if (pos < 0) {
            cout << "\nInvalid position: ";
            return ;
        }
        if (pos == 0) {
            insertAtHead (val);
            return;
        }
        Node *temp = head;
        int currentIndex = 0;
       
        while ( temp != tail && currentIndex < pos - 1) {
        temp = temp->next;
        currentIndex++;
        }

        if (temp == tail) {
            insertAtTail (val);
            return ;
        }

        Node *newNode = new Node (val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteNode (int pos ) {
        if (head == NULL) {
            cout << "\nList is empty: ";
            return ;
        }
        if(pos == 0) {
            if (head == tail ){
            delete head;
            head = tail = NULL;
            return;
            }
            Node *temp = head;
            head = head->next;
            tail->next = head;
            delete temp;
            return;
        }

        Node *temp = head;
        int count = 0;
        while (temp != tail && count < pos - 1) {
            temp = temp->next;
            count++;
        }
        if (temp->next == head) {
            cout << "\nInvalid position!";
            return;
        }
        Node *toDelete = temp->next;

        if (toDelete == tail) {
            tail = temp;
        }

        temp->next = toDelete->next;
        delete toDelete;
    }

    void print () {
        Node *temp = head;
        do {
        cout << temp->data << " => ";
        temp = temp->next;
        } while (temp != head);
        cout << " (head again): \n";
    }
};

int main()
{
    CircularList cirList;
    cirList.insertAtTail(1);
    cirList.insertAtTail(2);
    cirList.insertAtTail(3);
    cirList.insertAtTail(4);

    cirList.print();
    cirList.insertAtHead(9);
    cirList.insertAtTail(22);
    cirList.print();

    cout << "\nInserting value = 100, at position = 3 \n";
    cirList.insertAtposition (100, 3);
    cirList.print();
    cout << "\nDeleting Node at index 4 :\n";
    cirList.deleteNode(4);
    cirList.print();
   return 0;
}