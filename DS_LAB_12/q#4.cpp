#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
    unordered_map<int,int> mapi;
    int arr[] = {3, 4, 7, 1, 2, 9, 8};
    int size = 7;

    for (int i = 0; i < size; i++) {
        mapi[arr[i]] = i;
    }
    
    for (int i = 0; i < size; i++)
    {
        int a = arr[i];
        for (int j = i+1; j < size; j++)
        {
            int b = arr[j];
            for (int k = j+1; k < size; k++)
            {
                int c = arr[k];

                int target = a + b - c;

                if (mapi.find(target) != mapi.end()) {
                    auto it = mapi.find(target);

                    if (it->second != i && it->second != j && it->second != k) {
                        cout  << "Pair found: "<< "(" << a << "," << b << ")"
                             << " && "
                             << "(" << c << "," << target << ")"
                             << "\n";

                             return 0;
                    }
                }
            }
        }
    }

    return 0;
}
