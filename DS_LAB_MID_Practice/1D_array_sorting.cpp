#include<bits/stdc++.h>
using namespace std;

void selectionsort(int arr[], int temp[], int newarr[], int size) {
    int p = 0;
    for (int i = 0; i < size; i++)  
    {
        int minindex = i;
        for (int j = i+1; j < size; j++)
        {
            if (arr[j] < arr[minindex]) {
                minindex = j;
            }
        }
        int small = arr[minindex];
        swap(arr[minindex], arr[i]);

        int found = 0;
        for (int l = 0; l < i; l++) {
            if (arr[l] == small) {
                found = 1;
                break;
            }
        }

        if (found == 0) {
            for (int k = 0; k < size; k++) {
                if (newarr[k] == small) {
                    temp[k] = p;
                }
            }
            p++;
        }
    }
}

int main()
{
    int arr[6] = {12, 5, 8, 5, 15, 8};
    int newarr[6] = {12, 5, 8, 5, 15, 8};
    int temp[6] = {0};

    selectionsort(arr, temp, newarr, 6);

    for (int i = 0; i < 6; i++) {
        cout << temp[i] << " ";
    }

    return 0;
}
