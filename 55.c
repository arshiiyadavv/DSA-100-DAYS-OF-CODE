#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Binary Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Queue
struct Node* queue[MAX];
int front = 0, rear = 0;

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Enqueue
void enqueue(struct Node* node) {
    queue[rear++] = node;
}

// Dequeue
struct Node* dequeue() {
    return queue[front++];
}

// Build tree from level-order traversal
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node* root = createNode(arr[0]);
    enqueue(root);

    int i = 1;

    while (front < rear && i < n) {
        struct Node* current = dequeue();

        // Left child
        if (i < n && arr[i] != -1) {
            current->left = createNode(arr[i]);
            enqueue(current->left);
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            enqueue(current->right);
        }
        i++;
    }

    return root;
}

// Right View Traversal
void rightView(struct Node* root) {
    if (root == NULL)
        return;

    struct Node* q[MAX];
    int f = 0, r = 0;

    q[r++] = root;

    while (f < r) {
        int levelSize = r - f;

        for (int i = 0; i < levelSize; i++) {
            struct Node* temp = q[f++];

            // Print last node of current level
            if (i == levelSize - 1) {
                printf("%d ", temp->data);
            }

            if (temp->left)
                q[r++] = temp->left;

            if (temp->right)
                q[r++] = temp->right;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    rightView(root);

    return 0;
}