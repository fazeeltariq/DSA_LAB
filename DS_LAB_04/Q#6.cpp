#include<iostream>
#include<climits>
using namespace std;
int main()
{
    int arr[6] = {29,83,471,36,91,8};
    int max = INT_MIN;
    for (int i = 0; i < 6; i++)
    {
        if(max > arr[i]) {
            max = arr[i];
        }
    }
    int noofdigits = 0;
    while(max>0){
        max = max/10;
        noofdigits++;
    }
    int exp = 1;
    while(noofdigits--){
        exp*=10;
    }
    


    
   return 0;
}