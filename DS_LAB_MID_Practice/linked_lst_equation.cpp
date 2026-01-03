#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    Node *next;
    Node *prev;
    int data;
    Node (int data) {
        prev = next = NULL;
    }
};
class List {
    public:
    Node *head;
    Node *tail;
    List () {
        head = tail = NULL;
    }
    
};
int main()
{

   return 0;
}