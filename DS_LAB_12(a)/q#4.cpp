#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define NO_OF_CHARS 256

// Create bad character table
void badCharHeuristic(const string &pattern, vector<int> &badChar) {
    int m = pattern.length();
    for (int i = 0; i < 256; i++)
        badChar[i] = -1; // initialize all as -1

    for (int i = 0; i < m; i++)
        badChar[(int)pattern[i]] = i; // last occurrence
}

// Boyer-Moore search using bad character rule
void boyerMooreSearch(const string &text, const string &pattern) {
    int n = text.length();
    int m = pattern.length();

    vector<int> badChar(256);
    badCharHeuristic(pattern, badChar);

    int s = 0; // shift of pattern with respect to text
    while (s <= n - m) {
        int j = m - 1;

        // Keep comparing pattern from right to left
        while (j >= 0 && pattern[j] == text[s + j])
            j--;

        if (j < 0) {
            cout << "Pattern found at index " << s << endl;

            // Shift pattern so next character in text aligns with last occurrence in pattern
            s += (s + m < n) ? m - badChar[text[s + m]] : 1;
        } 
        else {
            // Shift pattern according to bad character rule
            int shift = max(1, j - badChar[text[s + j]]);
            s += shift;
        }
    }
}

int main() {
    string text = "ABAAABCDBBABCDDEBCABC";
    string pattern = "ABC";

    boyerMooreSearch(text, pattern);

    
    return 0;
}