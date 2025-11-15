#include <iostream>
#include <cstring>
using namespace std;

class Product{
    private:
    char *name;
    double price;
    int stockquanity;
    double discount = 0.0;
    public:

    Product(){
        name = nullptr;
        price = 0.0;
        stockquanity = 0;
    }

    Product (const char* newname, double price, int stockquantity){
        name = new char [strlen(newname) + 1];
        strcpy (name, newname);
        this->price = price;
        this->stockquanity = stockquantity;
    }

    Product(const Product& other) {
        name = new char[strlen(other.name) + 1];
        strcpy(name,other.name);
        price = other.price;
        stockquanity = other.stockquanity;
    }

    void applyDiscount(double discount) {
        this->discount = discount;
        price=price-(price*discount/100.0);
    }

    Product& operator=(const Product& other) {
        if (this != &other){
            delete[] name;
            name = new char[strlen(other.name)+1];
            strcpy(name,other.name);
            price = other.price;
            stockquanity = other.stockquanity;
        }
        return *this;
    }

    void setPrice( double price) {
        this->price = price;
    }

    void displayDetails(){
        cout << "\nProduct name: "<<name;
        cout << "\nProduct price: "<<price;
        cout << "\nProduct stock: "<<stockquanity;
        cout << "\nProduct discount: "<<discount << " %";
        cout << endl;
    }  

    ~Product(){
        delete[] name;
    }

};

class Bundle{
    private:
    Product *products;
    int size;
    int productcount = 0;
    bool istakingmemory;
    public:

    Bundle (int s, Product arr[]){
        size = s;
        productcount = s;
        products = new Product[size];
        for (int i = 0; i < size; i++)
        {
            products[i]=arr[i];
        }
        istakingmemory = true;
    }

    Bundle(const Bundle& other,bool shallow) {
        if (shallow) {
            products = other.products;
            productcount = other.productcount;
            istakingmemory = false; 
        } 
        else {
            productcount=other.productcount;
            products = new Product[productcount];

            for (int i=0;i<productcount;i++){
                products[i]=other.products[i];
            }
            istakingmemory=true;
        }
    }

   void addProduct(Product& p) {
        Product* temp = new Product[productcount + 1];
        for (int i = 0; i < productcount; i++) {
            temp[i] = products[i];
        }
        temp[productcount] = p;
        delete[] products; 
        products = temp;
        productcount++;
    }

    void displayDetails() const {
        cout << "\nProduct Details: ";
        for (int i = 0; i < productcount; i++)
        {
            cout << "Product " << i + 1 << ": ";
            products[i].displayDetails();
        }
    }

    void applyDiscount(double discount){
        for (int i = 0; i < productcount; i++)
        {
            products[i].applyDiscount(discount);
        }
    }

    void setAllProductsprice(double price){
        for (int i = 0; i < productcount; i++)
        {
            products[i].setPrice(price);
        }
        cout << "\nPrice has been set for all products: ";
    }

    ~Bundle() {
        if(istakingmemory)
        delete[] products;
    }


};
int main()
{
    Product products[3];
    products[0] = Product("TV", 2000, 15);
    products[1] = Product("Mobile-Phone", 3000, 20);
    products[2] = Product("Laptop", 60000, 25);

    Bundle bundle (3,products);

    Product newproduct ("PC",100000,30);
    bundle.addProduct(newproduct);
   
    cout << "\nBefore Applying Discount:\n";
    bundle.displayDetails();

    bundle.applyDiscount(20);

    cout << "\nAfter Applying Discount:\n";
    bundle.displayDetails();

    // Shallow and Deep Copy
    

    // making shallow copy.
    cout << "\n------------Making Shallow copy-------------"; 
    Bundle newbundle(bundle,true);
    newbundle.displayDetails();

    // changing price of new-bundle
    newbundle.setAllProductsprice(1000);

    // displaying original bundle. Also change price in old bundle due to shallow copy.
    bundle.displayDetails();
    cout << "\n-------------------------------------------\n";
    // making deep copy.
      cout << "\n------------Making Deep copy-------------";
    Product p[1];
    p[0] = Product("Hair-Brush",100,23);
    Bundle b1(1,p);

    Bundle b2(b1,false);
    // changing price in bundle 2.
    b2.setAllProductsprice(416983);

    // displaying bundle 1 price. It won't be changed due to deep copy.

    b1.displayDetails();


    return 0;
}