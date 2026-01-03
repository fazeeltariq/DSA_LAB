#include<iostream>
using namespace std;

void insertion_sort (int arr[], int size) {
    for (int i = 1; i < size; i++)
    {
        int pivot = arr[i];
        int j = i-1;
        while (j >= 0 && arr[j] < pivot)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = pivot;
    }
}

int main () 
{
    int arr1[7] = {5,3,5,2,3,4,2};
    int arr2[2] = {5,2};

    int size1 = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if(arr2[i] == arr1[j]) size1++;
        }
    }

    int* newarr = new int[size1];
    int count = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (arr1[j] == arr2[i]){
                newarr[count++] = arr2[i];
            } 
        }
    }


    int secondarr[7-size1]= {0};
    int ndcount = 0;
   
           for (int k = 0; k < 7; k++)
           {
                int found = 0;
                for (int l = 0; l < 2; l++)
                {
                    if(arr1[k] == arr2[l]) found = 1;
                }
                if (found == 0) secondarr[ndcount++] = arr1[k];
           }

    insertion_sort(newarr,size1);
    int result[7] = {0};
    for (int i = 0; i < size1; i++)
    {
        result[i] = newarr[i];
    }
    int j = 0;
    for (int i = size1; i < 7; i++)
    {
        result[i] = secondarr[j];
        j++;
    }
    for (int i = 0; i < ndcount; i++)
    {
        cout << secondarr[i] << " ";
    }
    cout<<"\n";
    for (int i = 0; i < 7; i++)
    {
        cout << result[i] << " ";
    }
    delete[] newarr;
    
}