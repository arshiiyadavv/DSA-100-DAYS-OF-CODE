#include <stdio.h>
#include <stdlib.h>

#define N 100

// Node for linked list bucket
struct Node {
    float data;
    struct Node* next;
};

// Insert node in sorted order
void insertSorted(struct Node** head, float value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    // Insert at beginning
    if (*head == NULL || (*head)->data >= value) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    // Find correct position
    struct Node* current = *head;
    while (current->next != NULL && current->next->data < value) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// Bucket Sort Function
void bucketSort(float arr[], int n) {
    struct Node* buckets[N];

    // Initialize buckets
    for (int i = 0; i < n; i++) {
        buckets[i] = NULL;
    }

    // Put array elements into buckets
    for (int i = 0; i < n; i++) {
        int index = n * arr[i];
        insertSorted(&buckets[index], arr[i]);
    }

    // Concatenate buckets into array
    int k = 0;
    for (int i = 0; i < n; i++) {
        struct Node* temp = buckets[i];

        while (temp != NULL) {
            arr[k++] = temp->data;
            temp = temp->next;
        }
    }
}

int main() {
    int n;

    scanf("%d", &n);

    float arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    bucketSort(arr, n);

    // Print sorted array
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }

    return 0;
}