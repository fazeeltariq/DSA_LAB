#include <iostream>
using namespace std;
int main()
{
    string arr[] = {"banana", "apple", "cherry", "date", "grape"};
    int n = 5;

    cout << "\nBefore sorting:\n[ ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
        if (i != n - 1) cout << ", ";
    }
    cout << " ]\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j+1]) {
                string temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    cout << "\nAfter sorting the array of strings:\n[ ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
        if (i != n-1) cout << ", ";
    }
    cout << " ]\n";

    return 0;
}
