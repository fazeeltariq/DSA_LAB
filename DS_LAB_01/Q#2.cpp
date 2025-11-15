#include<iostream>
#include<cstring>
using namespace std;

class Exam{
    private:
    char *name;
    char *date;
    int score;

    public:

    Exam () {
    name = nullptr;
    date = nullptr;
    score = 0;
    }

    Exam(const char *newname ,const char *newdate, int score){
      name = new char [strlen(newname)+1];
      strcpy(name,newname);
      date = new char [strlen(newdate)+1];
      strcpy(date,newdate);
      this->score = score;
    }

   // Copy constructor (commented out to demonstrate shallow copy issues)

    // Exam (const Exam& other){
    //     name = new char[strlen(other.name)+1];
    //     strcpy (name, other.name);
    //     date = new char[strlen(other.date)+1];
    //     strcpy (date, other.date);
    // }

    // Exam& operator=(const Exam& other) {
    //     if (this != &other) { 
    //         delete[] name; 
    //         name = new char[strlen(other.name) + 1];
    //         strcpy(name, other.name);
    //         delete[] date;
    //         date = new char[strlen(other.date)+1];
    //         strcpy(date,other.date);
    //     }
    //     return *this;
    // }

    void setName(char *newname){
        delete[] name;
        name = new char[strlen(newname)+1];
        strcpy(name,newname);
    }

    void setDate(char *newdate){
        delete[] date;
        date = new char[strlen(newdate)+1];
        strcpy(date,newdate);
    }

    void setScore (int score){
        this->score = score;
    }

    void displayDetails(){
        cout << "\nExam name: "<<name;
        cout << "\nExam Date: "<<date;
        cout << "\nExam score: "<<score;
        cout << "\n";
    }

    ~Exam() {
        delete[] date;
        delete[] name;
    }
};

int main()
{
    Exam exam1 ("DSA","19-09-2020",100);
    Exam exam2 ("TOA","1-3-2025",100);
    Exam exam3 ("OOP","30-05-2024",100);

    cout << "\nExam # 1 Details: ";
    exam1.displayDetails();
    cout << "\nExam # 2 Details: ";
    exam2.displayDetails();
    cout << "\nExam # 3 Details: ";
    exam3.displayDetails();

    // If we use the assignment operator here (exam2 = exam3),
    // both objects will share the same memory (shallow copy).
    // Changing one object will also change the other.
    // This happens because the copy constructor and assignment operator
    // are not defined (default shallow copy is used).

    Exam exam4 = exam1;   // Shallow copy happens here
    exam4.displayDetails();

    // it will change names of both Exam1 and Exam4.
    exam1.setName("PF");        
    exam4.displayDetails();
}