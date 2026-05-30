/*
 * Program  : Memory Management — Variable Partitions (MVT)
 * Subject  : Operating Systems Lab
 *
 * Description:
 *   In MVT (Multiprogramming with Variable-size Tasks), memory is allocated
 *   dynamically to each process — exactly as much as it needs.
 *   There are no fixed partitions, so internal fragmentation is eliminated.
 *
 *   External Fragmentation: Remaining memory after all allocations that
 *   cannot satisfy any further process request.
 */

#include <stdio.h>

#define MAX_PROCESSES 10

int main() {
    int total_memory;
    int process_size[MAX_PROCESSES];
    int num_processes = 0;
    int remaining_memory;
    char continue_input = 'y';
    int i;

    /* --- Input Total Memory --- */
    printf("\nEnter the total memory available (in Bytes): ");
    scanf("%d", &total_memory);

    remaining_memory = total_memory;

    /* --- Dynamically Allocate to Each Process --- */
    for (i = 0; continue_input == 'y'; i++, num_processes++) {
        printf("\nEnter memory required for Process %d (in Bytes): ", i + 1);
        scanf("%d", &process_size[i]);

        if (process_size[i] <= remaining_memory) {
            printf("Memory allocated for Process %d", i + 1);
            remaining_memory -= process_size[i];
        } else {
            printf("Not enough memory! Process %d cannot be allocated.", i + 1);
            num_processes++;  /* Count this process as encountered */
            break;
        }

        printf("\nDo you want to add another process? (y/n): ");
        scanf(" %c", &continue_input);
    }

    /* --- Allocation Summary Table --- */
    printf("\n\nTotal Memory Available : %d Bytes", total_memory);
    printf("\n\n%-12s %-20s\n", "Process", "Memory Allocated (Bytes)");
    printf("----------------------------------\n");

    for (i = 0; i < num_processes; i++) {
        printf("P%-11d %-20d\n", i + 1, process_size[i]);
    }

    printf("\n----------------------------------");
    printf("\nTotal Memory Allocated   : %d Bytes", total_memory - remaining_memory);
    printf("\nExternal Fragmentation   : %d Bytes\n", remaining_memory);

    return 0;
}
