#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {4, 1, 7, 3, 8, 2};
    int k = 3;

    priority_queue<int, vector<int>, greater<int>> minHeap; // min heap

    for (int x : arr) {
        minHeap.push(x);
        if (minHeap.size() > k)
            minHeap.pop(); // remove smallest
    }

    cout << "Top " << k << " largest elements: ";
    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
}
