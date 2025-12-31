#include <bits/stdc++.h>
using namespace std;

class Queue {
private:
   int front;
   int rear;
   int capacity;
   int* arr;
public:
   Queue(int size) {
      front=0;
      rear=-1;
      capacity=size;
      arr=new int[size];
   }
   void enqueue(int val) {
   if (rear == capacity - 1) {
      cout << "Queue Overflow! Cannot add more customer " << val << "\n";
      return;
   }
      arr[++rear] = val;
      cout << "Customer " << val << " entered the queue." << "\n";
   }

    void dequeue() {
      if (front > rear) {
         cout << "Queue Underflow! No customers." << "\n";
         return;
      }
      cout << "Customer " << arr[front] << " has been processed." << "\n";
      front++;
    }

   void display() {
      if (front > rear) {
         cout << "No customers present in the queue!" << endl;
         return;
      }
      cout << "Current queue is: ";
      for (int i = front;i <= rear; i++) {

         cout << arr[i] << " ";
      }
      cout << endl;
    }

   ~Queue() {
      delete[] arr;
    }
};

int main() {
   Queue q(7);

   int customers[] = {13, 7, 4, 1, 6, 8, 10};
   for (int i = 0; i < 7; i++) {
      q.enqueue(customers[i]);
   }

   cout << "\nQueue\n";
   q.display();

   cout << "\n Managing Customers: \n";
   q.dequeue();
   q.display();

   q.dequeue();
   q.display();

   q.dequeue();
   q.display();

   return 0;
}
