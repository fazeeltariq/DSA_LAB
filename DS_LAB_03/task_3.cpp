#include<bits/stdc++.h>
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


int main()
{
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
   return 0;
}