# Memory Management — Fixed Partitions (MFT)

ms = int(input("Total memory (Bytes): "))
bs = int(input("Block size   (Bytes): "))
nob = ms // bs
print(f"Partitions created: {nob}")

n   = int(input("Number of processes: "))
mp  = [int(input(f"Process {i+1} size: ")) for i in range(n)]

print(f"\n{'Process':<10}{'Required':<12}{'Allocated':<12}{'Int. Frag'}")
print("-" * 46)

tif, allocated = 0, 0
for i in range(n):
    if allocated >= nob:
        print("Memory full. Remaining processes skipped."); break
    if mp[i] > bs:
        print(f"P{i+1:<9}{mp[i]:<12}NO")
    else:
        frag = bs - mp[i]
        print(f"P{i+1:<9}{mp[i]:<12}YES{' '*9}{frag}")
        tif += frag; allocated += 1

print(f"\nTotal Internal Fragmentation: {tif} Bytes")
print(f"Total External Fragmentation: {ms - nob*bs} Bytes")
