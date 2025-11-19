#include<iostream>
using namespace std;

class Node{
    public:
    string name;
    Node *next;
    Node(string val){
        this->name = val;
        next = NULL;
    }
};

class Flight{
    private:
    Node *head;
    int capacity;
    int booked;
    public:

    Flight(){
        head = NULL;
        capacity = 200;
        booked = 0;
    }

    void cancelReservation (string name) {
        if (head == NULL) {
        cout << "No passengers exist to cancel.\n";
        return;
    }
        if(head->name == name) {
            Node *temp = head;
            head = head->next;
            delete temp;
            cout << "\nSeat has been cancelled of " << name << endl;
            booked--;
            return;
        }

        Node *temp = head;
        while (temp->next != NULL && temp->next->name != name)
        {
            temp = temp->next;
        }

        if(temp->next == NULL) {
            cout << "\nNo reservation found for " << name << endl;
        }
        else {
            Node *todeleted = temp->next;
            temp->next = todeleted->next;
            delete todeleted;
            booked--;
            cout << "\nReservation canceled for " << name << endl;
        }
    }


    void isticketReserved (string name) {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->name == name) {
                cout << "\nSeat with this name is booked: \n";
                return;
            }
            temp = temp->next;
        }
         cout << "\nSeat with this name is not booked: \n";
    }

   void displayPassengers() {
        if (head == NULL) {
            cout << "\nNo one booked yet.\n";
            return;
        }
        cout << "\n========== Passenger List ==========\n";
        Node* temp = head;
        int count = 1;
        while (temp != NULL) {
            cout << count++ << ". " << temp->name << endl;
            temp = temp->next;
        }
        cout << "------------------------------------\n";
        cout << "Total booked: " << booked << " / " << capacity << endl;
        cout << "====================================\n";
    }
    
    void reserveTicket (string name) {
        if(booked >= capacity){
            cout << "\nNo more seats: ";
            return;
        }

        Node *newNode = new Node(name);

        if (head == NULL || name < head->name) {
            newNode->next = head;
            head = newNode;
            booked++;
            cout << "\nTicket has been reserved for " << name << endl;
            return ;
        }
        else{
            Node *temp = head;

            while (temp->next != NULL && temp->next->name < name)
            {
                temp = temp->next;
            }

            newNode->next = temp->next;
            temp->next = newNode; 
            booked++;
            cout << "\nTicket has been reserved for "<< name;
        }
    }

    ~Flight() {
    Node *current = head;
    while (current != NULL) {
        Node *nextNode = current->next;
        delete current;
        current = nextNode;
    }
}
};


int main(){

   Flight f1; 
    
    int choice = 0;

    cout << "\n---------------Airline Ticket Reservation-----------------\n";
   while (choice != 5){

   cout << "\n1. Reserve a ticket: ";
   cout << "\n2. Cancel a ticket: ";
   cout << "\n3. Check reserved ticket: ";
   cout << "\n4. Display Passengers: ";
   cout << "\n5. Exit";
   cout << "\nEnter the choice: ";
   cin >> choice;
   string name;
   switch (choice)
   {
    case 1:
        cout << "\nEnter the name: ";
        cin >> name;
        f1.reserveTicket(name);
    break;

    case 2:
        cout << "\nEnter the name: ";
        cin >> name;
        f1.cancelReservation(name);
    break;

    case 3:
        cout << "\nEnter the name: ";
        cin >> name;
        f1.isticketReserved(name);
    break;

    case 4:
        f1.displayPassengers();
    break;

    case 5:
        return 0;
    default:
        cout << "\nInvalid command: ";
    break;
   }
}
}