#include <iostream>
using namespace std;

class Message {
public:
    int time;
    Message() {}
    Message(int t) {
        time = t;
    }
};
class Queue {
private:
    int front;
    int rear;
    int capacity;
    Message* arr;

public:
    Queue(int size) {
        front = 0;
        rear = -1;
        capacity = size;
        arr = new Message[size];
    }
    void enqueue(Message val) {
        if (rear==capacity-1) {
            cout<<"Queue Overflow! Cannot add more messages.\n";
            return;
        }
        arr[++rear]=val;
        cout<<"Message " << val.time<<" added to queue.\n";
    }
    void dequeue() {
        if (front>rear) {

            cout <<"Queue Underflow! No messages to process.\n";
            return;
        }

        cout<< "Message " <<arr[front].time<<" processed successfully.\n";
        front++;
    }
    void display(){
        if (front>rear) {
            cout<<"No messages currently in the queue.\n";
            return;
        }
        cout<<"Current queue: ";
        for(int i = front; i <= rear; i++) {
            cout<<arr[i].time<<" ";
        }
        cout<<endl;
    }
    ~Queue(){
        delete[] arr;
    }
};

int main() {
    cout << "=== Messaging Queue System ===\n";

    Queue q(5);

    // adding messages to the queue
    q.enqueue(Message(3));
    q.enqueue(Message(5));
    q.enqueue(Message(8));

    q.display();
    // prcoess first message
    q.dequeue();

    q.display();

    // adding more to the queue
    q.enqueue(Message(10));
    q.enqueue(Message(12));

    q.display();
    // Process remaining messages
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();

    return 0;
}
