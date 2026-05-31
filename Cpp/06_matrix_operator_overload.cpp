/*
 * Program  : Matrix Addition Using Operator Overloading
 * Author   : [Your Name]
 * Subject  : C++ Lab
 *
 * Description:
 *   Defines a Matrix class for a 2x2 matrix.
 *   Overloads the + operator to add two Matrix objects element-wise
 *   and return the resulting matrix.
 *
 * Concepts:
 *   - Operator overloading
 *   - 2D array as class data member
 */

#include <iostream>
#include <iomanip>
using namespace std;

#define ROWS 2
#define COLS 2

class Matrix {
private:
    int data[ROWS][COLS];

public:
    // Read matrix elements from user input
    void read(const string &label) {
        cout << "Enter elements of " << label << " (" << ROWS << "x" << COLS << "):\n";
        for (int i = 0; i < ROWS; i++)
            for (int j = 0; j < COLS; j++) {
                cout << "  [" << i << "][" << j << "]: ";
                cin >> data[i][j];
            }
    }

    // Overload + : adds two matrices element-wise
    Matrix operator+(const Matrix &other) const {
        Matrix result;
        for (int i = 0; i < ROWS; i++)
            for (int j = 0; j < COLS; j++)
                result.data[i][j] = data[i][j] + other.data[i][j];
        return result;
    }

    // Display matrix in grid format
    void display(const string &label) const {
        cout << label << ":\n";
        for (int i = 0; i < ROWS; i++) {
            cout << "  | ";
            for (int j = 0; j < COLS; j++)
                cout << setw(4) << data[i][j];
            cout << "  |\n";
        }
    }
};

int main() {
    Matrix m1, m2, m3;

    m1.read("Matrix A");
    cout << "\n";
    m2.read("Matrix B");

    m3 = m1 + m2;

    cout << "\n";
    m1.display("Matrix A");
    cout << "\n";
    m2.display("Matrix B");
    cout << "\n";
    m3.display("A + B");

    return 0;
}
