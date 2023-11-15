#include <stdio.h>
#include <stdlib.h>

void prn(int n, int m[][50]) {
    printf("\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
}

void dijkstra(int n, int s, int m[][50], int dist[10]) {
    int i, v, count = 1, min, visited[10];

    // Initialization: setting distances and visited flags
    for (i = 1; i <= n; i++) {
        visited[i] = 0;
        dist[i] = m[s][i];
    }
    visited[s] = 1;
    dist[s] = 0;

    // Dijkstra's algorithm
    while (count <= n) {
        min = 999; // Initialize the minimum distance to a large value
        v = 0;

        // Find the vertex with the minimum distance among the unvisited vertices
        for (i = 1; i <= n; i++) {
            if (dist[i] < min && visited[i] == 0) {
                min = dist[i];
                v = i;
            }
        }

        visited[v] = 1; // Mark the selected vertex as visited
        count++;

        // Update distances for adjacent vertices
        for (i = 1; i <= n; i++) {
            if (m[v][i] != 0 && dist[i] > dist[v] + m[v][i]) {
                dist[i] = dist[v] + m[v][i];
            }
        }
    }
}

int main() {
    int n, s, m[50][50], dist[10];
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Input the weights for each edge
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("Enter the weight from %d to %d: ", i, j);
            scanf("%d", &m[i][j]);
        }
    }

    // Set unreachable nodes' distances to a large value (998 represents infinity)
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (m[i][j] == 0 && i != j) {
                m[i][j] = 998;
            }
        }
    }

    // Print the adjacency matrix
    prn(n, m);

    // Input the source node
    printf("Enter the source node: ");
    scanf("%d", &s);

    // Apply Dijkstra's algorithm
    dijkstra(n, s, m, dist);

    // Print the shortest paths from the source node
    printf("Shortest paths from %d are:\n", s);
    for (int i = 1; i <= n; i++) {
        if (s != i) {
            printf("%d -> %d = %d\n", s, i, dist[i]);
        }
    }

    return 0;
}
