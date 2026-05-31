/*
 * Program  : Addition of Two Complex Numbers Using Friend Function
 * Author   : [Your Name]
 * Subject  : C++ Lab
 *
 * Description:
 *   A Complex class stores real and imaginary parts.
 *   A constructor initializes the data members.
 *   A friend function 'addComplex' accesses private members of
 *   two Complex objects to compute their sum.
 *
 * Concepts:
 *   - Constructor for initialization
 *   - Friend function (can access private members of the class)
 */

#include <iostream>
using namespace std;

class Complex {
private:
    float real;
    float imag;

public:
    // Constructor to initialize real and imaginary parts
    Complex(float r = 0, float i = 0) : real(r), imag(i) {}

    // Friend function: not a member, but has access to private data
    friend Complex addComplex(Complex c1, Complex c2);

    void display() const {
        if (imag >= 0)
            cout << real << " + " << imag << "i";
        else
            cout << real << " - " << -imag << "i";
    }
};

// Friend function definition
Complex addComplex(Complex c1, Complex c2) {
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

int main() {
    float r1, i1, r2, i2;

    cout << "Enter real and imaginary parts of Complex 1: ";
    cin >> r1 >> i1;
    cout << "Enter real and imaginary parts of Complex 2: ";
    cin >> r2 >> i2;

    Complex c1(r1, i1), c2(r2, i2);
    Complex result = addComplex(c1, c2);

    cout << "\nC1     = "; c1.display();
    cout << "\nC2     = "; c2.display();
    cout << "\nC1 + C2 = "; result.display();
    cout << endl;

    return 0;
}
