#include<bits/stdc++.h>
using namespace std;

bool issafe (vector<vector<char>> &board,  int i, int j, char num) {
    // check row
   for (int k = 0; k < 9; k++) {
    if (board[i][k] == num) return false;
    }

    // check column
   for (int k = 0; k < 9; k++) {
    if (board[k][j] == num) return false;
    }

    // check grid
    int startRow = (i/3)*3;
    int startCol = (j/3)*3;

        
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            if (board[startRow + r][startCol + c] == num) return false;
        }
    }
        return true;
}


bool solvesuduko (vector<vector<char>> &board, vector<char> &arr, int i, int j) {
    if (i == 9) return true;

    int col = j+1, row = i;
    if (col == 9) {
        col = 0;
        row = i + 1;
    }
     if (board[i][j] != '.') {
        return solvesuduko(board, arr, row, col); 
    }

    for (int k = 0; k < 9; k++)
    {   
        if (issafe (board,i,j,arr[k]) && board[i][j] == '.') {
            board[i][j] = arr[k];
            if (solvesuduko (board,arr,row,col)) return true;
            board[i][j] = '.';
        }
    }
    return false;
}

int main()
{
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    vector<char> arr = {'1','2','3','4','5','6','7','8','9'};

    solvesuduko(board,arr,0,0);

    for (auto &row : board) {
        for (auto &c : row) cout << c << " ";
        cout << "\n";
    }
   return 0;
}