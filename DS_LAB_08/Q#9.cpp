#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int start, int end) {
    int mid = start + (end - start) / 2;
    int i = start, j = mid + 1;
    int n = end - start + 1;
    int temp[n];
    int index = 0;

    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j])
            temp[index++] = arr[i++];
        else
            temp[index++] = arr[j++];
    }

    while (i <= mid)
        temp[index++] = arr[i++];

    while (j <= end)
        temp[index++] = arr[j++];

    for (int k = 0; k < n; k++)
        arr[start + k] = temp[k];
}


void mergesort(int arr[], int st, int en)
{
    if (st >= en){
        return;
    }

    int mid = (st + en) / 2;
    mergesort(arr, st, mid);
    mergesort(arr, mid + 1, en);
    merge(arr, st, en);
}

int main()
{
    int arr[] = {3, 1, 4, 5, 2};
    int size = 5;
    mergesort(arr, 0, 4);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}