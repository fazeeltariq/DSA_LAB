#include<bits/stdc++.h>
using namespace std;

class Card {
    public:
    int rank;
    char suit;
    Card () {}
    Card (int rank, char suit) {
        this->rank = rank;
        this->suit = suit;
    }
};

class Node {
    public:
    Card card;
    Node  *next;
    Node (Card card) {
        this->card = card;
        next = nullptr;
    }
};
class List {
    public:
    Node *head;
    Node *tail;
    List () {
        head = tail = NULL;
    }
    void push_back (Card c) {
        Node *newcard = new Node(c);
        if (head == NULL) {
            head = tail = newcard;
            return;
        }
        else {
            tail->next = newcard;
            tail = newcard;
        }
    } 
    void pop_front() {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    void playGame (Node *player1, Node *player2) {

    }
};
int main()
{
    srand(time(0));  
    List player1;
    List player2;
   
    char suits[] = {'h', 'd', 'c', 's'};

    for (int i = 0; i < 5; i++)
    {
        int num = (rand() % (14-2+1))+2;
        char suit = suits[rand() % 4];
        player1.push_back(Card(num,suit));

    }
    for (int i = 0; i < 5; i++)
    {
        int num1 = (rand() % (14-2+1))+2;
        char suit = suits[rand() % 4];
        player2.push_back(Card(num1,suit));
    }
    List newplay;
    newplay.playGame (player1.head,player2.head);
    
    
   return 0;
}