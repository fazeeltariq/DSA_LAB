#include<bits/stdc++.h>
using namespace std;

void backtrack (vector<int> arr, int target,vector<int> ans, int start) {
    if (target == 0) {
        for (int i = 0; i < ans.size(); i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
        return;
    }
    if (target < 0) return;
    for (int i = start; i < arr.size(); i++)
    {
        ans.push_back(arr[i]);
        backtrack (arr,target-arr[i],ans,i);
        ans.pop_back();   
    }
    
}

int main()
{
    vector<int> arr = {2,3,6,7};
    int target = 7;
    vector<int> ans;
    backtrack(arr,target,ans,0);
   return 0;
}