#include <stdio.h>

#define INF 999999

int graph[100][100];
int visited[100];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        graph[u][v] = w;
        graph[v][u] = w;
    }

    visited[1] = 1;
    int edges = 0, totalWeight = 0;

    while (edges < n - 1) {
        int min = INF;
        int a = -1, b = -1;

        for (int i = 1; i <= n; i++) {
            if (visited[i]) {
                for (int j = 1; j <= n; j++) {
                    if (!visited[j] && graph[i][j] < min) {
                        min = graph[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        visited[b] = 1;
        totalWeight += min;
        edges++;
    }

    printf("%d\n", totalWeight);

    return 0;
}