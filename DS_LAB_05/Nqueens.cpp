#include<bits/stdc++.h>
using namespace std;

int recursiveArraySum(int* arr[], int sizes[], int rows, int i , int j){
   if(i == rows) return 0;

   if(j == sizes[i]) {
      return recursiveArraySum(arr, sizes, rows, i + 1, 0);
   }
   
   return arr[i][j] + recursiveArraySum(arr,sizes,rows,i,j+1);

}

int main()
{

   int **arr = new int*[5];
   int size[5] = {4,3,5,6,2};
   for (int i = 0; i < 5; i++)
   {
      arr[i] = new int[size[i]];
   }
   cout << "\nEnter the values of Jagged Array: "; 

   for (int i = 0; i < 5; i++){
      cout << "\nEnter " << size[i] << " elements for row " << i+1 << ": \n";
      for (int j = 0; j < size[i]; j++){
         cin >> arr[i][j];
      }     
   }
   cout << "\nThe jagged array is: ";
   for (int i = 0; i < 5; i++){
      for (int j = 0; j < size[i]; j++){
         cout << arr[i][j] << " ";
      }     
      cout << "\n";
   }


   int sum = recursiveArraySum(arr,size,5,0,0);
   cout << "\nThe sum of jagged array is : "<< sum;

   for (int i = 0; i < 5; i++) {
      delete[] arr[i];
   }
   delete[] arr;


   return 0;
}