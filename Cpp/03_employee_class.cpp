/*
 * Program  : Employee Class with Salary Computation
 * Author   : [Your Name]
 * Subject  : C++ Lab
 *
 * Description:
 *   Defines an EMPLOYEE class with the following data members:
 *     - Employee Number
 *     - Employee Name
 *     - Basic Salary
 *     - DA  (Dearness Allowance)   = 40% of Basic
 *     - IT  (Income Tax deduction) = 10% of Basic
 *     - Net Salary = Basic + DA - IT
 *
 *   Member functions: getDetails() to input, calcSalary() to compute,
 *   and printDetails() to display.
 */

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Employee {
private:
    int    emp_no;
    string emp_name;
    float  basic;
    float  da;          // Dearness Allowance
    float  it;          // Income Tax
    float  net_salary;

public:
    // Input employee details
    void getDetails() {
        cout << "Enter Employee Number : "; cin >> emp_no;
        cin.ignore();
        cout << "Enter Employee Name   : "; getline(cin, emp_name);
        cout << "Enter Basic Salary    : "; cin >> basic;
    }

    // Calculate DA, IT, and Net Salary
    void calcSalary() {
        da         = 0.40f * basic;   // DA = 40% of basic
        it         = 0.10f * basic;   // IT = 10% of basic
        net_salary = basic + da - it;
    }

    // Display all employee data
    void printDetails() const {
        cout << fixed << setprecision(2);
        cout << "\n--- Employee Details ---";
        cout << "\nEmployee Number : " << emp_no;
        cout << "\nEmployee Name   : " << emp_name;
        cout << "\nBasic Salary    : " << basic;
        cout << "\nDA (40%)        : " << da;
        cout << "\nIT (10%)        : " << it;
        cout << "\nNet Salary      : " << net_salary << endl;
    }
};

int main() {
    Employee emp;
    emp.getDetails();
    emp.calcSalary();
    emp.printDetails();
    return 0;
}
