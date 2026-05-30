# SJF CPU Scheduling (Non-Preemptive)

n  = int(input("Enter number of processes: "))
bt = [int(input(f"P{i+1} Burst Time: ")) for i in range(n)]

# Sort processes by burst time, carry original process number
procs = sorted(enumerate(bt, 1), key=lambda x: x[1])
pid   = [p[0] for p in procs]
bt    = [p[1] for p in procs]

wt  = [0] + [sum(bt[:i]) for i in range(1, n)]
tat = [wt[i] + bt[i] for i in range(n)]

print(f"\n{'Process':<12}{'Burst':<12}{'WT':<12}{'TAT'}")
print("-" * 48)
for i in range(n):
    print(f"P{pid[i]:<11}{bt[i]:<12}{wt[i]:<12}{tat[i]}")

print(f"\nAvg WT: {sum(wt)/n:.2f}  |  Avg TAT: {sum(tat)/n:.2f}")
