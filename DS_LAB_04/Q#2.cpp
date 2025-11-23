#include<iostream>
#include <climits>
using namespace std;

void insertionsort(int arr[], int size) {
      for (int i = 1; i < size; i++)
    {
        int pivot = arr[i];
        int j = i-1;

        while (arr[j] > pivot && j >= 0)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = pivot;
    }
}


int main()
{
    int size = 9;
    int arr[9] = { 20, 12, 15, 2, 10, 1, 13, 9, 5};
    // int arr[9] = { 10, 3, 6, -1, 5, 20, 100, 4, 1};
    
    cout << "\nOriginal array: ";
    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] << " ";
    }
    
    insertionsort(arr,size);

    int mid = size/2;
    int maximum = arr[size-1];

    for (int i = size-1; i >= mid; i--)
    {
        arr[i] = arr[i-1];
    }

    arr[mid] = maximum;

    
    cout << "\nAfter sorting the array: ";

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

   return 0;
}