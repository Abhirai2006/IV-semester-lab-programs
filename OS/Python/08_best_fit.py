# Memory Allocation — Best Fit

nb = int(input("Number of blocks: "))
bs = [int(input(f"Block {i+1} size: ")) for i in range(nb)]
np = int(input("Number of processes: "))
ps = [int(input(f"Process {i+1} size: ")) for i in range(np)]

alloc = [-1] * np
used  = [False] * nb

for j in range(np):
    best, best_idx = float('inf'), -1
    for i in range(nb):
        diff = bs[i] - ps[j]
        if not used[i] and 0 <= diff < best:
            best, best_idx = diff, i
    if best_idx != -1:
        alloc[j] = best_idx; used[best_idx] = True

print(f"\n{'Process':<10}{'P.Size':<10}{'Block':<8}{'B.Size':<10}{'Fragment'}")
print("-" * 46)
for j in range(np):
    if alloc[j] != -1:
        frag = bs[alloc[j]] - ps[j]
        print(f"P{j+1:<9}{ps[j]:<10}{alloc[j]+1:<8}{bs[alloc[j]]:<10}{frag}")
    else:
        print(f"P{j+1:<9}{ps[j]:<10}Not Allocated")
