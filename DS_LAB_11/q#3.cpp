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



int getKthLargest (int arr[], int n, int k) {
    MaxHeap h(n);
    for (int i = 0; i < n; i++)
        h.insert(arr[i]);
    
    k--;
    while (k--)
    {
        h.deleteMax();
    }
    return h.getMax();
}

int main() {
    int arr[] = {1,23,12,9,30,2,50};
    int k;
    cout << "\nEnter the value of k: ";
    cin >> k;

    cout << "\nArray Element: ";
    for(int i = 0; i < 5; i++) cout << arr[i] << " ";

    int kth = getKthLargest (arr,5,k);
    cout << "\nK-th largest Element is: " << kth;

    return 0;
}
