#include <bits/stdc++.h>
using namespace std;

struct Customer {
    string name;
    int month;
    int date;
    int hanger = 0;
    Customer() {}
};

bool comesBefore(Customer &c1, Customer &c2) {
    if (c1.month < c2.month) return true;
    if (c1.month > c2.month) return false;

    if (c1.date < c2.date) return true;
    if (c1.date > c2.date) return false;

    if (c1.name.length() > c2.name.length()) return true;
    return false;
}

int search_hanger(Customer *c1, string name) {
    int st = 0 ,end = 5;
    while (st <= end)
    {
        int mid = st + (end - st)/2;
        if (c1[mid].name == name) {
            return c1->hanger;
        }
        else if (c1[mid].name > name) {
            end = mid-1;
        }
        else st = mid+1;
    }
    return -1;
}
int main() {
    Customer c1[5];

    cout << "Enter Name Day Month for 5 customers:\n";
    for (int i = 0; i < 5; i++) {
        int date, month;
        string name;
        cin >> name >> date >> month;
        c1[i].date = date;
        c1[i].month = month;  
        c1[i].name = name;
    }

    for (int i = 0; i < 4; i++) {
        int minIndex = i;
        for (int j = i + 1; j < 5; j++) {
            if (comesBefore(c1[j], c1[minIndex])) {
                minIndex = j;
            }
        }
        swap(c1[i], c1[minIndex]);
    }

    cout << "\nSorted Customers with Hanger Numbers:\n";
    for (int i = 0; i < 5; i++) {
        c1[i].hanger = i + 1;
        cout << c1[i].name << " (hanger " << c1[i].hanger << ") "
             << " Date: " << c1[i].date << "/" << c1[i].month << "\n";
    }

    return 0;
}
