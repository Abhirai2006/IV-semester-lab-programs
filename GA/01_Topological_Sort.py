"""
Program  : Topological Sort (DFS-based)
Subject  : Graph Algorithms Lab
Aim      : Obtain the topological ordering of vertices in a given digraph.

Algorithm:
1. For each unvisited vertex, run DFS.
2. In DFS, mark the vertex as visited, recurse on all unvisited neighbours.
3. After all neighbours are processed, push the vertex onto result_stack.
4. Reverse of result_stack gives the topological order.

Sample Output: [5, 4, 2, 3, 1, 0]
"""

# adjacent_list[i] = list of vertices that vertex i points to
adjacent_list = [[1, 2], [3], [3], [1], [0, 1], [0, 2]]
visited       = [0] * len(adjacent_list)  # 0 = unvisited, 1 = visited
result_stack  = []                        # stores vertices in finish order


def dfs(node, visited, adj):
    """Marks node visited, recurses into unvisited neighbours, then stacks node."""
    visited[node] = 1
    for neighbour in adj[node]:
        if visited[neighbour] == 0:
            dfs(neighbour, visited, adj)
    if node not in result_stack:
        result_stack.append(node)


# Start DFS from every unvisited vertex
for vertex in range(len(adjacent_list)):
    if visited[vertex] == 0:
        dfs(vertex, visited, adjacent_list)

# Reverse the finish stack to get topological order
print("Topological Order:", result_stack[::-1])
