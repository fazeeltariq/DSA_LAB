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
    bool search(int val){
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == val) return true;
            temp = temp->next;
        }
        return false;
    }
     void deleteByValue(int val){
        if(!search(val)){
            cout << "\nKey does not exist: ";
            return;
        } 
        while (head != NULL && head->data == val)
        {
            Node *temp2 = head;
            head = head->next;
            delete temp2;
        } 
        Node *temp = head;
        Node *prev = NULL;
        while (temp != NULL)
        {
            if (temp->data == val) {
                Node *temp2 = temp;
                prev->next = temp->next;
                temp = temp->next;
                delete temp2;
            }
            else {
                prev = temp;
                temp = temp->next;
            }
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
};
int main()
{
   LinkedList list;
   list.insertAtTail(1);
   list.insertAtTail(2);
   list.insertAtTail(3);
   list.insertAtTail(3);
   list.insertAtTail(3);
   list.insertAtTail(4);
   cout << "\nBefore Deletion: \n";
   list.print();
   list.deleteByValue(3);
   cout << "\nAfter deletion: \n";
   list.print();
   return 0;
}