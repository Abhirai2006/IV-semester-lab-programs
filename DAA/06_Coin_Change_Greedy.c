/*
 * Program  : Coin Change Problem (Greedy)
 * Subject  : Design and Analysis of Algorithms Lab
 * Category : Greedy
 * Complexity: O(n) for fixed denominations
 *
 * Aim: Find the minimum number of coins needed to make a given amount
 *      using a greedy strategy (largest denomination first).
 *
 * Note: Greedy is optimal ONLY for canonical coin systems (standard currency).
 *       For arbitrary denominations, use Dynamic Programming (Program 12).
 */

#include <stdio.h>

int main(void) {
    int denominations[] = {100, 50, 20, 10, 5, 2, 1};
    int num_denominations = 7;
    int amount, total_coins = 0;

    printf("Enter amount: ");
    scanf("%d", &amount);

    printf("Coins used: ");
    for (int denom_idx = 0; denom_idx < num_denominations; denom_idx++) {
        while (amount >= denominations[denom_idx]) {
            printf("%d ", denominations[denom_idx]);
            amount      -= denominations[denom_idx];
            total_coins++;
        }
    }

    printf("\nTotal coins used: %d\n", total_coins);

    if (amount != 0)
        printf("Warning: exact change not possible with given denominations.\n");

    return 0;
}
