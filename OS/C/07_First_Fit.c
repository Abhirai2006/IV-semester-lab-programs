/*
 * Program  : Memory Allocation — First Fit
 * Subject  : Operating Systems Lab
 *
 * Description:
 *   In the First Fit strategy, each process is allocated to the FIRST
 *   memory block that is large enough to accommodate it.
 *
 *   Advantage  : Fast — stops scanning as soon as a fit is found.
 *   Disadvantage: Can leave many small unusable fragments at the start.
 *
 * Note:
 *   A process that has been allocated is marked with a sentinel value
 *   (ALLOCATED_MARKER) so it is not re-allocated to another block.
 */

#include <stdio.h>

#define MAX_BLOCKS    20
#define ALLOCATED_MARKER 99999  /* Sentinel: marks a process as already placed */

int main() {
    int num_blocks, num_processes;
    int block_size[MAX_BLOCKS];
    int process_size[MAX_BLOCKS];
    int i, j;

    /* --- Input Block Sizes --- */
    printf("Enter the number of memory blocks: ");
    scanf("%d", &num_blocks);

    for (i = 1; i <= num_blocks; i++) {
        printf("  Size of Block %d: ", i);
        scanf("%d", &block_size[i]);
    }

    /* --- Input Process Sizes --- */
    printf("\nEnter the number of processes: ");
    scanf("%d", &num_processes);

    for (i = 1; i <= num_processes; i++) {
        printf("  Size of Process %d: ", i);
        scanf("%d", &process_size[i]);
    }

    /* --- First Fit Allocation --- */
    printf("\n--- Allocation Results ---\n");

    for (i = 1; i <= num_blocks; i++) {
        for (j = 1; j <= num_processes; j++) {
            /* Skip already-allocated processes */
            if (process_size[j] == ALLOCATED_MARKER)
                continue;

            if (process_size[j] <= block_size[i]) {
                printf("Process %d (size %d) -> allocated to Block %d (size %d)\n",
                       j, process_size[j], i, block_size[i]);
                /* Mark this process as allocated */
                process_size[j] = ALLOCATED_MARKER;
                break;  /* Move to the next block */
            }
        }
    }

    /* --- Report Unallocated Processes --- */
    printf("\n--- Unallocated Processes ---\n");
    int any_unallocated = 0;
    for (j = 1; j <= num_processes; j++) {
        if (process_size[j] != ALLOCATED_MARKER) {
            printf("Process %d could not be allocated.\n", j);
            any_unallocated = 1;
        }
    }
    if (!any_unallocated)
        printf("All processes were successfully allocated.\n");

    return 0;
}
