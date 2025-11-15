#include<iostream>
using namespace std;

class Box{
    private:
    int *data;
    public:

    Box(){
        data = nullptr;
    }

    Box(int data){
        this->data = new int(data);
    }

    // commented out due to show behaviour of shallow and deep copy

    // Box (const Box &other){
    //     data = new int(*other.data);
    // }

    //  Box& operator=(const Box &other) {
    //     if (this != &other) {
    //         delete data;
    //         data = new int(*other.data);
    //     }
    //     return *this;
    // }

    void setvalue (int value){
        delete data;
        data = new int(value);
    }

    void print(string boxname) const {
        cout << boxname << " Data: "<< *data <<endl;
    }
    ~Box (){
        delete data;
    }
};
int main()
{
    cout << "===Rule of Three Demonstration ===\n";

    Box box1(200);
    Box box2(400);

    box1.print("Box1");
    box2.print("Box2");

    // Copy constructor
    Box box3 = box1; 
    box3.print("Box3 (copy of Box1)");

    // Copy assignment
    box2 = box1; 
    box2.print("Box2 after assignment from Box1");

    // Change value in Box1
    box1.setvalue(9999);

    cout << "\nAfter modifying Box1:\n";
    box1.print("Box1");
    box2.print("Box2 (remains unchanged)");
    box3.print("Box3 (remains unchanged)");
}    