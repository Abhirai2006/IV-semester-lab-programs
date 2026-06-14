/*
 * Program  : Travelling Salesman Problem (Branch and Bound)
 * Subject  : Design and Analysis of Algorithms Lab
 * Category : Branch and Bound
 * Complexity: Exponential worst case; pruning reduces average case significantly
 *
 * Aim: Find the minimum cost Hamiltonian cycle that visits every city exactly
 *      once and returns to the start, using Branch and Bound with cost-based pruning.
 */

#include <stdio.h>

#define INF      99999
#define MAX_CITIES 15

int num_cities;
int travel_cost[MAX_CITIES][MAX_CITIES];
int best_tour_cost              = INF;
int best_tour[MAX_CITIES];
int current_tour[MAX_CITIES];

/*
 * explore: recursively builds the tour city by city.
 *   current_city   : the city we are currently at
 *   visited[]      : tracks which cities have been included
 *   accumulated_cost : total travel cost so far
 *   cities_visited : how many cities have been visited (including start)
 */
void explore(int current_city, int visited[], int accumulated_cost, int cities_visited) {
    /* All cities visited — try to return to the starting city */
    if (cities_visited == num_cities) {
        if (travel_cost[current_city][0] != 0 &&
            accumulated_cost + travel_cost[current_city][0] < best_tour_cost) {
            best_tour_cost = accumulated_cost + travel_cost[current_city][0];
            for (int i = 0; i < num_cities; i++)
                best_tour[i] = current_tour[i];
        }
        return;
    }

    for (int next_city = 0; next_city < num_cities; next_city++) {
        if (!visited[next_city] && travel_cost[current_city][next_city] != 0) {
            /* Pruning: skip branch if it already exceeds the best known cost */
            if (accumulated_cost + travel_cost[current_city][next_city] < best_tour_cost) {
                visited[next_city]             = 1;
                current_tour[cities_visited]   = next_city;
                explore(next_city, visited,
                        accumulated_cost + travel_cost[current_city][next_city],
                        cities_visited + 1);
                visited[next_city] = 0;  /* backtrack */
            }
        }
    }
}

int main(void) {
    printf("Enter number of cities: ");
    scanf("%d", &num_cities);

    printf("Enter cost matrix (0 for no direct path):\n");
    for (int row = 0; row < num_cities; row++)
        for (int col = 0; col < num_cities; col++)
            scanf("%d", &travel_cost[row][col]);

    int visited[MAX_CITIES] = {0};
    visited[0]     = 1;
    current_tour[0] = 0;  /* always start from city 0 */

    explore(0, visited, 0, 1);

    if (best_tour_cost == INF) {
        printf("No valid tour found.\n");
    } else {
        printf("\nOptimal Tour: 0");
        for (int step = 1; step < num_cities; step++)
            printf(" -> %d", best_tour[step]);
        printf(" -> 0\n");
        printf("Minimum Tour Cost = %d\n", best_tour_cost);
    }

    return 0;
}
