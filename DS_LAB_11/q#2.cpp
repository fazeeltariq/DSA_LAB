#include <iostream>
using namespace std;

class MaxHeap {
private:
    int *arr;
    int size;
    int total_size;

public:
    MaxHeap(int s) {
        total_size = s;
        arr = new int[total_size];
        size = 0;
    }

    int parent(int i) { return (i - 1) / 2; }
    int leftchild(int i) { return 2 * i + 1; }
    int rightchild(int i) { return 2 * i + 2; }

    void heapifyUp(int i) {
        while (i > 0 && arr[i] > arr[parent(i)]) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void insert(int val) {
        if (size >= total_size) {
            cout << "\nHeap overflow!\n";
            return;
        }
        arr[size] = val;
        heapifyUp(size);
        size++;
    }

    void heapifyDown(int i) {
        int largest = i;
        int left = leftchild(i);
        int right = rightchild(i);

        if (left < size && arr[left] > arr[largest])
            largest = left;

        if (right < size && arr[right] > arr[largest])
            largest = right;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapifyDown(largest);
        }
    }

    void deleteMax() {
        if (size == 0) {
            cout << "Heap is empty!\n";
            return;
        }
        arr[0] = arr[size - 1];
        size--;
        heapifyDown(0);
    }

    int getMax() {
        return arr[0];
    }

    ~MaxHeap() {
        delete[] arr;
    }
};

int leftchild(int i) { return 2 * i + 1; }
int rightchild(int i) { return 2 * i + 2; }

bool isMaxHeap(int arr[], int n) {
    for (int i = 0; i <= (n - 2) / 2; i++) {
        int left = leftchild(i);
        int right = rightchild(i);

        if (left < n && arr[i] < arr[left])
            return false;
        if (right < n && arr[i] < arr[right])
            return false;
    }
    return true;
}

void HeapSort(int arr[], int n) {
    MaxHeap h(n);
    for (int i = 0; i < n; i++)
        h.insert(arr[i]);
    for (int i = n - 1; i >= 0; i--) {
        arr[i] = h.getMax();
        h.deleteMax();
    }
}

int main() {
    int arr[6] = {10, 2, 1, 4, -1, 100};

    if (isMaxHeap(arr, 6)) {
        cout << "\nArray is a binary heap.\n";
    } else {
        cout << "\nArray is not a binary heap.\n";
    }

    cout << "\nBefore sorting the array: ";
    for (int i=0;i<6;i++) cout << arr[i] << " ";
    cout << endl;

    HeapSort(arr, 6);

    cout << "Sorted array using Heap Sort: ";
    for (int i = 0; i < 6; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
