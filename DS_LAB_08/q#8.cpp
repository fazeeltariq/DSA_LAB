#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void radixSort(int arr[], int n) {
    queue<int> q[10];  
    int maxNum = getMax(arr, n);

    int maxDigits = 0;
    while (maxNum > 0) {
        maxDigits++;
        maxNum /= 10;
    }

    int exp = 1;
    for (int d = 0; d < maxDigits; d++) {
      
        for (int i = 0; i < n; i++) {
            int digit = (arr[i] / exp) % 10;
            q[digit].push(arr[i]);
        }


        int index = 0;
        for (int i = 0; i < 10; i++) {
            while (!q[i].empty()) {
                arr[index++] = q[i].front();
                q[i].pop();
            }
        }

        exp *= 10;
    }
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorting: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    radixSort(arr, n);

    cout << "After sorting:  ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
