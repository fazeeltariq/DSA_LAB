#include<iostream>
#include<list>
using namespace std;

const int TABLESIZE = 10;   

class Node {
public:
    int key;
    int value;
};

class HashTable {
private:
    list<Node> table[TABLESIZE];
    
    int hashfunction (int key) {
        return key % TABLESIZE;
    }
    
public:
    HashTable () {
        
    }
    
    void insert (int key, int value) {
        int index = hashfunction (key);

        list<Node> &current = table[index];

        for (auto &it: current) {
            if (it.key == key) {
                it.value = value;
                return;
            }
        }
        
        current.push_front ({key,value});
    }


    int search (int key) {
        int index = hashfunction(key);
        list<Node> &cur = table[index];

        for (auto &it: cur) {
            if (it.key == key) {
                return it.value;
            }
        }
        return -1;
    }

    void remove(int key) {
        int idx = hashfunction(key);
    list<Node> &cur = table[idx];

    for (auto it = cur.begin(); it != cur.end(); it++) {
        if (it->key == key) {
            cur.erase(it);  
            cout << "Key " << key << " deleted\n";
            return;
        }
    }
    cout << "Key not found\n";
}


    void display() {
    for (int i = 0; i < TABLESIZE; i++) {
        cout << "Index " << i << ": ";

        list<Node> &temp = table[i];

        if (temp.empty()) {
            cout << "EMPTY";
        }

        for (auto &it : temp) {
            cout << " -> [Key: " << it.key << ", Value: " << it.value << "]";
        }
        cout << endl;
    }
}


};
int main()
{
    HashTable myhash;
    myhash.insert (1,100);
    myhash.insert (2,200);
    myhash.insert (3,300);
    myhash.insert (4,400);
    myhash.insert (5,500);
    
    cout << "Search key \n";
    cout << "Key found: " << myhash.search (300);
    myhash.display ();
    myhash.remove (100);
    myhash.display();
   return 0;
}