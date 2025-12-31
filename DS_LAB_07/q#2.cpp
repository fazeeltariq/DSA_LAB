#include<iostream>
#include <ctime>
using namespace std;

class Transaction {
private:
    int id;
    double amount;
    string description;
    bool isSale; // is money received
    static int count;
public:
    Transaction () {}

    Transaction (double amount, string desc, bool isSale) {
        this->amount = amount;
        this->description = desc;
        this->isSale = isSale;
        count++;
        id = count;    // generating a unique ID
    }

    bool checkDescription () {
        return description.size() > 20;
    }

    void cutDescription () {
        if(checkDescription()) {
            description = description.substr(0,20) + "...";
        }
    }
    double getSaleAmount () { return amount; }

    void setSaleAmountAfterDiscount (double amount) {
        this->amount = amount;
    }
    void setTrasaction (double amount) {
        this->amount = amount;
    }

    void setFlag (bool val) {
        isSale = val;
    }
    string getDescription () { return description; }

    void setDescription  (string d) { this->description = d; }

    void display () {
        cout << "Transaction ID: " << id << "\n" << "Amount: " << amount << " PKR\n" << "Description: " << description << "\n"
             << "Type: " << (isSale ? "Sale" : "Refund") << "\n"
             << "-----------------------------\n";
    }

};
int Transaction::count = 0;

class Node {
public:
    Transaction transaction;
    Node* next;

    Node (Transaction val) {
        transaction = val;
        next = NULL;
    }
};

class TransactionStore {
public:
    Node *top;
    TransactionStore () {
        top = NULL;
    }

    void push (Transaction t) {
        if (t.checkDescription()) {     // check if description is greater than 20
            t.cutDescription();
        }

        if (t.getSaleAmount() >= 0) {

            float discount = 0;

            if (t.getSaleAmount() >= 1500) discount = 0.30;
            else if (t.getSaleAmount() >= 1000) discount = 0.15;
            else if (t.getSaleAmount() >= 500) discount = 0.05;

            if (discount > 0) {
                cout<<discount * 100 << " percent discount applied on "<< t.getDescription() << endl;
            }

            double amount = t.getSaleAmount() - (t.getSaleAmount() * discount);
            t.setSaleAmountAfterDiscount(amount);
        }

        Node *newtransaction = new Node (t);

        if (top == NULL) {
            top = newtransaction;
        } 
        else {
            newtransaction->next = top;
            top = newtransaction;
        }

        cout << "\nTransaction added successfully:\n";
        t.display();
    }

    void pop () {

        if (top == NULL) {
            cout << "Stack UnderFlow!\n";
            return;
        }

        cout << "Reversing transaction...\n";
        top->transaction.setTrasaction (top->transaction.getSaleAmount() * (-1));   // reversed
        top->transaction.setFlag (false);

        string description = top->transaction.getDescription() + " [REVERSED]";
        top->transaction.setDescription (description);

        top->transaction.display();

        Node *temp = top;
        top = top->next;
        delete temp;
    }

    ~TransactionStore () {
        while (top != NULL) {
            Node *temp = top;
            top = top->next;
            delete temp;
        }
    }
};


// this function is for checking which operator has high precedence: 
int checkPrecedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    else if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}
// check wheather it is a operator:
bool isOperator(char c) {
    if (c == '+' || c == '*'|| c == '-' ||  c == '/') {
        return true;
    }
    return false;
}
string infixToPostfix(string infix) {
    char arr[50]; // taking 50 size
    
    int top = -1;
    string postfix="";

    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        if ((ch >= '0' && ch <= '9') || ch == '.') {
            postfix += ch;
        }
        else if (ch == '(') {
            arr[++top] = ch;
        }
        else if (ch == ')') {
            postfix += ' ';
            while (top >= 0 && arr[top] != '(') {
                postfix+=arr[top--];
                postfix+=' ';
            }
            top--;
        }
        else if (isOperator(ch)) {
            postfix+=' ';
            while (top >= 0 && checkPrecedence(arr[top]) >= checkPrecedence(ch)) {
                postfix+=arr[top--];
                postfix+=' ';
            }
            arr[++top] = ch;
        }
    }
    while (top >= 0) {
        postfix += ' ';
        postfix += arr[top--];
    }
    return postfix;
}

double evaluatePostfix(string postfix) {
    double arr[50];
    int top = -1;
    string num = "";

    for (int i = 0; i < postfix.length(); i++) {
        char ch = postfix[i];
        if (ch == ' ') {
            if (num != "") {
                arr[++top] = stod(num);
                num = "";
            }
        }
        else if (isOperator(ch)) {
            double b = arr[top--];
            double a = arr[top--];
            double result = 0;

            if (ch == '+') {
                result = a + b;
            }
            else if (ch == '-') {
                result = a - b;
            }
            else if (ch == '*') {
                result = a * b;
            }
            else if (ch == '/') {
                result = a / b;
            }
            
            arr[++top] = result;
        }
        else 
        {
            num += ch;
        }
    }
    return arr[top];
}


int main()
{
    srand(time(0));

    Transaction transactions[7] = {
        Transaction(1200, "Sale: Blue Jacket", true),
        Transaction(450, "Sale: Cotton Socks", true),
        Transaction(-300, "Refund: Defective Shirt", false),
        Transaction(1700, "Sale: Leather Jacket", true),
        Transaction(600, "Sale: White Sneakers", true),
        Transaction(-500, "Refund: Damaged Bag", false),
        Transaction(2200, "Sale: Premium Watch", true)
    };

    TransactionStore store;
    bool used[7] = {false};

    int count = 0;
    while (count < 4) {
        int idx = rand() % 7;
        if (!used[idx]) {
            used[idx] = true;
            store.push(transactions[idx]);
            count++;
        }
    }

    cout << "\n\nReversing 2 transactions...\n";
    store.pop();
    store.pop();


    string infix = "(100+20)*0.9-5";
    cout << "Infix: " << infix << endl;

    string postfix = infixToPostfix(infix);
    cout << "Postfix: " << postfix << endl;

    double result = evaluatePostfix(postfix);
    cout << "Evaluated Result: " << result << endl;

    return 0;
}
