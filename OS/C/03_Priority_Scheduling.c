
/*
 * Program  : Priority CPU Scheduling — Non-Preemptive
 * Subject  : Operating Systems Lab
 *
 * Description:
 *   Each process is assigned a priority number. The CPU is allocated to
 *   the process with the highest priority (lowest priority number = higher
 *   urgency in this implementation).
 *
 *   NOTE: To use "higher number = higher priority", change '>' to '<'
 *         in the sort condition below.
 *
 * Formulae:
 *   Waiting Time (WT)       = Sum of burst times of all preceding processes
 *   Turnaround Time (TAT)   = WT + Burst Time
 */

#include <stdio.h>

#define MAX_PROCESSES 20

int main() {
    int n, i, j, temp;
    float avg_waiting_time = 0, avg_turnaround_time = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int process_id[n];
    int burst_time[n];
    int priority[n];
    int waiting_time[n];
    int turnaround_time[n];

    /* --- Input --- */
    for (i = 0; i < n; i++) {
        process_id[i] = i + 1;
        printf("Enter Burst Time and Priority for P%d: ", i + 1);
        scanf("%d %d", &burst_time[i], &priority[i]);
    }

    /* --- Sort by Priority using Bubble Sort (lower number = higher priority) --- */
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (priority[j] > priority[j + 1]) {
                /* Swap priority values */
                temp           = priority[j];
                priority[j]    = priority[j + 1];
                priority[j + 1] = temp;

                /* Swap burst times to keep them aligned */
                temp             = burst_time[j];
                burst_time[j]    = burst_time[j + 1];
                burst_time[j + 1] = temp;

                /* Swap process IDs to keep them aligned */
                temp              = process_id[j];
                process_id[j]     = process_id[j + 1];
                process_id[j + 1] = temp;
            }
        }
    }

    /* --- Calculate Waiting Time --- */
    waiting_time[0] = 0;  /* Highest priority process waits 0 */
    for (i = 1; i < n; i++) {
        waiting_time[i] = waiting_time[i - 1] + burst_time[i - 1];
    }

    /* --- Calculate Turnaround Time and Averages --- */
    printf("\n%-8s %-10s %-12s %-14s %-15s\n",
           "Process", "Priority", "Burst Time", "Waiting Time", "Turnaround Time");
    printf("----------------------------------------------------------------\n");

    for (i = 0; i < n; i++) {
        turnaround_time[i]  = waiting_time[i] + burst_time[i];
        avg_waiting_time    += waiting_time[i];
        avg_turnaround_time += turnaround_time[i];

        printf("P%-10d %-10d %-12d %-14d %-15d\n",
               process_id[i],
               priority[i],
               burst_time[i],
               waiting_time[i],
               turnaround_time[i]);
    }

    printf("\nAverage Waiting Time    : %.2f", avg_waiting_time / n);
    printf("\nAverage Turnaround Time : %.2f\n", avg_turnaround_time / n);

    return 0;
}
