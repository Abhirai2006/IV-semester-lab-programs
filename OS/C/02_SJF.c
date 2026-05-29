/*
 * Program  : Shortest Job First (SJF) CPU Scheduling — Non-Preemptive
 * Author   : [Your Name]
 * Subject  : Operating Systems Lab
 *
 * Description:
 *   SJF selects the process with the smallest burst time next.
 *   This implementation sorts processes by burst time (ascending)
 *   before calculating scheduling metrics.
 *
 * Formulae:
 *   Turnaround Time (TAT) = Completion Time - Arrival Time (assumed 0 here)
 *   Waiting Time (WT)     = TAT - Burst Time
 */

#include <stdio.h>

#define MAX_PROCESSES 20

int main() {
    int n;
    int process_id[MAX_PROCESSES];
    int burst_time[MAX_PROCESSES];
    int waiting_time[MAX_PROCESSES];
    int turnaround_time[MAX_PROCESSES];

    float avg_waiting_time = 0, avg_turnaround_time = 0;
    int i, j, temp_bt, temp_pid;

    /* --- Input --- */
    printf("\nEnter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        process_id[i] = i + 1;
        printf("Enter Burst Time for P%d: ", i + 1);
        scanf("%d", &burst_time[i]);
    }

    /* --- Sort by Burst Time (Bubble Sort, ascending) --- */
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (burst_time[i] > burst_time[j]) {
                /* Swap burst times */
                temp_bt        = burst_time[i];
                burst_time[i]  = burst_time[j];
                burst_time[j]  = temp_bt;

                /* Keep process IDs in sync */
                temp_pid       = process_id[i];
                process_id[i]  = process_id[j];
                process_id[j]  = temp_pid;
            }
        }
    }

    /* --- Calculate Waiting and Turnaround Times --- */
    /* First process has no waiting time */
    waiting_time[0]    = 0;
    turnaround_time[0] = burst_time[0];
    avg_waiting_time    = 0;
    avg_turnaround_time = burst_time[0];

    for (i = 1; i < n; i++) {
        waiting_time[i]    = waiting_time[i - 1] + burst_time[i - 1];
        turnaround_time[i] = waiting_time[i] + burst_time[i];

        avg_waiting_time    += waiting_time[i];
        avg_turnaround_time += turnaround_time[i];
    }

    /* --- Output Table --- */
    printf("\n%-09s %-12s %-15s %-15s\n",
           "Process", "Burst Time", "Waiting Time", "Turnaround Time");
    printf("-------------------------------------------------------\n");

    for (i = 0; i < n; i++) {
        printf("P%-12d %-12d %-15d %-15d\n",
               process_id[i],
               burst_time[i],
               waiting_time[i],
               turnaround_time[i]);
    }

    printf("\nAverage Waiting Time    : %.2f", avg_waiting_time / n);
    printf("\nAverage Turnaround Time : %.2f\n", avg_turnaround_time / n);

    return 0;
}
