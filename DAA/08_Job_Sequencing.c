/*
 * Program  : Job Sequencing with Deadlines (Greedy)
 * Subject  : Design and Analysis of Algorithms Lab
 * Category : Greedy
 * Complexity: O(n²)
 *
 * Aim: Schedule jobs to maximise total profit where each job has a deadline
 *      and a profit earned only if completed on time (1 unit of time per job).
 */

#include <stdio.h>

typedef struct {
    int job_id;
    int deadline;
    int profit;
} Job;

/* Sort jobs descending by profit (bubble sort) */
void sortByProfit(Job jobs[], int num_jobs) {
    for (int i = 0; i < num_jobs - 1; i++) {
        for (int j = i + 1; j < num_jobs; j++) {
            if (jobs[i].profit < jobs[j].profit) {
                Job temp = jobs[i];
                jobs[i]  = jobs[j];
                jobs[j]  = temp;
            }
        }
    }
}

int main(void) {
    int num_jobs;
    printf("Enter number of jobs: ");
    scanf("%d", &num_jobs);

    Job jobs[20];
    int max_deadline = 0;

    printf("Enter job id, deadline, and profit for each job:\n");
    for (int i = 0; i < num_jobs; i++) {
        scanf("%d %d %d", &jobs[i].job_id, &jobs[i].deadline, &jobs[i].profit);
        if (jobs[i].deadline > max_deadline)
            max_deadline = jobs[i].deadline;
    }

    sortByProfit(jobs, num_jobs);

    /* time_slot[t] = job id assigned to slot t; -1 means the slot is free */
    int time_slot[max_deadline + 1];
    for (int t = 0; t <= max_deadline; t++)
        time_slot[t] = -1;

    int total_profit    = 0;
    int scheduled_count = 0;

    for (int i = 0; i < num_jobs; i++) {
        /* Find the latest free slot at or before this job's deadline */
        for (int slot = jobs[i].deadline; slot >= 1; slot--) {
            if (time_slot[slot] == -1) {
                time_slot[slot]  = jobs[i].job_id;
                total_profit    += jobs[i].profit;
                scheduled_count++;
                break;
            }
        }
    }

    printf("\nScheduled jobs (slot -> job id):\n");
    for (int slot = 1; slot <= max_deadline; slot++)
        if (time_slot[slot] != -1)
            printf("  Slot %d -> Job %d\n", slot, time_slot[slot]);

    printf("Total jobs scheduled : %d\n", scheduled_count);
    printf("Total profit         : %d\n", total_profit);

    return 0;
}
