"""
Program  : Kruskal's Minimum Spanning Tree
Subject  : Graph Algorithms Lab
Aim      : Find the minimum cost spanning tree of a given undirected graph
           using Kruskal's algorithm.

Data Structure: Union-Find (Disjoint Set Union)
  parent[node] < 0  → node is a root; |parent[node]| = size of component
  parent[node] >= 0 → node's parent in the union-find tree

Algorithm:
1. Sort all edges in ascending order of weight.
2. For each edge (u, v, weight):
     If u and v are in different components → add edge to MST, union them.
     Else → skip (would create a cycle).
3. Stop when MST has (num_nodes - 1) edges.

Sample Output:
  [1, 2]
  [3, 4]
  [3, 6]
  [1, 3]
  [4, 5]
"""


def find_root(parent, node):
    """Returns root of node's component with path compression."""
    if parent[node] < 0:
        return node
    root         = find_root(parent, parent[node])
    parent[node] = root   # path compression: flatten the tree
    return root


def union_components(parent, node_a, node_b, mst_edges):
    """
    Merges the components containing node_a and node_b.
    Uses union by size: larger component absorbs smaller.
    Records the edge in mst_edges if they were in different components.
    """
    original_a = node_a
    original_b = node_b
    root_a     = find_root(parent, node_a)
    root_b     = find_root(parent, node_b)

    if root_a == root_b:
        return   # same component — adding this edge creates a cycle, skip

    mst_edges.append([original_a, original_b])

    # Merge smaller into larger (parent stores negative size)
    if parent[root_a] < parent[root_b]:   # root_a has larger component
        parent[root_a] += parent[root_b]
        parent[root_b]  = root_a
    else:
        parent[root_b] += parent[root_a]
        parent[root_a]  = root_b


# Edge list: [node1, node2, weight]
# (the '9' in the manual was deduced to be '4' from the expected output)
edges = [
    [1, 2, 1],
    [1, 3, 3],
    [2, 6, 4],
    [3, 6, 2],
    [3, 4, 1],
    [4, 5, 5]
]

num_nodes = 6
mst_edges = []

# Sort edges by weight ascending
edges  = sorted(edges, key=lambda edge: edge[2])
parent = [-1] * (num_nodes + 1)   # indices 0..num_nodes; we use 1..num_nodes

for node_a, node_b, weight in edges:
    union_components(parent, node_a, node_b, mst_edges)

for edge in mst_edges:
    print(edge)
