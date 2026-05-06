#include <stdio.h>
#include <stdlib.h>

// Structure for tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Queue structure
struct Queue {
    struct Node* arr[100];
    int front, rear;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Initialize queue
void initQueue(struct Queue* q) {
    q->front = 0;
    q->rear = -1;
}

// Check if queue is empty
int isEmpty(struct Queue* q) {
    return q->front > q->rear;
}

// Enqueue
void enqueue(struct Queue* q, struct Node* node) {
    q->arr[++q->rear] = node;
}

// Dequeue
struct Node* dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

// Level Order Traversal
void levelOrderTraversal(struct Node* root) {
    if (root == NULL)
        return;

    struct Queue q;
    initQueue(&q);

    enqueue(&q, root);

    while (!isEmpty(&q)) {
        struct Node* current = dequeue(&q);

        printf("%d ", current->data);

        if (current->left)
            enqueue(&q, current->left);

        if (current->right)
            enqueue(&q, current->right);
    }
}

int main() {
    /*
            1
           / \
          2   3
         / \
        4   5
    */

    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    levelOrderTraversal(root);

    return 0;
}