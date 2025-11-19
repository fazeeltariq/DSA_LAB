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

class LinkedList {
    private:
    Node *head;
    Node *tail;
    public:

    LinkedList(){
        head = tail = NULL;
    }

    void insertAtHead(int val) { 
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

    Node* reverseList(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;

        while (curr != nullptr) {
            next = curr->next;  
            curr->next = prev;  
            prev = curr;        
            curr = next;        
        }
        return prev; 
    }

    void reverseAlternateNodes() {
        if(head == NULL) {
            return ;
        }
        int count = 0;
        Node *originalhead = NULL;
        Node *originallast = NULL;
        Node *extractedhead = NULL;
        Node *extractedlast = NULL;
        Node *temp = head;

       while (temp != NULL) {
        Node *nextNode = temp->next; 
        temp->next = NULL;   

        if (count % 2 == 0){
            if(!originalhead)
                originalhead = originallast = temp;

            else { 
                originallast->next = temp; originallast = temp; 
            }
        }
        else {
            if(!extractedhead)
                extractedhead = extractedlast = temp;

            else { 
                extractedlast->next = temp; extractedlast = temp; 
            }
        }

        temp = nextNode;
        count++;
    }

        extractedhead = reverseList(extractedhead);
        if (originallast) {
        originallast->next = extractedhead;
        }
        head = originalhead;
        Node* t = originallast;
        while (t!=NULL && t->next != NULL) {
            t = t->next;
        }
        tail = t;
        head = originalhead;
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
    LinkedList list;
    list.insertAtTail(10);
    list.insertAtTail(4);
    list.insertAtTail(9);
    list.insertAtTail(1);
    list.insertAtTail(3);
    list.insertAtTail(5);
    list.insertAtTail(9);
    list.insertAtTail(4);
    cout << "\nBefore reversing Alternates nodes: \n";
    list.print();
    list.reverseAlternateNodes();
    cout << "\nAfter reversing Alternates nodes: \n";
    list.print();
    

}