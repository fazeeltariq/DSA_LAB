#include<iostream>
using namespace std;

bool containsDuplicates (int arr[], int size) {
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
    for (int i = 0; i < size-1; i++)
    {
        if (arr[i] == arr[i+1]) {
            return true;
        }
    }
    return false;
}

int main()
{
    int n = 10;
    int arr[10];

    cout << "\nEnter the elements of the array: \n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    if(containsDuplicates(arr,n)) {
        cout << "\nArray contains Duplicates.\n";
    }
    else {
        cout << "\nArray does not contains Duplicates.\n";
    }
   return 0;
}