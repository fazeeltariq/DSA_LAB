#include<iostream>
using namespace std;

int getMax(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }
    return maxVal;
}

void counting_sort(int arr[], int n , int exp) {
    int output[n];
    int count[10] = {0};


    for (int i = 0; i < n; i++)
    {
        int digit = (arr[i]/exp)%10;
        count[digit]++;
    }
    // prefix sum
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i-1];
    }
    
    for (int i = n-1; i >= 0; i--)
    {
        int digit = (arr[i]/exp)%10;
        output[count[digit]-1] = arr[i];
        count[digit]--;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radix_sort(int arr[], int n) {
    int maxi = getMax(arr,n);

    for (int exp = 1; maxi/exp > 0; exp*=10)
    {
        counting_sort(arr,n,exp);
    }
    
}

int main()
{
    int n = 10;
    int arr[10] = {240990, 215364, 236762, 243454, 252143,
                   223444, 212321, 232311, 245655, 243333};

    cout << "\nBefore sorting the IDs:\n";
    for (int i = 0; i < n; i++) {
        cout << "ID " << i + 1 << ": " << arr[i] << "\n";
    }

    radix_sort(arr, n);

    cout << "\nAfter sorting the IDs (Merit Lists) :\n";
    for (int i = 0; i < n; i++) {
        cout << "ID " << i + 1 << ": " << arr[i] << "\n";
    }

    return 0;
}