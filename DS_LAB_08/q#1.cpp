#include <bits/stdc++.h>
using namespace std;

class Student {
public:
    int score;
    string name;
    Student() {}
    Student(string s, int sc) {
        score = sc;
        name = s;
    }
};

class Node {
public:
    Student student;
    Node* next;
    Node(Student s) {
        student = s;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;
    Node *tail;

    LinkedList() { 
        head = NULL; 
    }
    void insertAtHead(Student val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
    void print() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->student.name << " " << temp->student.score << endl;
            temp = temp->next;
        }
    }

    void deleteAtPosition(int pos) {
        if (head == NULL) return;
        if (pos == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        for (int i = 0; current != NULL && i < pos - 1; i++) {
            current = current->next;
        }

        if (current == NULL || current->next == NULL) {
            return;
        }
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
    }

    int size() {
        int count = 0;
        Node* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

int getMax(Node* temp) {
    int maxi = 0;
    while (temp != NULL) {
        if (temp->student.score > maxi) {
            maxi = temp->student.score;
        }
        temp = temp->next;
    }
    return maxi;
}

void countSort(LinkedList* list, int exp) {
    int size = list->size();
    int count[10] = {0};
    Node* current = list->head;

    while (current != NULL) {
        int digit = (current->student.score / exp) % 10;
        count[digit]++;
        current = current->next;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i-1];
    }

    Student* output = new Student[size];
    current = list->head;
    for (int i = size - 1; i >= 0; i--) {
        int digit = (current->student.score / exp) % 10;
        output[count[digit] - 1] = current->student;
        count[digit]--;
        current = current->next;
    }

    current = list->head;
    int i = 0;
    while (current != NULL) {
        current->student = output[i++];
        current = current->next;
    }
    delete[] output;
}

void RadixSort(LinkedList* list) {
    int maxi = getMax(list->head);
    for (int exp = 1; maxi / exp > 0; exp *= 10) {
        countSort(list, exp);
    }    
}

int binarySearch(Student arr[], int n, string name, int score) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid].score == score && arr[mid].name == name){
            return mid;
        }
        else if (arr[mid].score < score) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}

void copyToArray(LinkedList& list, Student arr[]) {
    Node* temp = list.head;
    int i = 0;
    while (temp != NULL) {
        arr[i++] = temp->student;
        temp = temp->next;
    }
}

int main() 
{
    LinkedList list;
    list.insertAtHead(Student("Sara", 70));
    list.insertAtHead(Student("Sohail", 30));
    list.insertAtHead(Student("Ahmed", 20));
    list.insertAtHead(Student("Ayan", 90));
    list.insertAtHead(Student("Zameer", 60));
   
    cout << "\nBefore sorting:\n";
    list.print();

    RadixSort(&list);

    cout << "\nAfter sorting:\n";
    list.print();

    int n = list.size();
    Student* arr = new Student[n];
    copyToArray(list, arr);

    string name;
    int score;
    cout<<"\nEnter name of student to search: ";
    cin>>name;
    cout<<"Enter the score: ";
    cin>>score;

    int pos = binarySearch(arr, n, name, score);

    if (pos != -1) {
        cout<<"\nRecord found and deleted.\n";
        list.deleteAtPosition(pos);
    } 
    else 
    {
        cout << "\nRecord not found.\n";
    }

    cout << "\nUpdated List:\n";
    list.print();

    delete[] arr;
    return 0;

}
