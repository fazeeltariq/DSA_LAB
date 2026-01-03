#include<bits/stdc++.h>
using namespace std;

#define d 256

int rabinCarp(string text, string pattern, int q) {
    int n = text.length();
    int m = pattern.length();
    
    int p = 0; // hash value for pattern
    int t = 0; // current window text hash value
    int h = 1;

    // h = (d^(m-1))%q
    for (int i = 0; i < m - 1; i++)
    {
        h = (h*d)%q;
    }

    for (int i = 0; i < m; i++)
    {
        p = (d*p + pattern[i])%q;
        t = (d*t + text[i])%q;
    }
    
    for (int i = 0; i <= n-m; i++)
    {
        if (p == t) {
            bool match = true;
            for (int j = 0; j < m; j++)
            {
                if (text[i+j] != pattern[j]) {
                    match  = false;
                    cout << "Hash value that is disarded: "<< t << endl;
                    break;
                }
            }
            if (match) {
                cout << "Pattern found at index " << i << endl;
            }
        }

        if (i < n-m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;

            if (t < 0) {
                t = t + q;
            }
        }
    }
    
}

int main()
{
    string text = "Data structures and Algorithms are fun. Algorithms make tasks easier";
    string pattern = "Algorithms";

    int q = 101;
    rabinCarp (text,pattern,q);
    return 0;
}