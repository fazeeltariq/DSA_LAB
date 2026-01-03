#include<bits/stdc++.h>
using namespace std;

bool issafe(int n, int m, int i, int j) {
    return !(i < 0 || j < 0 || i >= n || j >= m);
}

bool findWord(char arr[][6], int n, int m, string &word, int i, int j, int idx, int visited[5][6]) {
    if (idx == word.size()) return true;
    if (!issafe(n, m, i, j) || visited[i][j] || arr[i][j] != word[idx]) return false;

    visited[i][j] = 1;

    bool found =
        findWord(arr, n, m, word, i + 1, j, idx + 1, visited) ||
        findWord(arr, n, m, word, i - 1, j, idx + 1, visited) ||
        findWord(arr, n, m, word, i, j + 1, idx + 1, visited) ||
        findWord(arr, n, m, word, i, j - 1, idx + 1, visited);

    visited[i][j] = 0;
    return found;
}

int main()
{
    int n = 5, m = 6;
    char arr[5][6] = {
        {'g', 'a', 'k', 'i', 'w', 'i'},
        {'r', 'p', 'o', 'p', 'l', 'a'},
        {'a', 'p', 'a', 'p', 'b', 'a'},
        {'p', 'l', 'e', 'm', 'o', 'n'},
        {'e', 'e', 'e', 'p', 'b', 'p'}
    };
    cout<<"\nEnter the no of words to find: ";
    int k;
    cin>>k;
    while (k--)
    {
        cout<<"\nEnter word: ";
        string word;
        cin>>word;
        int found = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int visited[5][6] = {0};
                if(findWord(arr,n,m,word,i,j,0,visited)) {
                    cout << "\nWord '"<<word<<"' found starting at ("<<i<<","<<j<<")\n";
                    found = 1;
                    break;
                }   
            }      
        }   
        if (found == 0) {
            cout << "\nWord not found: \n";
        }
    }
   return 0;
}