#include <bits/stdc++.h>
using namespace std;

static int comparisons = 0;

int partitionStart(int arr[], int st, int end) {
    int idx = st ;
    int pivot = arr[st];

    for (int i = st+1; i <= end; i++) {
        comparisons++;
        if (arr[i] <= pivot) {
            idx++;
            swap(arr[idx], arr[i]);
        }
    }
    swap(arr[idx ], arr[st]);
    return idx ;
}

int partitionEnd(int arr[], int st, int end) {
    int idx = st - 1;
    int pivot = arr[end];

    for (int i = st; i < end; i++) {
        comparisons++;
        if (arr[i] <= pivot) {
            idx++;
            swap(arr[idx], arr[i]);
        }
    }
    swap(arr[idx+1], arr[end]);
    return idx + 1;
}

int partitionMiddle(int arr[], int st, int end) {
    int mid = st + (end - st) / 2;
    int pivot = arr[mid];

    swap(arr[mid], arr[end]);
    int i = st - 1;

    for (int j = st; j < end; j++) {
        comparisons++;
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[end]);
    return i + 1;
}

int Findmedian(int a, int b, int c) {
    if ((a > b) != (a > c)) return a;
    else if ((b > a) != (b > c)) return b;
    else return c;
}
int partitionMedian (int arr[], int st, int end) {
    int mid = arr[(st + end) / 2];
    int pivot = Findmedian (arr[st], arr[mid], arr[end]);

    int pivotIndex;
    if (pivot == arr[st]) pivotIndex = st;
    else if (pivot == arr[mid]) pivotIndex = mid;
    else pivotIndex = end;


    swap(arr[pivotIndex], arr[end]);


    int i = st - 1;
    for (int j = st; j < end; j++) {
        comparisons++;
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[end]);
    return i + 1;
}

void quickSort(int arr[], int st, int end) {
    if (st < end) {
        int p = partitionMedian(arr, st, end);
        quickSort(arr, st, p - 1);
        quickSort(arr, p + 1, end);
    }
}


int main() {

    int arr[10] = {10,9,8,7,6,5,4,3,2,1}; 
    int n = 10;
    cout << "\n";
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\nTotal comparisons: " << comparisons;
    return 0;
}
