/*
 * Program  : 0/1 Knapsack (Dynamic Programming)
 * Subject  : Design and Analysis of Algorithms Lab
 * Category : Dynamic Programming
 * Complexity: O(n * capacity)
 *
 * Aim: Solve the 0/1 Knapsack problem optimally using Dynamic Programming.
 *      Each item can either be taken (1) or left (0) — no fractions.
 */

#include <stdio.h>

#define MAX_ITEMS    20
#define MAX_CAPACITY 1000

int dp[MAX_ITEMS + 1][MAX_CAPACITY + 1];

int max(int a, int b) { return a > b ? a : b; }

int main(void) {
    int num_items, capacity;
    printf("Enter number of items and knapsack capacity: ");
    scanf("%d %d", &num_items, &capacity);

    int weight[MAX_ITEMS], profit[MAX_ITEMS];
    printf("Enter weight and profit for each item:\n");
    for (int item = 0; item < num_items; item++) {
        printf("  Item %d: ", item + 1);
        scanf("%d %d", &weight[item], &profit[item]);
    }

    /*
     * Fill DP table.
     * dp[item][cap] = max profit using first 'item' items with 'cap' capacity.
     */
    for (int item = 1; item <= num_items; item++) {
        for (int cap = 0; cap <= capacity; cap++) {
            if (weight[item - 1] <= cap)
                /* Either skip this item or include it — take the better option */
                dp[item][cap] = max(dp[item - 1][cap],
                                    profit[item - 1] + dp[item - 1][cap - weight[item - 1]]);
            else
                /* Item too heavy for current capacity — skip it */
                dp[item][cap] = dp[item - 1][cap];
        }
    }

    printf("\nMaximum Profit = %d\n", dp[num_items][capacity]);

    /* Backtrack through the table to find which items were selected */
    printf("Items selected: ");
    int remaining_capacity = capacity;
    for (int item = num_items; item > 0; item--) {
        if (dp[item][remaining_capacity] != dp[item - 1][remaining_capacity]) {
            printf("Item%d(w=%d,p=%d) ", item, weight[item - 1], profit[item - 1]);
            remaining_capacity -= weight[item - 1];
        }
    }
    printf("\n");

    return 0;
}
