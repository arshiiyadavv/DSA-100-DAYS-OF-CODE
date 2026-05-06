#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int recStack[MAX];
int V;

// DFS function to detect cycle
int dfs(int node) {
    visited[node] = 1;
    recStack[node] = 1;

    for (int i = 0; i < V; i++) {
        if (adj[node][i]) {

            // If node not visited
            if (!visited[i]) {
                if (dfs(i))
                    return 1;
            }

            // If node already in recursion stack
            else if (recStack[i]) {
                return 1;
            }
        }
    }

    recStack[node] = 0;
    return 0;
}

int main() {
    int E;
    scanf("%d %d", &V, &E);

    // Input edges
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][v] = 1; // Directed graph
    }

    int cycle = 0;

    // Check all components
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i)) {
                cycle = 1;
                break;
            }
        }
    }

    if (cycle)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}