/*
 * Program  : Dijkstra's Shortest Path Algorithm
 * Subject  : Design and Analysis of Algorithms Lab
 * Category : Greedy / Graph
 * Complexity: O(V²)
 *
 * Aim: Find the shortest path from a source vertex to all other vertices
 *      in a weighted graph with non-negative edge weights.
 */

#include <stdio.h>

#define INF 99999

int main(void) {
    int num_vertices;
    printf("Enter number of vertices: ");
    scanf("%d", &num_vertices);

    int cost[20][20];
    printf("Enter cost matrix (%d for no direct edge):\n", INF);
    for (int row = 0; row < num_vertices; row++)
        for (int col = 0; col < num_vertices; col++)
            scanf("%d", &cost[row][col]);

    int source;
    printf("Enter source vertex (0-indexed): ");
    scanf("%d", &source);

    int shortest_dist[20];  /* shortest_dist[v] = shortest known distance from source to v */
    int finalized[20];      /* finalized[v] = 1 means shortest path to v is confirmed      */

    for (int vertex = 0; vertex < num_vertices; vertex++) {
        shortest_dist[vertex] = cost[source][vertex];
        finalized[vertex]     = 0;
    }
    shortest_dist[source] = 0;
    finalized[source]     = 1;

    for (int iteration = 0; iteration < num_vertices - 1; iteration++) {
        /* Pick the unfinalized vertex with the smallest known distance */
        int chosen = -1;
        for (int vertex = 0; vertex < num_vertices; vertex++)
            if (!finalized[vertex] && (chosen == -1 || shortest_dist[vertex] < shortest_dist[chosen]))
                chosen = vertex;

        if (shortest_dist[chosen] == INF) break;  /* remaining vertices are unreachable */

        finalized[chosen] = 1;

        /* Relax edges: update distance via chosen vertex if shorter */
        for (int neighbour = 0; neighbour < num_vertices; neighbour++) {
            if (!finalized[neighbour] &&
                cost[chosen][neighbour] != INF &&
                shortest_dist[chosen] + cost[chosen][neighbour] < shortest_dist[neighbour])
                shortest_dist[neighbour] = shortest_dist[chosen] + cost[chosen][neighbour];
        }
    }

    printf("\nShortest distances from vertex %d:\n", source);
    for (int vertex = 0; vertex < num_vertices; vertex++) {
        if (shortest_dist[vertex] == INF)
            printf("  To vertex %d : unreachable\n", vertex);
        else
            printf("  To vertex %d : %d\n", vertex, shortest_dist[vertex]);
    }

    return 0;
}
