#include<bits/stdc++.h>
using namespace std;

char sol[5][5] ={'.'};
bool issafe(char arr[5][5], int rows, int cols, int i, int j) {
    // check column above
    for (int k = i - 1; k >= 0; k--) {
        if (arr[k][j] == 'Q') return false;
    }
    // check upper right diagonal
    for (int k = i - 1, l = j + 1; k >= 0 && l < cols; k--, l++) {
        if (arr[k][l] == 'Q') return false;
    }
    // check upper left diagonal
    for (int k = i - 1, l = j - 1; k >= 0 && l >= 0; k--, l--) {
        if (arr[k][l] == 'Q') return false;
    }
    return true;
}

void place_max_Queens(char arr[5][5], int rows, int cols, int i, int &maxi, int count) {
    if(i == rows){
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                sol[i][j] = arr[i][j];
            }
            
        }
        maxi = max(maxi,count);
        return;
    }

        for (int k = 0; k < rows; k++)
        {
            if(issafe(arr,rows,cols,i,k)) {
                arr[i][k] = 'Q';
                place_max_Queens(arr,rows,cols,i+1,maxi,count+1);
                arr[i][k] = '.';
            }
        }
}
int main()
{
   char arr[5][5] ={{'.','.','.','.','.'},
                   {'.','.','.','.','.'},
                   {'.','.','.','.','.'},
                   {'.','.','.','.','.'},
                   {'.','.','.','.','.'}}; 

    int maxi = INT_MIN;
    place_max_Queens(arr,5,5,0,maxi,0);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << sol[i][j] << " ";
        }
        cout<<"\n";
    }
    
   return 0;
}