#include<bits/stdc++.h>
using namespace std;


void merge(int a[], int beg, int mid, int end)    
{    
    int i, j, k;  
    int n1 = mid - beg + 1;    
    int n2 = end - mid;       
    int LeftArray[n1], RightArray[n2];
      
    for (int i = 0; i < n1; i++)    
    LeftArray[i] = a[beg + i];    
    for (int j = 0; j < n2; j++)    
    RightArray[j] = a[mid + 1 + j];    
    i = 0;
    j = 0;  
    k = beg; 
    while (i < n1 && j < n2) {    
        if(LeftArray[i] <= RightArray[j]) {    
            a[k] = LeftArray[i];    
            i++;    
        }    
        else {    
        a[k] = RightArray[j];    
            j++;    
        }    
        k++;    
    }    
    while (i < n1) {    
        a[k] = LeftArray[i];    
        i++;    
        k++;    
    }    
      
    while (j < n2)  {    
        a[k] = RightArray[j];    
        j++;    
        k++;    
    }    
}    
  
void mergeSort(int a[], int beg, int end)  
{  
    if (beg < end)   
    {  
        int mid = (beg + end) / 2;  
        mergeSort(a, beg, mid);  
        mergeSort(a, mid + 1, end);  
        merge(a, beg, mid, end);  
    }  
}  

int main()
{
    int arr1[10] = {3, 4, 5, 1, 8, 9, 10, 11, 13, 7};
    int arr2[10] = {40, 23, 43, 11, 9, 7, 49, 33, 17, 21};

    int arr3[20];
    for (int i = 0; i < 10; i++)
    {
        arr3[i] = arr1[i];
    }
    int j = 10;
    for (int i = 0; i < 10; i++)
    {
        arr3[j] = arr2[i];
        j++;
    }
    cout << "\nBefore Sorting:\n";
    for (int i = 0; i < 20; i++) {
        cout << arr3[i] << " ";
    }
    cout << "\n";
    
    mergeSort(arr3, 0, 19);

    cout << "\nAfter Sorting :\n";

    for (int i = 0; i < 20; i++) {
        cout << arr3[i] << " ";
    }
    cout << "\n";

    return 0;
}