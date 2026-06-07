"""
Program  : Breadth First Search (BFS)
Subject  : Graph Algorithms Lab
Aim      : Print all nodes reachable from a given starting node
           in a digraph using BFS.

Two implementations shown as per lab manual:
  Method 1 — list-based queue, string node keys
  Method 2 — collections.deque (efficient O(1) popleft), integer node keys

Algorithm:
1. Mark start node as visited and enqueue it.
2. While queue is not empty:
     Dequeue a node, print/record it.
     For each unvisited neighbour: mark visited and enqueue.
"""

# ── Method 1 ─────────────────────────────
graph_1  = {
    '5': ['3', '7'],
    '3': ['2', '4'],
    '7': ['8'],
    '2': [],
    '4': ['8'],
    '8': []
}

visited_1  = []
bfs_queue  = []


def bfs_method1(visited, graph, start_node):
    """BFS using a plain list as queue (pop from front = O(n))."""
    visited.append(start_node)
    bfs_queue.append(start_node)

    while bfs_queue:
        current_node = bfs_queue.pop(0)        # dequeue from front
        print(current_node, end=" ")
        for neighbour in graph[current_node]:
            if neighbour not in visited:
                visited.append(neighbour)
                bfs_queue.append(neighbour)


print("Following is the BFS (Method 1):")
bfs_method1(visited_1, graph_1, '5')
print()

# ── Method 2 ─────────────────────────────
import collections


def bfs_method2(graph, start_node):
    """BFS using collections.deque for efficient O(1) popleft."""
    visited_set = set()
    queue       = collections.deque([start_node])

    while queue:
        current_vertex = queue.popleft()
        visited_set.add(current_vertex)
        for neighbour in graph[current_vertex]:
            if neighbour not in visited_set:
                queue.append(neighbour)

    print(visited_set)


if __name__ == "__main__":
    graph_2 = {
        0: [1, 2, 3],
        1: [0, 2],
        2: [0, 1],
        3: [0],
        4: [2]
    }
    print("\nFollowing is the BFS (Method 2):")
    bfs_method2(graph_2, 0)
