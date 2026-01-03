#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int exp;
    int coef;
    Node *next;
    Node(int ex, int coef) {
        exp = ex;
        this->coef = coef;
        next = nullptr;
    }
};


// class List {
//     public:
//     Node *head;
//     Node *tail;
//     List () {
//         head = tail = nullptr;
//     }
//     void insertHead (int exp, int coef) {
//         Node *newNode = new Node(exp,coef);
//         if (head == NULL) {
//             head = newNode;
//             tail = newNode;
//             return;
//         }
//         else {
//             newNode->next = head;
//             head = newNode;
//         }
//     }
// };

Node* addpolynomils (Node *head1, Node *head2) {
    Node *newhead = nullptr;
    Node *newtail = nullptr;
    while (head1 != NULL && head2!=NULL)
    {
        Node *newNode = nullptr;
        if (head1->exp == head2->exp) {
            int sum = head1->coef + head2->coef;
            if (sum != 0) {
                newNode = new Node (head1->exp, head1->coef);
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        
        else if (head1->exp > head2->exp ) {
            newNode = new Node (head1->exp, head1->coef);
            head1 = head1->next;
        }
        else  {
            newNode = new Node (head2->exp, head2->coef);
            head2 = head2->next;
        }

        if (newNode) {
            if (!newhead) {
                newhead = newtail = newNode;
            } else {
                newtail->next = newNode;
                newtail = newNode;
            }
        }
    } 

    while (head1 != NULL)
    {
        Node* newNode = new Node(head1->exp, head1->coef);
        newtail->next = newNode;
        newtail = newNode;
        head1 = head1->next;
    }
    while (head2 != NULL)
    {
        Node* newNode = new Node(head2->exp, head2->coef);
        newtail->next = newNode;
        newtail = newNode;
        head2 = head2->next;
    }
    return newhead;
}

void insertTail(Node*& head, Node*& tail, int c, int e) {
    Node* newNode = new Node(c, e);
    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}
int main()
{
    
    return 0;
}