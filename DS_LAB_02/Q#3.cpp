#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
    int marks[5];
    Student()
    {
        for (int i = 0; i < 5; i++)
        {
            marks[i] = 0;
        }
    }
};

int main()
{
    int noofDepartments;
    cout << "\nEnter no of Departments: ";
    cin >> noofDepartments;

    int *noofStudents = new int[noofDepartments];
    Student **students = new Student *[noofDepartments];

    for (int i = 0; i < noofDepartments; i++)
    {
        cout << "\nEnter the No of students in Department " << i + 1 << ": ";
        cin >> noofStudents[i];
        students[i] = new Student[noofStudents[i]];
    }

    cout << "\nEnter the marks for Students of each Department:\n";

    for (int i = 0; i < noofDepartments; i++)
    {
        cout << "\n-------- Department " << i + 1 << " ----------\n";
        for (int j = 0; j < noofStudents[i]; j++)
        {
            cout << "Enter marks for Student " << j + 1 << " (5 subjects): ";
            for (int k = 0; k < 5; k++)
            {
                cin >> students[i][j].marks[k];
            }
        }
    }

    cout << "\n----------- Marks Record --------------\n";

    for (int i = 0; i < noofDepartments; i++)
    {
        cout << "Department " << i + 1 << ":\n";
        for (int j = 0; j < noofStudents[i]; j++)
        {
            cout << " Student " << j + 1 << ": ";
            for (int k = 0; k < 5; k++)
            {
                cout << students[i][j].marks[k] << " ";
            }
            cout << endl;
        }
    }
    cout << "\n---------- Department-wise Statistics -------------\n";
    for (int i = 0; i < noofDepartments; i++)
    {
        int highest = INT_MIN;
        int lowest = INT_MAX;
        double sum = 0;
        int totalmarks = 0;

        cout << "\n----------Department-" << i + 1 << " Statistics--------- \n";

        for (int j = 0; j < noofStudents[i]; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                int mark = students[i][j].marks[k];
                highest = max(highest, mark);
                lowest = min(lowest, mark);
                sum += mark;
                totalmarks++;
            }
        }
        double avg = sum / totalmarks;

        cout << "\nDepartment " << i + 1 << " Results:";
        cout << "\n  Highest Mark = " << highest;
        cout << "\n  Lowest Mark  = " << lowest;
        cout << "\n  Average Mark = " << fixed << setprecision(2) << avg << endl;
    }


    for (int i = 0; i < noofDepartments; i++)
    {
        delete[] students[i];
    }
    delete[] students;
    delete[] noofStudents;

    return 0;
}
