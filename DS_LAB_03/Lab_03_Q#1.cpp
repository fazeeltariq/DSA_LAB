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
    public:
    Node *head;
    Node *tail;

    LinkedList(){
        head = tail = NULL;
    }

    void insertAtHead (int val) {
        Node* newNode = new Node (val);
        if(head == NULL) {
            head = tail = newNode;
            return;
        }
        else {
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

   void insertAtPosition(int value , int pos){
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

    Node *newNode =new Node(value);
    newNode->next= temp->next;
    temp->next = newNode;

    if (newNode->next == NULL) {
        tail = newNode;
    }
}

    void deleteByValue(int val){
        Node *temp = head; 
        Node *prev = NULL;
        int found = 0; 
        while (temp != NULL)
        {
            if(temp->data == val){
                found = 1;
                break;
            }
            prev = temp;
            temp = temp->next;
        }
        if(found == 0){
            cout << "\nValue is not present. ";
            return;
        }

        if(prev == NULL){
            deleteAtHead();
        }
        else if(temp->next == NULL){
            deleteAtTail();
        }
        else {
            prev->next = temp->next;
            delete temp;
        }
    }

    void reverse (Node *temp, Node *prev) {
    if(temp == NULL) {
        head = prev;
        return;
    }
    reverse(temp->next,temp);
    temp->next = prev;
    
    return;
    }
    
    void reverse(){
        Node *cur = head;
        Node *prev = NULL;
        while (cur != NULL)
        {
            Node *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head = prev; 
    }

    ~LinkedList() {
    Node *current = head;
    while (current != NULL) {
        Node *nextNode = current->next;
        delete current;
        current = nextNode;
    }
}
    Node *cur = tail;
    void bubblesort() {
        Node *temp = head;

        while (temp->next != NULL)
        {
            Node *temp2 = head;
            while (temp2->next != NULL)
            {
                if(temp2->data > temp2->next->data)
                swap(temp2->data, temp2->next->data);

                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        
    }

};


int main(){
    int arr[5] = {3, 1, 2, 5, 8};

    cout << "\nArray elements: ";

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    LinkedList list;
    for (int i = 0; i < 5; i++)
    {
        list.insertAtTail(arr[i]);
    }

    cout << "\nNew linked list: \n";
    list.print();

    list.insertAtTail(9);

    cout << "\nInserting value = 11, at position 3: \n";
    list.insertAtPosition(11, 3);
    list.print();
    
    list.insertAtHead(4);

    cout << "\nAfter deleting values 1, 2, 5\n";
    list.deleteByValue(1);
    list.deleteByValue(2);
    list.deleteByValue(5);

    list.print();
    list.reverse();
    list.print();
}