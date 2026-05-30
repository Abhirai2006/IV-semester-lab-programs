/*
 * Program  : Memory Allocation — Worst Fit
 * Subject  : Operating Systems Lab
 *
 * Description:
 *   In the Worst Fit strategy, each process is allocated to the LARGEST
 *   available block. The idea is that allocating from the largest block
 *   leaves a large remaining fragment, which may be usable by future processes.
 *
 *   Advantage  : Remaining fragments tend to be large enough to be reused.
 *   Disadvantage: Can quickly exhaust large blocks, hurting large-process requests.
 */

#include <stdio.h>

#define MAX_SIZE 25

int main() {
    int num_blocks, num_files;

    /* Initialize to 0 to prevent garbage output for unallocated entries */
    int block_size[MAX_SIZE]  = {0};
    int file_size[MAX_SIZE]   = {0};
    int fragment[MAX_SIZE]    = {0};
    int block_used[MAX_SIZE];   /* 1 = allocated, 0 = free */
    int fit_block[MAX_SIZE];    /* Which block each file was assigned to */

    int i, j;
    int temp_diff;
    int largest_gap;            /* Tracks the maximum leftover for worst fit */

    /* Initialize tracking arrays */
    for (i = 0; i < MAX_SIZE; i++) {
        block_used[i] = 0;
        fit_block[i]  = 0;
    }

    /* --- Input --- */
    printf("\nEnter the number of blocks: ");
    scanf("%d", &num_blocks);
    printf("Enter the number of files: ");
    scanf("%d", &num_files);

    printf("\nEnter the size of each block:\n");
    for (i = 1; i <= num_blocks; i++) {
        printf("  Block %d: ", i);
        scanf("%d", &block_size[i]);
    }

    printf("Enter the size of each file:\n");
    for (i = 1; i <= num_files; i++) {
        printf("  File %d: ", i);
        scanf("%d", &file_size[i]);
    }

    /* --- Worst Fit Allocation --- */
    for (i = 1; i <= num_files; i++) {
        largest_gap = -1;  /* -1 safely handles exact fits (fragment = 0) */

        for (j = 1; j <= num_blocks; j++) {
            if (block_used[j] == 1)
                continue;  /* Skip already-used blocks */

            temp_diff = block_size[j] - file_size[i];

            /* Valid fit: block is large enough AND is the worst (largest gap) so far */
            if (temp_diff >= 0 && temp_diff > largest_gap) {
                fit_block[i] = j;
                largest_gap  = temp_diff;
            }
        }

        if (largest_gap != -1) {
            fragment[i]              = largest_gap;
            block_used[fit_block[i]] = 1;  /* Mark block as used */
        }
    }

    /* --- Output Table --- */
    printf("\n%-10s %-12s %-14s %-12s %-12s\n",
           "File No", "File Size", "Block No", "Block Size", "Fragment");
    printf("-------------------------------------------------------------\n");

    for (i = 1; i <= num_files; i++) {
        if (fit_block[i] != 0) {
            printf("%-10d %-12d %-14d %-12d %-12d\n",
                   i, file_size[i], fit_block[i],
                   block_size[fit_block[i]], fragment[i]);
        } else {
            printf("%-10d %-12d Not Allocated\n", i, file_size[i]);
        }
    }

    return 0;
}
