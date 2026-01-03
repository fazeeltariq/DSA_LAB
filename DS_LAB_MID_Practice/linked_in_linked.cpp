#include<bits/stdc++.h>
using namespace std;

class smallNode {
    public:
    smallNode *next;
    string data;
    smallNode(int val) {
        data = val;
        next = nullptr;
    }
};

 class List {
    public:
    smallNode *head;
    smallNode *tail;
    List () {
        head = tail = nullptr;
    }
    void insertHead (int val) {
        smallNode *newNode = new smallNode(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
    }
};

class Node {
    public:
    Node *next;
    List l;
    Node() {
        next = nullptr;
    }
};

class newList {
    public:
    Node *head;
    Node *tail;
    newList () {
        head = tail = NULL;
    }
    int  solveEquations (Node *innerhead) {
        int result = stoi (innerhead->l.head->data);
        innerhead->l.head = innerhead->l.head->next;
        while (innerhead->l.head->next != NULL && innerhead->l.head->next->next != NULL)
        {
            string op = innerhead->l.head->data;
            innerhead->l.head = innerhead->l.head->next;
            int num = stoi (innerhead->l.head->data);
            if(op =="+") result += num; 
            else if(op =="-") result -= num; 
            else if(op =="*") result *= num; 
            else if(op =="/") result /= num; 
            innerhead->l.head = innerhead->l.head->next;
        }
        return result;
}
};
   


int main()
{

   return 0;
}