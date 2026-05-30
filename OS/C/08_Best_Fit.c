/*
 * Program  : Memory Allocation — Best Fit
 * Subject  : Operating Systems Lab
 *
 * Description:
 *   In the Best Fit strategy, each process is allocated to the SMALLEST
 *   block that is still large enough to accommodate it.
 *
 *   Advantage  : Minimizes wasted space (internal fragmentation) per allocation.
 *   Disadvantage: Slower — must scan all blocks. Leaves many tiny unusable gaps.
 */

#include <stdio.h>

#define MAX_SIZE 25

int main() {
    int num_blocks, num_processes;
    int block_size[MAX_SIZE];
    int process_size[MAX_SIZE];
    int fragment[MAX_SIZE];     /* Fragmentation for each process */
    int block_used[MAX_SIZE];   /* 1 = block already allocated, 0 = free */
    int fit_block[MAX_SIZE];    /* Which block each process was assigned to */

    int i, j;
    int temp_diff;
    int smallest_gap;           /* Tracks the minimum leftover for best fit */

    /* Initialize arrays */
    static int zero_init[MAX_SIZE];
    for (i = 0; i < MAX_SIZE; i++) {
        block_used[i] = 0;
        fit_block[i]  = 0;
        fragment[i]   = 0;
    }

    /* --- Input --- */
    printf("\nEnter the number of blocks: ");
    scanf("%d", &num_blocks);
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    printf("\nEnter the size of each block:\n");
    for (i = 1; i <= num_blocks; i++) {
        printf("  Block %d: ", i);
        scanf("%d", &block_size[i]);
    }

    printf("Enter the size of each process:\n");
    for (i = 1; i <= num_processes; i++) {
        printf("  Process %d: ", i);
        scanf("%d", &process_size[i]);
    }

    /* --- Best Fit Allocation --- */
    for (i = 1; i <= num_processes; i++) {
        smallest_gap = 10000;  /* Large initial value */

        for (j = 1; j <= num_blocks; j++) {
            if (block_used[j] == 1)
                continue;  /* Block already taken */

            temp_diff = block_size[j] - process_size[i];

            /* Valid fit: block is large enough AND is the best (smallest gap) so far */
            if (temp_diff >= 0 && temp_diff < smallest_gap) {
                fit_block[i]  = j;
                smallest_gap  = temp_diff;
            }
        }

        if (fit_block[i] != 0) {
            fragment[i]          = smallest_gap;
            block_used[fit_block[i]] = 1;  /* Mark block as used */
        }
    }

    /* --- Output Table --- */
    printf("\n%-12s %-14s %-14s %-12s %-12s\n",
           "Process", "Process Size", "Block No", "Block Size", "Fragment");
    printf("-----------------------------------------------------------------\n");

    for (i = 1; i <= num_processes; i++) {
        if (fit_block[i] != 0) {
            printf("%-12d %-14d %-14d %-12d %-12d\n",
                   i, process_size[i], fit_block[i],
                   block_size[fit_block[i]], fragment[i]);
        } else {
            printf("%-12d %-14d Not Allocated\n", i, process_size[i]);
        }
    }

    return 0;
}
