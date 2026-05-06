#include <stdio.h>

int graph[100][100];
int visited[100];
int queue[100];

int main() {
    int n, m, s;
    int front = 0, rear = 0;

    scanf("%d", &n);
    scanf("%d", &m);

    // Initialize graph
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        graph[u][v] = 1;
        graph[v][u] = 1; // Remove for directed graph
    }

    // Source vertex
    scanf("%d", &s);

    // Initialize visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // BFS
    visited[s] = 1;
    queue[rear++] = s;

    printf("BFS Traversal: ");

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    return 0;
}