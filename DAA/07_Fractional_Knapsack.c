/*
 * Program  : Fractional Knapsack (Greedy)
 * Subject  : Design and Analysis of Algorithms Lab
 * Category : Greedy
 * Complexity: O(n log n)
 *
 * Aim: Maximise total profit by selecting items (or fractions thereof)
 *      to fill a knapsack of given capacity.
 */

#include <stdio.h>

typedef struct {
    int   weight;
    int   profit;
    float value_density;  /* profit per unit weight = profit / weight */
} Item;

/* Sort items descending by value density (bubble sort) */
void sortByValueDensity(Item items[], int num_items) {
    for (int i = 0; i < num_items - 1; i++) {
        for (int j = i + 1; j < num_items; j++) {
            if (items[i].value_density < items[j].value_density) {
                Item temp = items[i];
                items[i]  = items[j];
                items[j]  = temp;
            }
        }
    }
}

int main(void) {
    int num_items, capacity;
    printf("Enter number of items and knapsack capacity: ");
    scanf("%d %d", &num_items, &capacity);

    Item items[20];
    printf("Enter weight and profit for each item:\n");
    for (int i = 0; i < num_items; i++) {
        scanf("%d %d", &items[i].weight, &items[i].profit);
        items[i].value_density = (float)items[i].profit / items[i].weight;
    }

    sortByValueDensity(items, num_items);

    float total_profit    = 0.0f;
    int   remaining_space = capacity;

    printf("\nItems selected:\n");
    for (int i = 0; i < num_items && remaining_space > 0; i++) {
        if (items[i].weight <= remaining_space) {
            /* Take the whole item */
            printf("  Item (w=%d, p=%d) — taken fully\n",
                   items[i].weight, items[i].profit);
            total_profit    += items[i].profit;
            remaining_space -= items[i].weight;
        } else {
            /* Take the fraction that fills the remaining space */
            float fraction = (float)remaining_space / items[i].weight;
            printf("  Item (w=%d, p=%d) — taken %.2f fraction\n",
                   items[i].weight, items[i].profit, fraction);
            total_profit   += items[i].profit * fraction;
            remaining_space = 0;
        }
    }

    printf("Maximum Profit = %.2f\n", total_profit);
    return 0;
}
