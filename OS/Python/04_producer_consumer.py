# Producer-Consumer Problem (Simulated Semaphores)

BUFFER_SIZE = 10
mutex, full, empty, item = 1, 0, BUFFER_SIZE, 0

def producer():
    global mutex, full, empty, item
    mutex -= 1; full += 1; empty -= 1; item += 1
    print(f"Producer produced item {item}")
    mutex += 1

def consumer():
    global mutex, full, empty, item
    mutex -= 1; full -= 1; empty += 1
    print(f"Consumer consumed item {item}")
    item -= 1
    mutex += 1

print("1. Producer  2. Consumer  3. Exit")
while True:
    n = int(input("\nEnter choice: "))
    if   n == 1:
        if mutex and empty: producer()
        else: print("Buffer is FULL!")
    elif n == 2:
        if mutex and full: consumer()
        else: print("Buffer is EMPTY!")
    elif n == 3: break
    print(f"[Buffer: {full}/{BUFFER_SIZE}]")
