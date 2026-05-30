# Memory Allocation — First Fit

nb = int(input("Number of blocks: "))
bs = [int(input(f"Block {i+1} size: ")) for i in range(nb)]
np = int(input("Number of processes: "))
ps = [int(input(f"Process {i+1} size: ")) for i in range(np)]

alloc = [-1] * np  # -1 = not allocated
used  = [False] * nb

for j in range(np):
    for i in range(nb):
        if not used[i] and ps[j] <= bs[i]:
            alloc[j] = i; used[i] = True; break

print()
for j in range(np):
    if alloc[j] != -1:
        print(f"Process {j+1} (size {ps[j]}) -> Block {alloc[j]+1} (size {bs[alloc[j]]})")
    else:
        print(f"Process {j+1} (size {ps[j]}) -> Not Allocated")
