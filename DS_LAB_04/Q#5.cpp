#include<iostream>
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
    int n = 6;
    int arr[6] = {2022, 2023, 2024, 2022, 2023, 2024};
    // int arr[6] = {2023, 2024, 2022, 2020, 2021, 2025};

    cout << "\nBefore sorting the array:\n";
    cout << "[";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] ;
        if (i!=n-1) cout <<", ";
    }
    cout << "]\n";

    insertionsort(arr,n);

    cout << "\nAfter sorting the array:\n";
    cout << "[";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] ;
        if (i!=n-1) cout <<", ";
    }
    cout << "]";
    
    
   return 0;
}