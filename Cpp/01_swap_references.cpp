/*
 * Program  : Swap Two Integers Using Reference Variables
 * Subject  : C++ Lab
 *
 * Description:
 *   Demonstrates pass-by-reference in C++.
 *   Unlike pass-by-value, changes made inside the function
 *   directly affect the original variables in the caller.
 */

#include <iostream>
using namespace std;

// References (&) make 'a' and 'b' aliases for the caller's variables
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x, y;
    cout << "Enter two integers: ";
    cin >> x >> y;

    cout << "\nBefore swap: x = " << x << ", y = " << y;
    swap(x, y);
    cout << "\nAfter swap : x = " << x << ", y = " << y << endl;

    return 0;
}
