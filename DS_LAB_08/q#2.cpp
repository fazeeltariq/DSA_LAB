#include <iostream>  
using namespace std;
  
int getMax(int a[], int n) {  
   int max = a[0];  
   for(int i = 1; i<n; i++) {  
      if(a[i] > max)  
         max = a[i];  
   }  
   return max; 
}  
void countingSort(int arr[], int n, int exp) {
    int *output = new int[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 8; i >= 0; i--)
        count[i] += count[i + 1];

    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    delete[] output;
}

void radixsort(int a[], int n) {  
  int max = getMax(a, n);  
  
  for (int place = 1; max / place > 0; place *= 10)  
    countingSort(a, n, place);  
}  
  
void printArray(int a[], int n) {  
  for (int i = 0; i < n; ++i) {  
    cout<<a[i]<<" ";  
  }  
  cout<<"\n";  
}  
  
int main() {  
  int a[] = {36, 987, 654, 2, 20, 99, 456, 555, 957, 3, 66};  

  int n = sizeof(a) / sizeof(a[0]);  
  cout<<"Before sorting array elements are - \n";

  printArray(a,n);  
  radixsort(a, n);  
  cout<<"After applying Radix sort, the array elements are -\n";  
  printArray(a, n);  
}  
