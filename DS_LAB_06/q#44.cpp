#include <bits/stdc++.h>
using namespace std;

bool issafe(int arr[4][4], int sol[4][4], int rows, int cols, int i, int j) {
    if(i >= 0 && j >= 0 && i < rows && j < cols && arr[i][j] == 1 && sol[i][j] == 0) {
        return true;
    }
    return false;
}

bool backtrack(int arr[4][4], int sol[4][4], int rows, int cols, int i, int j) {
    
    if(i == 2 && j == 0) {
        sol[i][j] = 1; 
        return true;
    }

    if(issafe(arr, sol, rows, cols, i, j)) {
        sol[i][j] = 1; 

        if(backtrack(arr, sol, rows, cols, i + 1, j)) return true;
        if(backtrack(arr, sol, rows, cols, i - 1, j)) return true;
        if(backtrack(arr, sol, rows, cols, i, j + 1)) return true;
        if(backtrack(arr, sol, rows, cols, i, j - 1)) return true;

        sol[i][j] = 0;
        return false;
    }
    return false;
}

int main() {
     int arr[4][4] = {
        {1, 1, 1, 1},
        {0, 0, 0, 1},
        {1, 1, 0, 1},
        {1, 1, 1, 1}
    };

    int sol[4][4] = {0};

    if(backtrack(arr, sol, 4, 4, 0, 0)) {
        cout << "Path exists:\n";
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                cout << sol[i][j] << " ";
            }
            cout << "\n";
        }
    } 
    else {
        cout << "Path does not exist\n";
    }
    return 0;
}
