#include<bits/stdc++.h>
using namespace std;

void subsets (vector<int> &arr, int i, vector<int> &ans, vector<vector<int>> &subset) {
    if (i == arr.size()) {
        subset.push_back(ans);
        return;
    }
    ans.push_back(arr[i]);
    subsets (arr,i+1,ans,subset);
    ans.pop_back();
    subsets(arr,i+1,ans,subset);
}

int main()
{
    vector<int> arr = {1,2,3};
    vector<int> ans;
    vector<vector<int>> subset;
    subsets(arr,0,ans,subset);

    for (auto &s : subset) {
        cout << "{ ";
        for (auto &x : s) cout << x << " ";
        cout << "}\n";
    }

    return 0;
}