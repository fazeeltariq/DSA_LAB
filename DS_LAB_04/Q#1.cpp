#include<iostream>
#include <climits>
using namespace std;

void selectionsort(int arr[], int size) {
    for (int i = 0; i < size-1; i++)
    {
        int minIndex = i;
        for (int j = i; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap (arr[i], arr[minIndex]);
    }
}

int main()
{
    int size = 10;
    int arr[10];
    cout << "\nEnter 10 elements of array:";

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    selectionsort(arr,size);

    cout << "\n4 minimum elements in array are:\n";
    for (int i = 0; i < 4; i++)
    {
        cout << "Minimum # " << i+1 << " : " << arr[i] << "\n";
    }

   return 0;
}