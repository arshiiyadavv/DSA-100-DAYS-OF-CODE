#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int indegree[MAX];
int queue[MAX];
int front = 0, rear = -1;

void enqueue(int x) {
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front > rear;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][v] = 1;     // Directed edge u -> v
        indegree[v]++;
    }

    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            enqueue(i);
        }
    }

    int count = 0;
    int topo[MAX];

    while (!isEmpty()) {
        int node = dequeue();
        topo[count++] = node;

        for (int i = 0; i < V; i++) {
            if (adj[node][i]) {
                indegree[i]--;

                if (indegree[i] == 0) {
                    enqueue(i);
                }
            }
        }
    }

    if (count != V) {
        printf("Cycle exists, topological sort not possible\n");
    } else {
        for (int i = 0; i < count; i++) {
            printf("%d ", topo[i]);
        }
        printf("\n");
    }

    return 0;
}