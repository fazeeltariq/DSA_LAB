#include<iostream>
using namespace std;

class Bankaccount{
    private:
    double balance;
    public:
    Bankaccount(){
        balance = 0.0;
    }

    Bankaccount(double balance) {
       this->balance = balance;
    }

    void addBalance( double newbalance){
        balance += newbalance;
    }

    Bankaccount (const Bankaccount& other)
    {
        balance = other.balance;
    }
    double getBalance() {
        return balance;
    }
    
   void withDraw( double amount){
    if(this->balance - amount >= 0){
        this->balance = this->balance - amount;
    }
    else{
        cout << "\nNot enough balance: ";
    }
    }

    void printBalance (){
        cout << "Balance is $ " << balance <<endl;    
    }
};



int main()
{
    Bankaccount account1;
    account1.printBalance();

    Bankaccount account2(1000);
    account2.printBalance();

    Bankaccount account3(account2);  
    account3.withDraw(200);         

    account2.printBalance();     
    account3.printBalance();      
}