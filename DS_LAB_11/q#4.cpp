#include <iostream>
using namespace std;


void heapifyDown(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapifyDown(arr, n, largest);
    }
}

void converttoMaxHeap(int arr[], int n) {
    for (int i = (n - 2) / 2; i >= 0; i--) {
        heapifyDown(arr, n, i);
    }
}

int main() {
    int arr[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
   

    cout << "\nMin Heap: ";
    for(int i = 0; i < 10; i++) cout << arr[i] << " ";
    cout << "\n";

    converttoMaxHeap (arr,10);

    cout << "\nMax Heap: ";
    for(int i = 0; i < 10; i++) cout << arr[i] << " ";
    
    return 0;
}
