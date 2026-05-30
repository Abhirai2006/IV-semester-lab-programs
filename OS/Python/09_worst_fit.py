# Memory Allocation — Worst Fit

nb = int(input("Number of blocks: "))
bs = [int(input(f"Block {i+1} size: ")) for i in range(nb)]
nf = int(input("Number of files: "))
fs = [int(input(f"File {i+1} size: ")) for i in range(nf)]

alloc = [-1] * nf
used  = [False] * nb

for j in range(nf):
    worst, worst_idx = -1, -1
    for i in range(nb):
        diff = bs[i] - fs[j]
        if not used[i] and diff >= 0 and diff > worst:
            worst, worst_idx = diff, i
    if worst_idx != -1:
        alloc[j] = worst_idx; used[worst_idx] = True

print(f"\n{'File':<8}{'F.Size':<10}{'Block':<8}{'B.Size':<10}{'Fragment'}")
print("-" * 44)
for j in range(nf):
    if alloc[j] != -1:
        frag = bs[alloc[j]] - fs[j]
        print(f"F{j+1:<7}{fs[j]:<10}{alloc[j]+1:<8}{bs[alloc[j]]:<10}{frag}")
    else:
        print(f"F{j+1:<7}{fs[j]:<10}Not Allocated")
