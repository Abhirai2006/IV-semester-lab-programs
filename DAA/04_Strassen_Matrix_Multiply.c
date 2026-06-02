/*
 * Program  : Strassen's Matrix Multiplication
 * Subject  : Design and Analysis of Algorithms Lab
 * Category : Divide & Conquer
 * Complexity: O(n^2.807)
 *
 * Aim: Multiply two 2x2 matrices using Strassen's algorithm (7 multiplications
 *      instead of the standard 8).
 */

#include <stdio.h>

void printMatrix(int M[2][2], const char *label) {
    printf("%s:\n", label);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++)
            printf("%5d ", M[i][j]);
        printf("\n");
    }
}

int main(void) {
    int A[2][2], B[2][2], C[2][2];

    printf("Enter elements of Matrix A (2x2):\n");
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            scanf("%d", &A[i][j]);

    printf("Enter elements of Matrix B (2x2):\n");
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            scanf("%d", &B[i][j]);

    /* Strassen's 7 intermediate products */
    int M1 = (A[0][0] + A[1][1]) * (B[0][0] + B[1][1]);
    int M2 = (A[1][0] + A[1][1]) *  B[0][0];
    int M3 =  A[0][0]            * (B[0][1] - B[1][1]);
    int M4 =  A[1][1]            * (B[1][0] - B[0][0]);
    int M5 = (A[0][0] + A[0][1]) *  B[1][1];
    int M6 = (A[1][0] - A[0][0]) * (B[0][0] + B[0][1]);
    int M7 = (A[0][1] - A[1][1]) * (B[1][0] + B[1][1]);

    /* Assemble result matrix */
    C[0][0] = M1 + M4 - M5 + M7;
    C[0][1] = M3 + M5;
    C[1][0] = M2 + M4;
    C[1][1] = M1 - M2 + M3 + M6;

    printf("\n");
    printMatrix(A, "Matrix A");
    printf("\n");
    printMatrix(B, "Matrix B");
    printf("\n");
    printMatrix(C, "Product C = A x B");

    return 0;
}
