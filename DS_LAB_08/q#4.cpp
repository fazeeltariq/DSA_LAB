#include <bits/stdc++.h>
using namespace std;

class Product {
public:
    string name;
    double price;
    string description;
    bool isavailable;
    Product(string n, double p, string d, bool available) {
        name = n;
        price = p;
        description = d;
        isavailable = available;
    }
    void display() {
        cout << "----------------------------------------\n";
        cout << "Product Name : "<< name << endl;
        cout << "Price        : $" <<fixed<<setprecision(2) << price << endl;
        cout << "Description  : " << description << endl;
        cout << "Available    : "<<(isavailable ? "Yes" : "No")<< endl;
    }
};

int partition(Product p[], int start, int end) {
    double pivot = p[end].price;
    int i = start-1;

    for (int j = start; j < end; j++) {
        if (p[j].price <= pivot) {
            i++;
            swap(p[i], p[j]);
        }
    }
    swap(p[i+1], p[end]);

    return i + 1;
}
void quick(Product p[], int start,int end) {
    if (start < end) {
        int part = partition(p, start, end);
        quick(p, start, part - 1);
        quick(p, part + 1, end);
    }
}

int main() {
    Product products[] = {
        {"Product 1", 10.99, "This is product 1.", true},
        {"Product 2", 5.99, "This is product 2.", false},
        {"Product 3", 2.99, "This is product 3.", true}
    };

    int n = sizeof(products) / sizeof(products[0]);

    cout << "========== BEFORE SORTING ==========\n";
    for (int i = 0; i < n; i++)
        products[i].display();

    quick(products, 0, n - 1);

    cout << "\n========== AFTER SORTING ==========\n";
    for (int i = 0; i < n; i++)
        products[i].display();

    return 0;
}
