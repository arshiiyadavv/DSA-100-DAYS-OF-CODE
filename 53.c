#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

struct Node {
    int data;
    struct Node *left, *right;
};

struct QueueNode {
    struct Node* node;
    int hd;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node* nodes[n];

    for (int i = 0; i < n; i++) {
        if (arr[i] != -1)
            nodes[i] = createNode(arr[i]);
        else
            nodes[i] = NULL;
    }

    for (int i = 0; i < n; i++) {
        if (nodes[i] != NULL) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < n)
                nodes[i]->left = nodes[left];

            if (right < n)
                nodes[i]->right = nodes[right];
        }
    }

    return nodes[0];
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    // Vertical storage
    int vertical[200][100];
    int count[200] = {0};

    int minHD = 0, maxHD = 0;

    // Queue for BFS
    struct QueueNode queue[MAX];
    int front = 0, rear = 0;

    queue[rear++] = (struct QueueNode){root, 0};

    while (front < rear) {
        struct QueueNode temp = queue[front++];

        struct Node* curr = temp.node;
        int hd = temp.hd;

        int index = hd + 100;

        vertical[index][count[index]++] = curr->data;

        if (hd < minHD)
            minHD = hd;

        if (hd > maxHD)
            maxHD = hd;

        if (curr->left)
            queue[rear++] = (struct QueueNode){curr->left, hd - 1};

        if (curr->right)
            queue[rear++] = (struct QueueNode){curr->right, hd + 1};
    }

    // Print vertical order
    for (int i = minHD + 100; i <= maxHD + 100; i++) {
        for (int j = 0; j < count[i]; j++) {
            printf("%d ", vertical[i][j]);
        }
        printf("\n");
    }

    return 0;
}