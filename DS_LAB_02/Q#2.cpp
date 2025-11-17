#include <bits/stdc++.h>
using namespace std;

int main()
{
    int rows = 5, cols = 4;
    int** studentData = new int*[rows];
    int totalmarks[5] = {0,0,0,0,0};

    int highestMarks = INT_MIN;
    int studentno = -1;

    for (int i = 0; i < rows; i++) {
        studentData[i] = new int[cols];
    }

    cout << "\n---------- Enter the Student Details ------------\n";

    for (int i = 0; i < rows; i++) {

        cout <<"\nEnter Student "<< i + 1  << " \n";
        for (int j = 0; j < cols; j++) {

            cout <<"   Subject "<< j+1 <<" marks: ";

            cin >> studentData[i][j];
            totalmarks[i] += studentData[i][j];
        }
        if (totalmarks[i] > highestMarks) {
            highestMarks = totalmarks[i];
            studentno = i;
        }
    }
    cout << "\nDisplaying the total marks of each student:\n";
    for (int i = 0; i < rows; i++) {
        cout<< "Student "<< i+1 << " total marks: "<<totalmarks[i]<<endl;
    }

    cout << "\nDisplaying the Average marks of each student:\n";

    for (int i = 0; i < rows; i++) {
        cout << "Student "<< i+1 <<" average marks: "<< totalmarks[i]/4.0<< endl;
    }

    cout << "\nStudent " << studentno + 1 << " has highest marks = " <<highestMarks << endl;

    for (int i = 0;i < rows; i++) {
        delete[] studentData[i];
    }
    delete[] studentData;

    return 0;
}
