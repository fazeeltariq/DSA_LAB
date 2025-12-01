#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

 void insertNodes (Node *head1, Node *&head2) {
        if(head1 == NULL || head2 == NULL) return;
        
        Node *temp1 = head1;
        Node *temp2 = head2;
        while (temp1 != NULL && temp2 != NULL) 
        {
            Node *next1 = temp1->next;
            Node *next2 = temp2->next;

            temp1->next = temp2;
            temp2->next = next1;
            
            temp1 = next1;
            temp2 = next2;
        }
        head2 = temp2;
    }

     void print(Node *head) {
        Node *temp = head;
        while (temp != NULL) {
            cout << temp->data << " => ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
int main() {
    Node *head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    cout<<"\nList # 1: \n";
    print(head1);
    Node *head2 = new Node(4);
    head2->next = new Node(5);
    head2->next->next = new Node(6);
    head2->next->next->next = new Node(7);
    head2->next->next->next->next = new Node(8);
    cout<<"\nList # 2: \n";
    print(head2);
    cout << "\nAfter merging linked lists: \n";
   insertNodes(head1,head2);
   cout<<"List 1: ";
   print(head1);
    cout<<"List 2: ";
   print(head2);
}
