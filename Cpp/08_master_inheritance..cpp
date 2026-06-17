// Program 8: Class network diagram — Person, Account, Admi, Master
// Demonstrates multiple inheritance with virtual base class.
//
// Hierarchy:
//   Person (Name, Code)
//     ├── Account (Pay)    [virtual public Person]
//     └── Admi   (Experience) [virtual public Person]
//             └── Master (Name, Code, Experience, Pay)

#include <iostream>
#include <cstring>
using namespace std;

// Base class: Person
class Person {
protected:
    char name[20];
    int  code;

public:
    void get_per(int c, const char* s) {
        code = c;
        strcpy(name, s);
    }

    void put_per() {
        cout << "\nCode : " << code;
        cout << "\nName : " << name;
    }
};

// Derived class: Account (virtually inherits Person)
class Account : virtual public Person {
protected:
    float pay;

public:
    void get_pay(float p) {
        pay = p;
    }

    void put_pay() {
        cout << "\nPay amount : " << pay;
    }
};

// Derived class: Admi (virtually inherits Person)
class Admi : virtual public Person {
protected:
    int exp;

public:
    void get_exp(int e) {
        exp = e;
    }

    void put_exp() {
        cout << "\nExperience : " << exp << " years";
    }
};

// Final derived class: Master (inherits Account and Admi)
class Master : public Account, public Admi {
public:
    void display() {
        put_per();
        put_pay();
        put_exp();
        cout << endl;
    }
};

int main() {
    Master m;

    // Set data
    m.get_per(111, "Piyush");
    m.get_pay(501.50);
    m.get_exp(2);

    cout << "--- Master Object Information ---";
    m.display();

    // Update data
    cout << "\nUpdating information..." << endl;
    m.get_per(222, "Abhirai");
    m.get_pay(750.00);
    m.get_exp(5);

    cout << "--- Updated Master Object Information ---";
    m.display();

    return 0;
}