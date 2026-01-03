#include<bits/stdc++.h>
using namespace std;

int tablesize = 10;
class HashTable {
private:
    int keys[10];
    string values[10]; 
    bool occupied[10];
    int hashfunction (int key) {
        return key%tablesize;
    }

public:
    HashTable () {
        for (int i = 0; i < tablesize; i++)
        {
            keys[i] = 0;
            values[i] = "";
            occupied[i] = false;
        }
    }

    void insert (int key, string val) {
        int keyhash = hashfunction (key);
        int index = keyhash;
        int i = 0;

        while (i < tablesize)
        { 
            index = (index+ i*i)%tablesize;
            if (!occupied[index] && keys[index] == key) {
                keys[index] = key;
                values[index] = val;
                occupied[index] = true;
                return;
            }

            if (index == keyhash) {
                cout << "\nHash table is full: ";
                return;
            }
            i++;
        }

        cout << "\nTable size if full: ";
    }

    string search (int key) {
       int start = hashfunction (key);
       int index = start;
       int i=0;
       while (i < tablesize)
       {
            if(!occupied[index]) return "Not found:";
            
            if (occupied && keys[index] == key) {
                return values[index];
            }
            index = (index+i*i)%tablesize;

             if (index == start) {
                break;
            }
            i++;
       }
       return "Not found";

    }
};

int main()
{
   return 0;
}