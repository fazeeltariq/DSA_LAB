#include<bits/stdc++.h>
using namespace std;

bool issafe(int n, int i, int j) {
    return !(i < 0 || j < 0 || i >= n || j >= n);
}

bool ispalindrome (string ans) {
    int j = ans.length()-1;
    for (int i = 0; i < ans.length()/2; i++)
    {
        if (ans[i] != ans[j]) return false;
        j--;
    }
    return true;
}
void find_palindrome (char arr[5][5], int i, int j ,int n, string ans,bool visited[5][5]) {
    if (!issafe(n, i, j) || visited[i][j]) return;
    
    ans += arr[i][j];     
    visited[i][j] = true;
    
    if( ans.length() >= 5){
        if(ispalindrome(ans)) {
            cout << "\nPalindrome of length 5 " << ans;
        }
        visited[i][j] = false;
        return;
    }

    find_palindrome (arr,i+1,j,n,ans,visited);
    find_palindrome (arr,i-1,j,n,ans,visited);
    find_palindrome (arr,i,j+1,n,ans,visited);
    find_palindrome (arr,i,j-1,n,ans,visited);
    
    visited[i][j] = false;
    return;
}
int main()
{
    char arr[5][5] = {
    {'G', 'R', 'O', 'O', 'T'},
    {'B', 'A', 'R', 'R', 'O'},
    {'W', 'R', 'D', 'B', 'S'},
    {'R', 'A', 'D', 'A', 'R'},
    {'W', 'E', 'S', 'T', 'G'}
};

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++) {

            bool visited[5][5] = {false};
            find_palindrome(arr,i,j,5,"",visited);
        }
    }

    return 0;
}