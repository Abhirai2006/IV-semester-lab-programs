"""
Program  : Warshall's Algorithm (Transitive Closure)
Subject  : Graph Algorithms Lab
Aim      : Compute the transitive closure of a given directed graph
           using Warshall's algorithm.

Algorithm:
1. Start with the adjacency matrix as the initial closure matrix.
2. For each intermediate vertex k (0 to n-1):
     For each source i and destination j:
       closure[i][j] = closure[i][j] OR (closure[i][k] AND closure[k][j])
3. The final matrix shows whether a path exists between every pair.

Sample Output:
  [1, 1, 1, 1]
  [0, 1, 1, 1]
  [0, 0, 1, 1]
  [0, 0, 0, 1]
"""


def compute_transitive_closure(graph):
    """Returns the transitive closure matrix using Warshall's algorithm."""
    num_nodes = len(graph)
    closure   = [list(row) for row in graph]   # deep copy of adjacency matrix

    for intermediate in range(num_nodes):
        for source in range(num_nodes):
            for destination in range(num_nodes):
                closure[source][destination] = (
                    closure[source][destination]
                    or (closure[source][intermediate] and closure[intermediate][destination])
                )
    return closure


def print_matrix(matrix):
    for row in matrix:
        print(row)


# Adjacency matrix (1 = direct edge exists, 0 = no direct edge)
graph = [
    [1, 1, 0, 1],
    [0, 1, 1, 0],
    [0, 0, 1, 1],
    [0, 0, 0, 1]
]

transitive_closure = compute_transitive_closure(graph)
print("Ans is")
print_matrix(transitive_closure)
