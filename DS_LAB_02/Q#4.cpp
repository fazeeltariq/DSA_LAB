#include <bits/stdc++.h>
using namespace std;

bool haveCommonfriend(bool friends[5][5], int i , int j){
    for (int k = 0; k < 5; k++)
    {
        if (k != i && k != j) {
            if (friends[i][k] && friends[j][k]) {
                return true;
            }
    }
}
    return false;
}

int main() {
    bool friends[5][5] = {
    { false, true,  true, false, true },
    { true,false, true, true, false},
    { true, true, false, true, true },
    { false, true, true,false,true },
    { true, false, true,  true, false}
};

   cout << "\nDisplaying Common Freinds for each Person : \n\n";

    for (int i = 0; i < 5; i++) {
         for (int j = i + 1; j < 5; j++) { 
        if (haveCommonfriend(friends, i, j)) {
            cout << "Persons " << i << " and " << j << " have a common friend.\n";
        } else {
            cout << "Persons " << i << " and " << j << " do NOT have a common friend.\n";
        }
    }
    }

    return 0;
}
