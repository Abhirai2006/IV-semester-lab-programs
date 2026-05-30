# Priority CPU Scheduling (Non-Preemptive, lower number = higher priority)

n   = int(input("Enter number of processes: "))
bt  = [int(input(f"P{i+1} Burst Time: ")) for i in range(n)]
pri = [int(input(f"P{i+1} Priority  : ")) for i in range(n)]

# Sort by priority (ascending = higher urgency)
procs = sorted(zip(pri, bt, range(1, n+1)), key=lambda x: x[0])
pri   = [p[0] for p in procs]
bt    = [p[1] for p in procs]
pid   = [p[2] for p in procs]

wt  = [0] + [sum(bt[:i]) for i in range(1, n)]
tat = [wt[i] + bt[i] for i in range(n)]

print(f"\n{'Process':<10}{'Priority':<10}{'Burst':<10}{'WT':<10}{'TAT'}")
print("-" * 50)
for i in range(n):
    print(f"P{pid[i]:<9}{pri[i]:<10}{bt[i]:<10}{wt[i]:<10}{tat[i]}")

print(f"\nAvg WT: {sum(wt)/n:.2f}  |  Avg TAT: {sum(tat)/n:.2f}")
