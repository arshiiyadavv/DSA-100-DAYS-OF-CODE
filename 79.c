#include <stdio.h>

#define MAX 100
#define INF 999999

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int graph[MAX][MAX];

    // Initialize graph with INF
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = INF;
        }
    }

    // Input edges
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        graph[u][v] = w;
        graph[v][u] = w; // remove this line for directed graph
    }

    int source;
    scanf("%d", &source);

    int dist[MAX], visited[MAX];

    // Initialize distances
    for (int i = 1; i <= n; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[source] = 0;

    // Dijkstra's Algorithm
    for (int count = 1; count <= n - 1; count++)
    {
        int min = INF, u;

        // Find minimum distance vertex
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i] && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }
        }

        visited[u] = 1;

        // Update distances
        for (int v = 1; v <= n; v++)
        {
            if (!visited[v] &&
                graph[u][v] != INF &&
                dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print shortest distances
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", dist[i]);
    }

    return 0;
}