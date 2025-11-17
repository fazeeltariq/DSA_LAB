#include <bits/stdc++.h>
using namespace std;

int main(){
   int rows;
   cout << "Enter number of rows: ";
   cin >> rows;

   int *noofseats = new int[rows];
   string **seats = new string*[rows];

   cout << "Enter seats in each row:\n";

   for(int i = 0; i < rows; i++){
      cout << "Row " << i+1 << ": ";
      cin >> noofseats[i];
      seats[i]=new string[noofseats[i]];
   }

   cout<<"\nEnter names for seats:\n";

   for(int i = 0; i < rows; i++){
      cout << "\n-- Row " << i+1 <<" --\n";
      for(int j = 0; j < noofseats[i]; j++){

         cout << "Seat " << j+1 <<": ";
         cin >> seats[i][j];
      }
   }

   cout<<"\n--------- Seating Chart --------\n";

   for(int i = 0; i < rows; i++){
      cout << "Row " << i+1 <<": ";

      for(int j = 0; j < noofseats[i]; j++){
         cout << seats[i][j] << " ";
      }
      cout<<"\n";
   }


   for(int i = 0; i < rows; i++) 
   delete[] seats[i];

   delete[] seats;
   delete[] noofseats;

   return 0;
}
