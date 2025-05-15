#include <stdio.h>
#include <limits.h>

#define V 4

int tsp(int graph[V][V], int visited[], int pos, int n, int count, int cost, int start) {
    if (count == n && graph[pos][start]) {
        return cost + graph[pos][start];
    }

    int ans = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && graph[pos][i]) {
            visited[i] = 1;
            int temp = tsp(graph, visited, i, n, count + 1, cost + graph[pos][i], start);
            ans = (temp < ans) ? temp : ans;
            visited[i] = 0;
        }
    }

    return ans;
}

int main() {
    int graph[V][V] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int visited[V];
    for (int i = 0; i < V; i++) visited[i] = 0;

    visited[0] = 1;

    int result = tsp(graph, visited, 0, V, 1, 0, 0);
    printf("Minimum cost of travelling all cities: %d\n", result);

    return 0;
}
