#include<iostream>
using namespace std;

class Node{ 
    public:
    int data;
    Node *next;
    Node(int value){
        data = value;
        next = NULL;
    }
};

class LinkedList {
    public:
    Node *head;
    Node *tail;

    LinkedList(){
        head = tail = NULL;
    }

     void insertAtHead(int val){    
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
    void evenBeforeOdd() {
    Node *prevodd = NULL;
    Node *preveven = NULL;
    Node *firstOdd = NULL;
    Node *firsteven = NULL;
    Node *temp = head;

    while (temp != NULL){
        if (temp->data % 2 == 0) {
            if (!firsteven) {
                firsteven = temp;
                preveven = temp;
            }
            else {
                preveven->next = temp;
                preveven = temp;
            }
        }
        else {
            if (!firstOdd) { 
                firstOdd = temp;
                prevodd = temp;
            } 
            else {
                prevodd->next = temp;
                prevodd = temp;
            }
        }
        temp = temp->next;
    }

    if (!firsteven || !firstOdd) return;

    preveven->next = firstOdd;
    prevodd->next = NULL;

    head = firsteven;
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
     ~LinkedList() {
    Node *current = head;
    while (current != NULL) {
        Node *nextNode = current->next;
        delete current;
        current = nextNode;
    }
    }

};
int main()
{
    LinkedList ll;
    // Input: 17-15-8-12-10-5-4-1-7-6-NULL
       cout << "\n<------------------------List 1:--------------------------------->\n";
    ll.insertAtTail(17);
    ll.insertAtTail(15);
    ll.insertAtTail(8);
    ll.insertAtTail(12);
    ll.insertAtTail(10);
    ll.insertAtTail(5);
    ll.insertAtTail(4);
    ll.insertAtTail(1);
    ll.insertAtTail(7);
    ll.insertAtTail(6);
    ll.print();
    ll.evenBeforeOdd();
    ll.print();
    
       cout << "\n<------------------------List 2:--------------------------------->\n";
    LinkedList list2;
    list2.insertAtTail(8);
    list2.insertAtTail(10);
    list2.insertAtTail(12);
    list2.print();
    list2.evenBeforeOdd();
    list2.print();


    cout << "\n<------------------------List 3:--------------------------------->\n";
    LinkedList list3;
    list3.insertAtTail(1);
    list3.insertAtTail(3);
    list3.insertAtTail(5);
    list3.insertAtTail(7);
    list3.print();
    list3.evenBeforeOdd();
    list3.print();

   return 0;
}