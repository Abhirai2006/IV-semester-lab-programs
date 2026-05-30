# FCFS CPU Scheduling

n = int(input("Enter number of processes: "))
at = [int(input(f"P{i+1} Arrival Time: ")) for i in range(n)]
bt = [int(input(f"P{i+1} Burst Time  : ")) for i in range(n)]

ct, cur = [0]*n, 0
for i in range(n):
    cur = max(cur, at[i]) + bt[i]
    ct[i] = cur

tat = [ct[i] - at[i] for i in range(n)]
wt  = [tat[i] - bt[i] for i in range(n)]

print(f"\n{'Process':<10}{'Arrival':<10}{'Burst':<10}{'CT':<10}{'TAT':<10}{'WT'}")
print("-" * 60)
for i in range(n):
    print(f"P{i+1:<9}{at[i]:<10}{bt[i]:<10}{ct[i]:<10}{tat[i]:<10}{wt[i]}")

print(f"\nAvg TAT: {sum(tat)/n:.2f}  |  Avg WT: {sum(wt)/n:.2f}")
