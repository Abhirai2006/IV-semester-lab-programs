/*
 * Program  : Floyd-Warshall All-Pairs Shortest Paths
 * Subject  : Design and Analysis of Algorithms Lab
 * Category : Dynamic Programming
 * Complexity: O(V³)
 *
 * Aim: Compute the shortest path between every pair of vertices in a
 *      weighted directed graph (negative edges allowed, no negative cycles).
 */

#include <stdio.h>

#define INF          99999
#define MAX_VERTICES 20

int main(void) {
    int num_vertices;
    printf("Enter number of vertices: ");
    scanf("%d", &num_vertices);

    int dist[MAX_VERTICES][MAX_VERTICES];
    printf("Enter cost matrix (%d for no direct edge, 0 on diagonal):\n", INF);
    for (int row = 0; row < num_vertices; row++)
        for (int col = 0; col < num_vertices; col++)
            scanf("%d", &dist[row][col]);

    /*
     * Floyd-Warshall: for each intermediate vertex, check if routing
     * through it gives a shorter path between every pair (source, destination).
     */
    for (int intermediate = 0; intermediate < num_vertices; intermediate++) {
        for (int source = 0; source < num_vertices; source++) {
            for (int destination = 0; destination < num_vertices; destination++) {
                if (dist[source][intermediate] != INF &&
                    dist[intermediate][destination] != INF &&
                    dist[source][intermediate] + dist[intermediate][destination] < dist[source][destination])
                    dist[source][destination] = dist[source][intermediate] + dist[intermediate][destination];
            }
        }
    }

    /* Check for negative cycles (dist[v][v] < 0 means a negative cycle exists) */
    for (int vertex = 0; vertex < num_vertices; vertex++) {
        if (dist[vertex][vertex] < 0) {
            printf("Negative cycle detected!\n");
            return 1;
        }
    }

    printf("\nAll-Pairs Shortest Path Matrix:\n");
    for (int row = 0; row < num_vertices; row++) {
        for (int col = 0; col < num_vertices; col++) {
            if (dist[row][col] == INF)
                printf("  INF");
            else
                printf("%5d", dist[row][col]);
        }
        printf("\n");
    }

    return 0;
}
