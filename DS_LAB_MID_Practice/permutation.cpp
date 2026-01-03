#include<bits/stdc++.h>
using namespace std;

void permutations (vector<int> &arr,vector<int> &ans, vector<vector<int>> &permu, vector<bool> &used){
    if (arr.size() == ans.size()) {
        permu.push_back (ans);
        return;
    } 
    for (int i = 0; i < arr.size(); i++)
    {
        if(!used[i]) {
        ans.push_back(arr[i]);
        used[i] = true;
        permutations (arr,ans,permu,used);
        ans.pop_back();
        used[i] = false;
        }
    }
    
}

int main()
{
    vector<int> arr= {1,2,3};
    vector<int> ans;
    vector<vector<int>> permu;
    vector<bool> used (false);
    permutations(arr,ans,permu,used);

     for (auto &s : permu) {
        cout << "{ ";
        for (auto &x : s) cout << x << " ";
        cout << "}\n";
    }
   return 0;
}