/*
 * Program  : First Come First Serve (FCFS) CPU Scheduling
 * Subject  : Operating Systems Lab
 *
 * Description:
 *   FCFS is the simplest CPU scheduling algorithm. Processes are executed
 *   in the order they arrive. No preemption occurs.
 *
 * Formulae:
 *   Completion Time (CT)    = Time at which process finishes execution
 *   Turnaround Time (TAT)   = CT - Arrival Time
 *   Waiting Time (WT)       = TAT - Burst Time
 */

#include <stdio.h>

#define MAX_PROCESSES 10

int main() {
    int n;
    int arrival_time[MAX_PROCESSES];
    int burst_time[MAX_PROCESSES];
    int waiting_time[MAX_PROCESSES];
    int turnaround_time[MAX_PROCESSES];
    int completion_time[MAX_PROCESSES];

    float avg_waiting_time = 0, avg_turnaround_time = 0;
    int i, total_time = 0;

    /* --- Input --- */
    printf("Enter the total number of processes: ");
    scanf("%d", &n);

    printf("\nEnter Arrival Time and Burst Time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("  Process P%d -> Arrival Time: ", i + 1);
        scanf("%d", &arrival_time[i]);
        printf("  Process P%d -> Burst Time  : ", i + 1);
        scanf("%d", &burst_time[i]);
    }

    /* --- Calculate Completion, Turnaround, and Waiting Times --- */
    for (i = 0; i < n; i++) {
        /* CT: accumulate total time; if CPU was idle, jump to arrival time */
        if (total_time < arrival_time[i])
            total_time = arrival_time[i];

        total_time += burst_time[i];
        completion_time[i]   = total_time;
        turnaround_time[i]   = completion_time[i] - arrival_time[i];
        waiting_time[i]      = turnaround_time[i] - burst_time[i];

        avg_turnaround_time += turnaround_time[i];
        avg_waiting_time    += waiting_time[i];
    }

    /* --- Output Table --- */
    printf("\n%-10s %-15s %-12s %-15s %-15s %-10s\n",
           "Process", "Arrival Time", "Burst Time",
           "Completion", "Turnaround", "Waiting");
    printf("--------------------------------------------------------------------------------\n");

    for (i = 0; i < n; i++) {
        printf("%-10d %-15d %-12d %-15d %-15d %-10d\n",
               i + 1,
               arrival_time[i],
               burst_time[i],
               completion_time[i],
               turnaround_time[i],
               waiting_time[i]);
    }

    printf("\nAverage Turnaround Time : %.2f", avg_turnaround_time / n);
    printf("\nAverage Waiting Time    : %.2f\n", avg_waiting_time / n);

    return 0;
}
