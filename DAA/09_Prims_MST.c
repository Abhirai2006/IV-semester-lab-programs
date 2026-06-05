/*
 * Program  : Prim's Minimum Spanning Tree
 * Subject  : Design and Analysis of Algorithms Lab
 * Category : Greedy / Graph
 * Complexity: O(V²)
 *
 * Aim: Find the Minimum Spanning Tree (MST) of a weighted undirected graph
 *      using Prim's algorithm.
 */

#include <stdio.h>

#define INF 99999

int main(void) {
    int num_vertices;
    printf("Enter number of vertices: ");
    scanf("%d", &num_vertices);

    int cost[20][20];
    printf("Enter cost matrix (0 or %d for no edge):\n", INF);
    for (int row = 0; row < num_vertices; row++)
        for (int col = 0; col < num_vertices; col++)
            scanf("%d", &cost[row][col]);

    int min_edge_cost[20];   /* min_edge_cost[v] = cheapest edge connecting v to the MST */
    int parent_vertex[20];   /* parent_vertex[v] = which MST vertex connects to v        */
    int in_mst[20];          /* in_mst[v] = 1 if vertex v is already in the MST          */

    for (int vertex = 0; vertex < num_vertices; vertex++) {
        min_edge_cost[vertex] = INF;
        in_mst[vertex]        = 0;
        parent_vertex[vertex] = -1;
    }

    min_edge_cost[0] = 0;  /* Start building MST from vertex 0 */

    for (int iteration = 0; iteration < num_vertices; iteration++) {
        /* Pick the unvisited vertex with the smallest connecting edge */
        int chosen = -1;
        for (int vertex = 0; vertex < num_vertices; vertex++)
            if (!in_mst[vertex] && (chosen == -1 || min_edge_cost[vertex] < min_edge_cost[chosen]))
                chosen = vertex;

        in_mst[chosen] = 1;

        /* Update connecting costs for neighbours of the chosen vertex */
        for (int neighbour = 0; neighbour < num_vertices; neighbour++) {
            if (!in_mst[neighbour] &&
                cost[chosen][neighbour] &&
                cost[chosen][neighbour] < min_edge_cost[neighbour]) {
                min_edge_cost[neighbour] = cost[chosen][neighbour];
                parent_vertex[neighbour] = chosen;
            }
        }
    }

    int total_mst_cost = 0;
    printf("\nMST Edges (vertex -- vertex : weight):\n");
    for (int vertex = 1; vertex < num_vertices; vertex++) {
        printf("  %d -- %d : %d\n", parent_vertex[vertex], vertex, min_edge_cost[vertex]);
        total_mst_cost += min_edge_cost[vertex];
    }
    printf("Total MST Cost = %d\n", total_mst_cost);

    return 0;
}
