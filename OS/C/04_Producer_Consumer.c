/*
 * Program  : Producer-Consumer Problem using Semaphores (Simulated)
 * Subject  : Operating Systems Lab
 *
 * Description:
 *   This program simulates the classic Producer-Consumer synchronization
 *   problem using integer variables to mimic semaphore behavior.
 *
 *   Semaphore variables:
 *     mutex : Binary semaphore — ensures mutual exclusion (0 = locked, 1 = free)
 *     full  : Counts the number of filled slots in the buffer
 *     empty : Counts the number of empty slots in the buffer
 *
 *   Buffer Capacity : BUFFER_SIZE (default 10)
 *
 * Note:
 *   This is a simplified simulation. Real semaphore-based programs use
 *   POSIX semaphores (sem_t) from <semaphore.h>.
 */

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 10

/* Simulated semaphore state */
int mutex = 1;           /* 1 = available, 0 = locked */
int full  = 0;           /* Number of items in buffer */
int empty = BUFFER_SIZE; /* Number of empty slots     */

int item_count = 0;      /* Tracks the current item value */

/* Simulates a producer: adds one item to the buffer */
void producer() {
    --mutex;         /* Lock (wait on mutex) */
    ++full;          /* One more filled slot */
    --empty;         /* One fewer empty slot */
    item_count++;
    printf("\nProducer produced item %d", item_count);
    ++mutex;         /* Unlock (signal mutex) */
}

/* Simulates a consumer: removes one item from the buffer */
void consumer() {
    --mutex;         /* Lock */
    --full;          /* One fewer filled slot */
    ++empty;         /* One more empty slot */
    printf("\nConsumer consumed item %d", item_count);
    item_count--;
    ++mutex;         /* Unlock */
}

int main() {
    int choice;

    printf("=== Producer-Consumer Problem Simulation ===");
    printf("\nBuffer Capacity: %d", BUFFER_SIZE);
    printf("\n\n1. Producer");
    printf("\n2. Consumer");
    printf("\n3. Exit\n");

    /* Run indefinitely until user selects Exit */
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (mutex == 1 && empty != 0) {
                    producer();
                } else if (empty == 0) {
                    printf("Buffer is FULL! Cannot produce.\n");
                    printf("-----------------------------------\n");
                } else {
                    printf("Mutex unavailable. Try again.");
                }
                break;

            case 2:
                if (mutex == 1 && full != 0) {
                    consumer();
                } else if (full == 0) {
                    printf("Buffer is EMPTY! Cannot consume.\n");
                    printf("-----------------------------------\n");
                } else {
                    printf("Mutex unavailable. Try again.");
                }
                break;

            case 3:
                printf("\nExiting simulation.\n");
                exit(0);

            default:
                printf("Invalid choice. Enter 1, 2, or 3.");
        }

        printf("\n[Status] Buffer: %d/%d | Empty: %d",
               full, BUFFER_SIZE, empty);
    }

    return 0;
}
