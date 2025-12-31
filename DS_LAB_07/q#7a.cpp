#include <iostream>
using namespace std;

class Library {
public:
    string patron;
    int books;
    Library() {}

    Library(string name, int n) {
        patron = name;
        books = n;
    }

    void showInfo() {
        cout << patron << " (" << books << " books)";
    }
};
class Node {
public:
    Library data;
    Node* next;

    Node(Library val) {
        data = val;
        next = NULL;
    }
};

class LibraryQueue {
private:
    Node* front;
    Node* rear;

public:
    LibraryQueue() {
        front = rear = NULL;
    }

    void enqueue(Library val) {
        Node* newNode = new Node(val);
        if (rear == NULL) {
            front = rear = newNode;
            return;
        } 
        else {
            rear->next = newNode;
            rear = newNode;
        }
        cout<<"Patron "<<val.patron<<" added to the queue with " << val.books << " book\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "No patrons in queue. All transactions completed.\n";
            return;
        }
        cout << "Patron # ";
        front->data.showInfo();
        cout << " has completed transation.\n";

        Node* temp = front;
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }
        delete temp;
    }

    bool isEmpty() {
        return front == NULL;
    }

    void display() {
        if (isEmpty()) {
            cout << "No patrons are there waiting in the queue.\n";
            return;
        }
        cout << "\nCurrent patrons are waiting:\n";
        Node* temp = front;
        while (temp != NULL) {
            cout << " - ";
            temp->data.showInfo();
            cout << endl;
            temp = temp->next;
        }
        cout << endl;
    }
};
int main() {
   
    cout << "\n--Library Management System:--\n";
    LibraryQueue libraryQueue;

    libraryQueue.enqueue(Library("Aliza", 3));
    libraryQueue.enqueue(Library("Sahil", 2));
    libraryQueue.enqueue(Library("Fazeel", 4));

    libraryQueue.display();

    libraryQueue.dequeue();
    libraryQueue.display();

    libraryQueue.dequeue();
    libraryQueue.display();

    libraryQueue.enqueue(Library("Aiman", 1));
    libraryQueue.display();

    libraryQueue.dequeue();
    libraryQueue.dequeue();
    return 0;
}
