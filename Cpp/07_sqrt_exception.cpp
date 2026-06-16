// Program 7: Compute square root of a number with exception handling
// If the input is negative, my_sqrt() raises an exception.

#include <iostream>
#include <cmath>
using namespace std;

double my_sqrt(double num) {
    if (num < 0) {
        throw num;  // throw the negative number as exception
    }
    return sqrt(num);
}

int main() {
    double num, root;

    cout << "Enter a number: ";
    cin >> num;

    try {
        root = my_sqrt(num);
        cout << "Square root of " << num << " is: " << root << endl;
    }
    catch (double val) {
        cout << "Error: Cannot compute square root of a negative number (" << val << ")." << endl;
    }

    return 0;
}