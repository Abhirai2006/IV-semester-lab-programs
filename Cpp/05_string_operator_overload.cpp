/*
 * Program  : String Class with Operator Overloading (== and +)
 * Subject  : C++ Lab
 *
 * Description:
 *   Defines a custom String class that wraps a C-string.
 *   Overloads:
 *     ==  to compare two strings (returns true if equal)
 *     +   to concatenate two strings (returns a new String)
 *
 * Concepts:
 *   - Operator overloading
 *   - C-string manipulation (strcpy, strcat, strcmp, strlen)
 */

#include <iostream>
#include <cstring>
using namespace std;

class String {
private:
    char str[100];

public:
    // Default constructor
    String() { str[0] = '\0'; }

    // Parameterized constructor
    String(const char* s) { strcpy(str, s); }

    // Overload == : returns true if both strings are equal
    bool operator==(const String &other) const {
        return strcmp(str, other.str) == 0;
    }

    // Overload + : returns a new String that is the concatenation
    String operator+(const String &other) const {
        String result;
        strcpy(result.str, str);
        strcat(result.str, other.str);
        return result;
    }

    void display() const { cout << str; }
};

int main() {
    char input1[100], input2[100];

    cout << "Enter String 1: "; cin >> input1;
    cout << "Enter String 2: "; cin >> input2;

    String s1(input1), s2(input2);
    String s3 = s1 + s2;

    cout << "\nString 1      : "; s1.display();
    cout << "\nString 2      : "; s2.display();
    cout << "\nConcatenated  : "; s3.display();
    cout << "\nAre they equal? " << (s1 == s2 ? "Yes" : "No") << endl;

    return 0;
}
