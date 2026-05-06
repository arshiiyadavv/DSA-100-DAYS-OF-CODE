#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[n];

    // Initialize adjacency list
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
    }

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        // Add edge u -> v
        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        // Add edge v -> u (for undirected graph)
        newNode = createNode(u);
        newNode->next = adj[v];
        adj[v] = newNode;
    }

    // Print adjacency list
    for (int i = 0; i < n; i++) {
        printf("%d: ", i);

        struct Node* temp = adj[i];

        while (temp != NULL) {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }

        printf("\n");
    }

    return 0;
}