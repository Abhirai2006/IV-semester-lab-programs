"""
Program  : DFS — Graph Connectivity Check
Subject  : Graph Algorithms Lab
Aim      : Check whether a given graph is connected or not using DFS.

Algorithm:
1. Start DFS from any node, using a visited set.
2. Recursively visit all unvisited neighbours.
3. If all nodes in the graph are visited → graph is Connected.
   Otherwise → graph is Disconnected (some nodes unreachable).

Sample Output: A B E C D
               Graph is Connected
"""

graph = {
    'A': ['B', 'C', 'D'],
    'B': ['E'],
    'C': ['D', 'E'],
    'D': [],
    'E': []
}

visited = set()


def dfs(visited, graph, node):
    """Recursively visits all nodes reachable from node."""
    if node not in visited:
        print(node)
        visited.add(node)
        for neighbour in graph[node]:
            dfs(visited, graph, neighbour)


dfs(visited, graph, 'A')

# Connectivity check: all nodes must be reachable from the start
if len(visited) == len(graph):
    print("\nGraph is Connected")
else:
    print("\nGraph is NOT Connected")
