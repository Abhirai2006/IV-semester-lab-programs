/*
 * Program  : Memory Management — Fixed Partitions (MFT)
 * Subject  : Operating Systems Lab
 *
 * Description:
 *   In MFT (Multiprogramming with Fixed-size Tasks), total memory is divided
 *   into equal-sized fixed partitions. Each process is loaded into a partition.
 *
 *   Internal Fragmentation: wasted space within a partition (partition - process size)
 *   External Fragmentation: leftover memory not fitting any full partition
 *
 * Limitations:
 *   - Fixed block size may waste memory if processes are small.
 *   - Number of partitions is limited by total memory / block size.
 */

#include <stdio.h>

#define MAX_PROCESSES 10

int main() {
    int total_memory, block_size;
    int num_blocks, external_frag;
    int num_processes;
    int process_size[MAX_PROCESSES];
    int total_internal_frag = 0;
    int allocated_count = 0;
    int i;

    /* --- Input Memory Configuration --- */
    printf("Enter the total memory available (in Bytes): ");
    scanf("%d", &total_memory);

    printf("Enter the block size (in Bytes): ");
    scanf("%d", &block_size);

    num_blocks    = total_memory / block_size;
    external_frag = total_memory - (num_blocks * block_size);

    printf("\nTotal Partitions Created: %d", num_blocks);

    /* --- Input Process Sizes --- */
    printf("\nEnter the number of processes: ");
    scanf("%d", &num_processes);

    for (i = 0; i < num_processes; i++) {
        printf("Enter memory required for Process %d (in Bytes): ", i + 1);
        scanf("%d", &process_size[i]);
    }

    /* --- Allocation Table --- */
    printf("\n%-12s %-16s %-12s %-20s\n",
           "Process", "Memory Required", "Allocated", "Internal Fragmentation");
    printf("------------------------------------------------------------\n");

    for (i = 0; i < num_processes; i++) {
        if (allocated_count >= num_blocks) {
            printf("\nMemory is full. Remaining processes cannot be accommodated.");
            break;
        }

        printf("P%-11d %-16d ", i + 1, process_size[i]);

        if (process_size[i] > block_size) {
            printf("%-12s %-20s\n", "NO", "---");
        } else {
            int internal_frag = block_size - process_size[i];
            printf("%-12s %-20d\n", "YES", internal_frag);
            total_internal_frag += internal_frag;
            allocated_count++;
        }
    }

    /* --- Summary --- */
    printf("\n------------------------------------------------------------");
    printf("\nTotal Internal Fragmentation : %d Bytes", total_internal_frag);
    printf("\nTotal External Fragmentation : %d Bytes\n", external_frag);

    return 0;
}
