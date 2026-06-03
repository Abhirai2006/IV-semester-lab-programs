/*
 * Program  : Topological Sort (Kahn's Algorithm)
 * Subject  : Design and Analysis of Algorithms Lab
 * Category : Graph
 * Complexity: O(V + E)
 *
 * Aim: Produce a valid topological ordering of a Directed Acyclic Graph (DAG)
 *      using Kahn's BFS-based algorithm.
 */

#include <stdio.h>

#define MAX_VERTICES 20

int adjacency[MAX_VERTICES][MAX_VERTICES];  /* adjacency matrix of the graph  */
int in_degree[MAX_VERTICES];               /* number of incoming edges per vertex */
int bfs_queue[MAX_VERTICES];               /* queue used for BFS traversal    */
int num_vertices, num_edges;

void topoSort(void) {
    int queue_front = 0;
    int queue_rear  = 0;
    int visited_count = 0;
    int result[MAX_VERTICES];

    /* Enqueue all vertices that have no incoming edges */
    for (int vertex = 0; vertex < num_vertices; vertex++)
        if (in_degree[vertex] == 0)
            bfs_queue[queue_rear++] = vertex;

    while (queue_front < queue_rear) {
        int current = bfs_queue[queue_front++];
        result[visited_count++] = current;

        /* Reduce in-degree of all neighbours of current vertex */
        for (int neighbour = 0; neighbour < num_vertices; neighbour++) {
            if (adjacency[current][neighbour]) {
                in_degree[neighbour]--;
                if (in_degree[neighbour] == 0)
                    bfs_queue[queue_rear++] = neighbour;
            }
        }
    }

    if (visited_count < num_vertices) {
        printf("Graph contains a cycle — topological sort not possible.\n");
        return;
    }

    printf("Topological Order: ");
    for (int i = 0; i < num_vertices; i++)
        printf("%d ", result[i]);
    printf("\n");
}

int main(void) {
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &num_vertices, &num_edges);

    printf("Enter each directed edge as (source destination):\n");
    for (int i = 0; i < num_edges; i++) {
        int source, destination;
        scanf("%d %d", &source, &destination);
        adjacency[source][destination] = 1;
        in_degree[destination]++;
    }

    topoSort();
    return 0;
}
