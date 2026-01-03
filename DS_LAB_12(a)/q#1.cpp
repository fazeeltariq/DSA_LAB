#include<bits/stdc++.h>
using namespace std;

int findpattern (string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    int totalcomparisons = 0;
    for (int i = 0; i <= n-m; i++)
    {
        int j = 0;
        while (j < m && text[i+j] == pattern[j])
        {
            j++;
            totalcomparisons++;
        }
        if (j == m) {
            cout << "Pattern found at index " << i << endl;
        }
    }
    return totalcomparisons;
}

int main()
{
    string text = "the quick brown fox jumps over the lazy dog";
    string pattern = "the";

    cout << "\nTotal comparisons are: " << findpattern (text,pattern);
   return 0;
}