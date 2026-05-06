#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert node at end
void insertEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Find intersection value
int findIntersection(struct Node* head1, struct Node* head2) {
    struct Node* p1 = head1;

    while (p1 != NULL) {
        struct Node* p2 = head2;

        while (p2 != NULL) {
            if (p1->data == p2->data) {
                return p1->data;
            }
            p2 = p2->next;
        }

        p1 = p1->next;
    }

    return -1;
}

int main() {
    int n, m, value;

    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    // Input first list
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertEnd(&head1, value);
    }

    // Input second list
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        scanf("%d", &value);
        insertEnd(&head2, value);
    }

    int intersection = findIntersection(head1, head2);

    if (intersection != -1)
        printf("%d", intersection);
    else
        printf("No Intersection");

    return 0;
}