#include<bits/stdc++.h>
using namespace std;

int health = 100;
int maxi = INT_MIN;

bool issafe (char arr[6][6],int i, int j, int size) {
    if (i >= 0 && j >= 0 &&  i < size && j < size && arr[i][j] !='X') return true;

    return false;
}

void reach_safe (char arr[6][6],int i, int j, int size, int sol[6][6]) {

    if ( arr[i][j] =='D' ) {
        maxi = max (maxi,health);
        sol[i][j] = 1;
        cout << "\nPath found (health = " << health << "):\n";
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                cout << sol[i][j] << " ";
            }
            cout << "\n";
        }
        return;
    } 

    if (issafe (arr,i,j,size) && sol[i][j] == 0) {

        sol[i][j] = 1;
        int temp = health; 
        if (arr[i][j] == 'R') health--;

        reach_safe (arr,i+1,j,size,sol);
        reach_safe (arr,i-1,j,size,sol);
        reach_safe (arr,i,j-1,size,sol);
        reach_safe (arr,i,j+1,size,sol);

        health = temp;
        sol[i][j] = 0;
    }   
    return;
}

int main()
{
    char arr[6][6] = {
        {'H','S','S','X','R','R'},
        {'S','S','S','X','S','R'},
        {'S','R','S','S','S','X'},
        {'S','X','S','X','S','S'},
        {'S','S','S','R','S','X'},
        {'S','X','S','S','S','D'}
    };

    int sol[6][6] = {0};

    reach_safe (arr,0,0,6,sol);
    if (maxi != INT_MIN){
        cout << "\nSafe path found with health = " << maxi << "\n";
        
    }
    else  {
        cout<< "\nPath does not exist: ";
    }
    return 0;
}