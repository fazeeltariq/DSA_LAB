#include<bits/stdc++.h>
using namespace std;

const int TABLESIZE = 100;   

class Node {
public:
    string key;
    Node *next;
  

    Node (string k) {
        key = k;
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
    
    void AddRecord (string word) {
        int idx = hashfunction (word);

        Node *temp = hashtable[idx];

        while (temp)
        {
            if (temp->key == word) {
                return;
            }
            temp  = temp->next;
        }
        Node *newNode = new Node (word);
        newNode->next = hashtable[idx];
        hashtable[idx] = newNode;
    }


    string wordsearch (string key) {
        int index = hashfunction(key);
        Node *temp = hashtable[index];

        while (temp)
        {
            if (temp->key == key) {
                return temp->key ;
            }
            temp = temp->next;
        }
        return "Key not found";
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
                cout << " -> [Value: " << temp->key << " ]";
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
    myhash.AddRecord ("fazeel");
    myhash.AddRecord("Aiman");
    myhash.AddRecord ("Ahmad");
    myhash.AddRecord ("Ali");
    myhash.AddRecord ("Adnan");
    myhash.AddRecord ("Babar");
    myhash.AddRecord ("Saim");
    myhash.AddRecord ("Virat");
    myhash.AddRecord("lazeef");

    cout << " Key found: " << myhash.wordsearch ("fazeel") <<"\n" ;

    myhash.display ();

   return 0;
}