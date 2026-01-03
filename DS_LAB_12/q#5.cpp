#include <iostream>
#include <string>
using namespace std;

const int TABLE_SIZE = 15;

class StudentHashTable {
private:
    int rollNo[TABLE_SIZE];
    string Name[TABLE_SIZE];
    bool occupied[TABLE_SIZE];

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }
public:
    StudentHashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            rollNo[i] = 0;
            Name[i] = "";
            occupied[i] = false;
        }
    }
    void InsertRecord(int key, const string& name) {
        int hash = hashFunction(key);
        int index;
        int i = 0;

        while (i < TABLE_SIZE) {
            index = (hash + i * i) % TABLE_SIZE;

            if (!occupied[index] || rollNo[index] == key) {
                rollNo[index] = key;
                Name[index] = name;
                occupied[index] = true;
                return;
            }
            i++;
        }

        cout << "Hash table full, cannot insert key " << key << endl;
    }

    void SearchRecord(int key) {
        int hash = hashFunction(key);
        int index;
        int i = 0;

        while (i < TABLE_SIZE) {
            index = (hash + i * i) % TABLE_SIZE;

            if (!occupied[index]) {
                cout << "Record not found\n";
                return;
            }

            if (rollNo[index] == key) {
                cout << "Record found: " << Name[index] << endl;
                return;
            }

            i++;
        }
        cout << "Record not found\n";
    }

    void Display() {
        cout << "Index\tRollNo\tName\n";
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (occupied[i])
                cout << i << "\t" << rollNo[i] << "\t" << Name[i] << "\n";
            else
                cout << i << "\t-\t-\n";
        }
    }
};

int main() {
    StudentHashTable h;

    h.InsertRecord(1, "Ali");
    h.InsertRecord(11, "Sara");
    h.InsertRecord(21, "Raza");
    h.InsertRecord(2, "Taha");

    h.SearchRecord(11);
    h.SearchRecord(21);
    h.SearchRecord(5);

    cout << "\nHash table:\n";
    h.Display();

    return 0;
}
