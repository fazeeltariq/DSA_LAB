#include <iostream>
using namespace std;

const int N = 4; // created a global variable

// safe function for checking if a flag can be placed.
bool issafe(int  board[N][N], int row, int col, int solution[N][N]) {

    for (int i = 0; i < row; i++) {
        if (board[i][col]==1) 
        return false;
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]==1) 
        return false;
    }
    for (int i = row, j=col; i>=0 && j<N; i--, j++) {
        if (board[i][j]==1) 
        return false;
    }
    return true;
}

void backtrack(int  board[N][N], int row, int &maximumFlags, int solution[N][N]) {
    if (row == N) {
        maximumFlags = N;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                solution[i][j] = board[i][j];
        return;
    }

    for (int col = 0; col < N; col++) {

        if (issafe(board, row, col, solution)) {

            board[row][col] = 1; 

            backtrack(board, row + 1, maximumFlags, solution);

            board[row][col] = 0;  

        }
    }
}

int main() {
    int board[N][N] = {0};
    int maximumFlags = 0;
    int solution[N][N] = {0};

    backtrack(board, 0, maximumFlags, solution);

    
    cout << "\nThe maximum flags that can be placed on " << N << " x " << N << " matrix is " << maximumFlags <<endl;
     
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << solution[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
