#include <iostream>
#include <vector>
using namespace std;

void countingSort(int arr[], int size) {
    int maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    vector<int> count(maxVal + 1, 0);

    for (int i = 0; i < size; i++) {
        count[arr[i]]++;
    }
    int index = 0;
    for (int i = 0; i <= maxVal; i++) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorting: ";
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;

    countingSort(arr, size);

    cout << "After sorting: ";
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}
