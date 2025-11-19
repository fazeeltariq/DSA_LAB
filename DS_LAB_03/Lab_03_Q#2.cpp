#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

class LinkedList{
    private:
    Node *head;
    Node *tail;
    public:

    LinkedList(){
        head = tail = NULL;
    }

    void insertAtHead(int val){    // push_front
        Node *newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
            return;
        }
        else{
        newNode->next = head;
        head = newNode;
        }
    }

    void insertAtTail(int val){
        Node *newNode = new Node(val);
         if(head == NULL){
            head = tail = newNode;
            return;
        }
        else{
        tail->next = newNode;
        tail = newNode;
        }
    }

    void deleteAtTail(){
        if(head == NULL){
            cout << "\nLinked list in empty: ";
            return;
        }
        else if(head == tail){
            delete head;
            head = tail = NULL;
        }
        else{
            Node *temp = head;
            while (temp->next != tail)
            {
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            temp->next = NULL;
        }
    }

    void deleteAtHead() {
        if( head == NULL) {
            cout << "\nLinked list in empty: ";
            return;
        }
        else if(head == tail){
            delete head;
            head = tail = NULL;
            return;
        }
        else{
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void print(){
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " => ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void moveToEnd(int number){
        while (number--)
        {
            tail->next = head;
            tail = head;
            head = head->next;
            tail->next = NULL;
        }
        tail->next = NULL;
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


int main(){
   int number;
   cout << "\nEnter the no of elements to move.";
   cin >> number;

    LinkedList list;
    list.insertAtTail(1);
    list.insertAtTail(2);
    list.insertAtTail(3);
    list.insertAtTail(4);

    list.print();
    list.moveToEnd(number);
    list.print();
}