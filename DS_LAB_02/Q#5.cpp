#include<bits/stdc++.h>
using namespace std;

int main()
{
    int rows = 4;
    int courses[4]={3,4,2,1}; 

    double** gpas = new double*[rows];

    for (int i = 0; i < rows; i++) {
        gpas[i] = new double[courses[i]];
    }
    string deptNames[4] = {"SE","AI","CS","DS"};
    cout << "\n---------- Enter Each Core GPA -----------\n";

    for (int i = 0; i < rows; i++) {
        cout << deptNames[i] << " Department:\n";
        for (int j = 0; j < courses[i]; j++) {
            cout<<"  Enter GPA for Course "<<j+1<<": ";
            cin>>gpas[i][j];
        }
    }

    cout << "\n---------- GPA Records -----------\n";
    for (int i=0;i<rows;i++) {
        cout << deptNames[i] << ": ";

        for (int j = 0; j < courses[i]; j++){

            cout<< fixed <<setprecision(2)<<gpas[i][j] << "  ";
        }
        cout << endl;
    }

    for (int i = 0; i < rows; i++) {
        delete[] gpas[i];
    }
    delete[] gpas;
    
    return 0;
}
