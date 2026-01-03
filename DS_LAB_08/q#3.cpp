#include <iostream>
using namespace std;

class Runner {
public:
    string name;
    int time; 
    Runner() {}
    Runner(string n, int t) {
        name = n;
        time = t;
    }
};
void merge(Runner arr[], int start, int mid, int end) {
    int n1 = mid-start+1;
    int n2 = end-mid;
    Runner left[10],right[10];

    for (int i = 0; i < n1; i++) {
        left[i] = arr[start + i];
    }

    for (int j = 0; j < n2; j++) {
        right[j] = arr[mid +1+j];
    }

    int i = 0, j = 0, k = start;
    while (i < n1 && j < n2) {
        if (left[i].time <= right[j].time) {
            arr[k] = left[i];
            i++;
        } 
        else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(Runner arr[], int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

int main() {
    int n = 10;
    Runner runners[n] = {{"Ali", 320},{"Babar", 280},{"Moiz", 295},
        {"Ayesha", 310},{"Ahmed", 270},{"Umar", 330},{"Fazeel", 285},
        {"Aimna", 300},{"Bisma", 260},{"Usman", 340}
    };

    cout << "Original Runners:\n";
    for (int i = 0; i < n; i++) {
        cout << runners[i].name << " - " << runners[i].time << " seconds\n";
    }

    mergeSort(runners,0,n-1);

    cout << "\n 5 Fastest Runners\n";
    cout << "----------------------------------\n";
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ". " << runners[i].name << " - "<<runners[i].time << " seconds\n";
    }

    return 0;
}
