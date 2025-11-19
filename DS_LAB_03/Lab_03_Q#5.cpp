#include<iostream>
using namespace std;

template <typename T>
class Node{
    public:
    T data;
    Node *next;

    Node(T val) {
        data = val;
        next = NULL;
    }
};

template <typename T>
class LinkedList {
    public:
    Node<T> *head;
    Node<T> *tail;
    LinkedList(){
        head = tail = NULL;
    }
    Node<T>* reverse(Node<T>* head) {
        Node<T>* prev = NULL;
        Node<T>* curr = head;
        Node<T>* next = NULL;

        while (curr != NULL) {
        next = curr->next;   
        curr->next = prev;  
        prev = curr;    
        curr = next;  
        }
        return prev;
    }
    bool isPalindrome(){
        if (!head || !head->next) return true;
     Node<T> *slow = head;   
     Node<T> *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
            slow = slow->next;
            fast = fast->next->next;
    }
    Node<T> *firstpart = head;
    Node<T> *secondpart = reverse(slow);
    while(secondpart != NULL){
        if(firstpart->data != secondpart->data){
            return false;
        }
        firstpart = firstpart->next;
        secondpart = secondpart->next;
    }
    return true;
    }
     void insertAtHead(T val){    
        Node<T> *newNode = new Node<T>(val);
        if(head == NULL){
            head = tail = newNode;
            return;
        }
        else{
        newNode->next = head;
        head = newNode;
        }
    }
    void print(){
        Node<T> *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " => ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    ~LinkedList() {
    Node<T> *current = head;
    while (current != NULL) {
        Node<T> *nextNode = current->next;
        delete current;
        current = nextNode;
    }
    }
};
int main()
{
    LinkedList<int> list;
    list.insertAtHead(1);
    list.insertAtHead(0);
    list.insertAtHead(2);
    list.insertAtHead(0);
    list.insertAtHead(1);
   
    if(list.isPalindrome()){
        cout << "\nList # 1 is PALIDROME: \n";
    }
    else {
        cout << "\nList # 1 is not PALINDROME: \n";
    }
    list.print();

    LinkedList<char> list2;
    list2.insertAtHead('b');
    list2.insertAtHead('o');
    list2.insertAtHead('r');
    list2.insertAtHead('r');
    list2.insertAtHead('o');
    list2.insertAtHead('w');
    list2.insertAtHead('o');
    list2.insertAtHead('r');
    list2.insertAtHead('r');    
    list2.insertAtHead('o');
    list2.insertAtHead('b');

     if(list2.isPalindrome()){
        cout << "\nList # 2 is PALIDROME: \n";
    }
    else {
        cout << "\nList # 2 is not PALINDROME: \n";
    }

    list2.print();
   return 0;
}
