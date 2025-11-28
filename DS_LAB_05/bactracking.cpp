#include <bits/stdc++.h>
using namespace std;

bool issafe(int arr[5][5], int sol[5][5], int rows, int cols, int i, int j) {
    if(i >= 0 && j >= 0 && i < rows && j < cols && arr[i][j] == 0 && sol[i][j] == 0) {
        return true;
    }
    return false;
}

bool lionMaze(int arr[5][5], int sol[5][5], int rows, int cols, int i, int j) {
    
    if(i == rows - 1 && j == cols - 1) {
        sol[i][j] = 1; 
        return true;
    }

    if(issafe(arr, sol, rows, cols, i, j)) {
        sol[i][j] = 1; 

        if(lionMaze(arr, sol, rows, cols, i + 1, j)) return true;
        if(lionMaze(arr, sol, rows, cols, i - 1, j)) return true;
        if(lionMaze(arr, sol, rows, cols, i, j + 1)) return true;
        if(lionMaze(arr, sol, rows, cols, i, j - 1)) return true;

        sol[i][j] = 0;
        return false;
    }
    return false;
}

int main() {
    int arr[5][5] = {
        {0,1,0,1,0},
        {0,0,0,0,0},
        {1,0,1,0,0},
        {0,1,1,0,0},
        {0,0,0,1,0}
    };

    int sol[5][5] = {0};

    if(lionMaze(arr, sol, 5, 5, 0, 0)) {
        cout << "Path exists:\n";
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
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
