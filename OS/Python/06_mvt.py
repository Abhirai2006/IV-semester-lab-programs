# Memory Management — Variable Partitions (MVT)

ms   = int(input("Total memory (Bytes): "))
rem  = ms
procs, i = [], 0

while True:
    size = int(input(f"Memory for Process {i+1} (Bytes): "))
    if size <= rem:
        print(f"Process {i+1} allocated.")
        procs.append(size); rem -= size; i += 1
    else:
        print("Not enough memory!"); break
    if input("Continue? (y/n): ").strip().lower() != 'y': break

print(f"\nTotal Memory   : {ms} Bytes")
print(f"\n{'Process':<12}{'Allocated (Bytes)'}")
print("-" * 30)
for idx, s in enumerate(procs, 1):
    print(f"{idx:<12}{s}")
print(f"\nTotal Allocated      : {ms - rem} Bytes")
print(f"External Fragmentation: {rem} Bytes")
