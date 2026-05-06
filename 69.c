#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF 999999

int graph[MAX][MAX];
int dist[MAX];
int visited[MAX];
int n;

/* Find unvisited vertex with minimum distance */
int getMinVertex() {
    int min = INF;
    int vertex = -1;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            vertex = i;
        }
    }

    return vertex;
}

void dijkstra(int source) {
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[source] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = getMinVertex();

        if (u == -1)
            break;

        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0 && !visited[v]) {
                if (dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }
}

int main() {
    int m, source;
    int u, v, w;

    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);

        graph[u][v] = w;
        graph[v][u] = w;   // remove this line for directed graph
    }

    scanf("%d", &source);

    dijkstra(source);

    for (int i = 0; i < n; i++) {
        if (dist[i] == INF)
            printf("%d: INF\n", i);
        else
            printf("%d: %d\n", i, dist[i]);
    }

    return 0;
}