/*
 * Program  : Display Student Names, Roll Numbers, and Grades
 * Subject  : C++ Lab
 *
 * Description:
 *   Defines a Student class with data members: name, roll_no, grade.
 *   Creates an array of 3 Student objects, reads their details,
 *   and displays them in a formatted table.
 */

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Student {
private:
    string name;
    int    roll_no;
    char   grade;

public:
    // Input student details
    void getDetails(int student_num) {
        cout << "\nStudent " << student_num << ":\n";
        cout << "  Name    : "; cin.ignore(); getline(cin, name);
        cout << "  Roll No : "; cin >> roll_no;
        cout << "  Grade   : "; cin >> grade;
    }

    // Display one row of the table
    void display() const {
        cout << left
             << setw(20) << name
             << setw(12) << roll_no
             << setw(8)  << grade
             << "\n";
    }
};

int main() {
    const int NUM_STUDENTS = 3;
    Student students[NUM_STUDENTS];

    // Input
    cout << "Enter details for " << NUM_STUDENTS << " students:";
    for (int i = 0; i < NUM_STUDENTS; i++)
        students[i].getDetails(i + 1);

    // Output table
    cout << "\n" << left
         << setw(20) << "Name"
         << setw(12) << "Roll No"
         << setw(8)  << "Grade" << "\n";
    cout << string(40, '-') << "\n";

    for (int i = 0; i < NUM_STUDENTS; i++)
        students[i].display();

    return 0;
}
