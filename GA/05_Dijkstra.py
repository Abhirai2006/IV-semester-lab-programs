"""
Program  : Dijkstra's Shortest Path Algorithm
Subject  : Graph Algorithms Lab
Aim      : From a given source vertex, find the shortest path to a
           destination vertex using Dijkstra's algorithm.

Algorithm:
1. Set source cost = 0, all other node costs = infinity.
2. Use a min-heap (priority queue) to always pick the cheapest unvisited node.
3. For each unvisited neighbour: if new cost < current cost, update it
   and record the predecessor path.
4. Repeat until heap is empty (all reachable nodes finalised).

Sample Output:
  Shortest Distance : 10
  Shortest Path     : ['A', 'C', 'E', 'F']
"""

import sys
from heapq import heapify, heappush, heappop


def dijkstra(graph, source, destination):
    """Finds shortest distance and path from source to destination."""
    inf = sys.maxsize

    # node_data[node] = {'cost': minimum distance from source, 'pred': path taken}
    node_data = {node: {'cost': inf, 'pred': []} for node in graph}
    node_data[source]['cost'] = 0

    visited        = []
    priority_queue = [(0, source)]   # (cost, node)
    heapify(priority_queue)

    while priority_queue:
        current_cost, current_node = heappop(priority_queue)

        if current_node in visited:
            continue   # already settled via a cheaper path

        visited.append(current_node)

        for neighbour, edge_cost in graph[current_node].items():
            if neighbour not in visited:
                new_cost = node_data[current_node]['cost'] + edge_cost
                if new_cost < node_data[neighbour]['cost']:
                    node_data[neighbour]['cost'] = new_cost
                    node_data[neighbour]['pred'] = (
                        node_data[current_node]['pred'] + [current_node]
                    )
                    heappush(priority_queue, (new_cost, neighbour))

    print("Shortest Distance :", node_data[destination]['cost'])
    print("Shortest Path     :", node_data[destination]['pred'] + [destination])


# Weighted undirected graph stored as adjacency dict
# Note: 'C' has neighbour 'D' (weight 2) — unclear in manual but deduced from output
graph = {
    'A': {'B': 2,  'C': 4},
    'B': {'A': 2,  'C': 3, 'D': 8},
    'C': {'A': 4,  'B': 3, 'E': 5, 'D': 2},
    'D': {'B': 8,  'C': 2, 'E': 11, 'F': 22},
    'E': {'C': 5,  'D': 11, 'F': 1},
    'F': {'D': 22, 'E': 1}
}

source      = 'A'
destination = 'F'
dijkstra(graph, source, destination)
