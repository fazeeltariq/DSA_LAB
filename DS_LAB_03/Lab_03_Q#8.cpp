#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node *prev;
    Node(int data){
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

class DoublyList{
    public:
    Node *head;
    Node *tail;

    DoublyList(){
        head = tail = NULL;
    }

    void push_front(int val){
        Node *newNode = new Node(val);
        if(head == NULL){
            head  = tail = newNode;
            return;
        }
        else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void push_back(int val){
        Node *newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
            return;
        }
        else{
           newNode->prev = tail; 
           tail->next = newNode;
           tail = newNode;
        }
    }

    void pop_front(){
        if (head == NULL){
            cout << "\nList in empty: ";
            return;
        }
        Node *temp = head;
        
        if(head == tail){
            head = tail = NULL;
        }
        else{
            head = head->next;
            head->prev = NULL;
        }
        delete temp;
    }

    void pop_back() {
    if (head == NULL) {
        cout << "\nList is empty.";
        return;
    }
    Node* temp = tail;  

    if (head == tail) {  
        head = tail = NULL;
    } else {
        tail = tail->prev;  
        tail->next = NULL;  
    }
    delete temp; 
    }


    void print(){
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " <==> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
    void mergeList(DoublyList &L, DoublyList &K) {
        if(K.head == NULL) {
            return ;
        }
        if (L.head == NULL) {
            L.head = K.head;
            L.tail = K.tail;
            K.head = K.tail = NULL;
            return;
        }

        L.tail->next = K.head;
        K.head->prev = L.tail;
        L.tail = K.tail;

        K.head = K.tail = NULL;

    }

};


int main()
{
    DoublyList L;
    L.push_back(1);
    L.push_back(2);
    L.push_back(3);
    cout << "\nList-L \n";
    L.print();

    DoublyList W;
    W.push_back(4);
    W.push_back(5);
    W.push_back(6);
    cout << "\nList-W \n";
    L.print();
    L.mergeList(L,W);

    cout << "\nAfter merging both the lists: ";
    L.print();
    return 0;
}