#include <bits/stdc++.h>
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
        cout << val << " inserted into heap.\n";
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

        cout << arr[0] << " is deleted.\n";
        arr[0] = arr[size - 1];
        size--;
        heapifyDown(0);
    }

    void updateKey (int i, int newval) {
        if (i < 0 || i >= size) {
            cout << "Invalid index!\n";
            return;
        }
        int old_val = arr[i];
        arr[i] = newval;

        if (newval > old_val) {
            heapifyUp (i);
        }
        else if (newval < old_val) {
            heapifyDown (i);
        }
    }

    void deleteAtIndex(int i) {
        if (i < 0 || i >= size) {
            cout << "Invalid index!\n";
            return;
        }

        cout << arr[i] << " is deleted at index " << i << ".\n";
        arr[i] = arr[size - 1];
        size--;
        heapifyDown(i);
    }


    void print() {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }
};


class MinHeap {
private:
    int *arr;
    int size;
    int total_size;

public:
    MinHeap(int s) {
        total_size = s;
        arr = new int[total_size];
        size = 0;
    }

    int parent(int i) { return (i - 1) / 2; }
    int leftchild(int i) { return 2 * i + 1; }
    int rightchild(int i) { return 2 * i + 2; }

    void heapifyUp(int i) {
        while (i > 0 && arr[i] < arr[parent(i)]) {
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
        cout << val << " inserted into heap.\n";
        heapifyUp(size);
        size++;
    }

    void heapifyDown(int i) {
        int smallest = i;
        int left = leftchild(i);
        int right = rightchild(i);

        if (left < size && arr[left] < arr[smallest])
            smallest = left;

        if (right < size && arr[right] < arr[smallest])
            smallest = right;

        if (smallest != i) {
            swap(arr[i], arr[smallest]);
            heapifyDown(smallest);
        }
    }

    void deleteMin() {
        if (size == 0) {
            cout << "Heap is empty!\n";
            return;
        }

        cout << arr[0] << " is deleted.\n";
        arr[0] = arr[size - 1];
        size--;
        heapifyDown(0);
    }
};
int main() {
    MaxHeap h1(10);
    h1.insert(8);
    h1.insert(7);
    h1.insert(6);
    h1.insert(5);
    h1.insert(4);

    cout << "Initial Max Heap: ";
    h1.print();

    h1.updateKey(2, 10);

    cout << "After update: ";
    h1.print();


    h1.deleteAtIndex (2);

    cout << "After deleting the updated element: ";
    h1.print();

    return 0;
}
