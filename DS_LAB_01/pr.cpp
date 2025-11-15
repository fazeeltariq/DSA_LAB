#include <iostream>
using namespace std;
class Product
{
    int price;
    int stock;
    string name;

public:
    Product()
    {
        price = 0;
        stock = 0;
        name = "";
    }
    Product(int stock, string name, int price)
    {
        this->name = name;
        this->price = price;
        this->stock = stock;
    }
    void setprice(int price)
    {
        this->price = price;
    }
    int getprice()
    {
        return price;
    }
    void display()
    {
        cout << "the name of product is " << name << endl;
        cout << "the price of product is " << price << endl;
        cout << "the stock of product is " << stock << endl;
    }
};
class Bundle
{
    Product *pp[10];
    int productcount;
    double discountpercentage;

public:
    Bundle(int discount)
    {
        discountpercentage = discount;
        for (int i = 0; i < 10; i++)
        {
            pp[i] = nullptr;
        }
        productcount = 0;
    }
    // deep copy
    Bundle(const Bundle &other)
    {
        discountpercentage = other.discountpercentage;
        productcount = other.productcount;

        for (int i = 0; i < 10; i++)
            pp[i] = nullptr;

        for (int i = 0; i < productcount; i++)
        {
            // Deep copy each product
            pp[i] = new Product(*other.pp[i]);
        }
    }

    void addproducttobundle(Product *p)
    {
        if (productcount >= 10)
        {
            cout << "product limit reached " << endl;
        }
        pp[productcount++] = p;
        cout << "product added " << endl;
    }

    void applydiscount()
    {
        for (int i = 0; i < productcount; i++)
        {
            double discountedprice = pp[i]->getprice() - (discountpercentage / 100 * pp[i]->getprice());
            pp[i]->setprice(discountedprice);
            discountedprice = 0;
        }
    }

    void display()
    {
        for (int i = 0; i < productcount; i++)
        {
            pp[i]->display();
        }
    }

    void changevalue(int price, int productno)
    {
        pp[productno]->setprice(price);
    }
    
    ~Bundle()
    {
        for (int i = 0; i < productcount; i++)
        {

            delete pp[i];
            pp[i] = nullptr;
        }
    }
};
int main()
{
   
     int discountPercentage = 5;

    // create original bundle
    Bundle obj1(discountPercentage);
    obj1.addproducttobundle(new Product(25, "Tissue", 150));
    obj1.addproducttobundle(new Product(45, "Box", 198));

    cout << "Original bundle (obj1):" << endl;
    obj1.display();

    cout << "\nApplying discount to obj1..." << endl;
    obj1.applydiscount();
    obj1.display();

    // // shallow copy
    // Bundle obj2 = obj1;   // default copy constructor
    // cout << "\nShallow copy (obj2):" << endl;
    // obj2.display();

    // cout << "\nChanging first product price in obj1..." << endl;
    // obj1.changevalue(0, 0);

    // cout << "obj1 after change:" << endl;
    // obj1.display();
    // cout << "obj2 after obj1 change (same, shallow copy):" << endl;
    // obj2.display();

    // deep copy
    Bundle b3(obj1);  // deep copy constructor
    cout << "\nDeep copy (b3):" << endl;
    b3.display();

    cout << "\nChanging second product price in obj1..." << endl;
    obj1.changevalue(1, 0);

    cout << "obj1 after change:" << endl;
    obj1.display();
    cout << "b3 after obj1 change (independent, deep copy):" << endl;
    b3.display();

    return 0;
}