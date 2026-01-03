#include<bits/stdc++.h>
using namespace std;

const int TABLESIZE = 10;   

class Node {
public:
    string key;
    Node *next;
    string value;

    Node (string k, string value) {
        key = k;
        this->value = value;
        next = NULL;
    }

};
class HashTable {
private:
    Node *hashtable[TABLESIZE];
    
    int hashfunction (string key) {
        int hashvalue = 0;
        for (int i = 0; i < key.length(); i++) {
            hashvalue += key[i];
        }
        return hashvalue % TABLESIZE;
    }
    
public:
    HashTable () {
        for (int i = 0; i < TABLESIZE ;i++) {
            hashtable[i] = nullptr;
        }
    }
    
    void insert (string key, string value) {
        int index = hashfunction (key);

        Node *current = hashtable[index];

        while (current)
        {
            if (current->key == key) {
                current->key = value;
                return;
            }
            current = current->next;
        }
        
        Node *newNode = new Node (key,value);
        newNode->next = hashtable [index];
        hashtable[index] = newNode;
    }

    string search (string key) {
        int index = hashfunction(key);
        Node *temp = hashtable[index];

        while (temp)
        {
            if (temp->key == key) {
                return temp->value;
            }
            temp = temp->next;
        }
        return "Key not found";
    }

    void remove (string key) {
        int idx = hashfunction (key);
        Node *temp = hashtable[idx];
        Node *prev = NULL;

        while (temp)
        {
            prev = temp;
            if (temp->key == key) 
                break;
            
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "\nKey not found: ";
            return;
        }
        if (prev == NULL) {
            hashtable[idx] = temp->next;
        }
        else {
            prev->next = temp->next;
        }
        delete temp;
        cout << "Key "<< key << " deleted: \n";
    }

    void display () {
        for (int i = 0; i < TABLESIZE; i++){
            cout << "Index " << i << " : ";
            Node *temp = hashtable[i];

            if (!temp) {
                cout << "\nEmpty: ";
            }

            while (temp)
            {
                cout << " -> [Key: " << temp->key << ", Name " << temp->value << " ]";
                temp = temp->next;
            }
            cout << endl;
        }   
    }

    ~HashTable() {
        for (int i = 0; i < TABLESIZE; i++)
        {
            Node *temp = hashtable[i];
            while (temp)
            {
                Node *cur = temp;
                temp = temp->next;
                delete cur;
            }  
        }
    }

};
int main()
{
    HashTable myhash;
    myhash.insert ("A","aaaaa");
    myhash.insert ("B","bbbbb");
    myhash.insert ("C","ccccc");
    myhash.insert ("A","zzzzz");

    myhash.display ();
   return 0;
}