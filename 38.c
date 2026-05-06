#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000

int dq[MAX];
int front = -1, rear = -1;

int isEmpty() {
    return front == -1;
}

int size() {
    if (isEmpty()) return 0;
    return rear - front + 1;
}

void push_front(int x) {
    if (front == 0) {
        printf("No space at front\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else {
        front--;
    }

    dq[front] = x;
}

void push_back(int x) {
    if (rear == MAX - 1) {
        printf("Deque is full\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear++;
    }

    dq[rear] = x;
}

void pop_front() {
    if (isEmpty()) return;

    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}

void pop_back() {
    if (isEmpty()) return;

    if (front == rear) {
        front = rear = -1;
    } else {
        rear--;
    }
}

void display() {
    if (isEmpty()) {
        printf("\n");
        return;
    }

    for (int i = front; i <= rear; i++) {
        printf("%d ", dq[i]);
    }
    printf("\n");
}

void reverseDeque() {
    int i = front, j = rear;
    while (i < j) {
        int temp = dq[i];
        dq[i] = dq[j];
        dq[j] = temp;
        i++;
        j--;
    }
}

void sortDeque() {
    for (int i = front; i <= rear; i++) {
        for (int j = i + 1; j <= rear; j++) {
            if (dq[i] > dq[j]) {
                int temp = dq[i];
                dq[i] = dq[j];
                dq[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        char op[30];
        scanf("%s", op);

        if (strcmp(op, "push_front") == 0) {
            int x;
            scanf("%d", &x);
            push_front(x);
        }

        else if (strcmp(op, "push_back") == 0) {
            int x;
            scanf("%d", &x);
            push_back(x);
        }

        else if (strcmp(op, "pop_front") == 0) {
            pop_front();
        }

        else if (strcmp(op, "pop_back") == 0) {
            pop_back();
        }

        else if (strcmp(op, "front") == 0) {
            if (!isEmpty())
                printf("%d\n", dq[front]);
            else
                printf("Deque is empty\n");
        }

        else if (strcmp(op, "back") == 0) {
            if (!isEmpty())
                printf("%d\n", dq[rear]);
            else
                printf("Deque is empty\n");
        }

        else if (strcmp(op, "size") == 0) {
            printf("%d\n", size());
        }

        else if (strcmp(op, "empty") == 0) {
            if (isEmpty())
                printf("Yes\n");
            else
                printf("No\n");
        }

        else if (strcmp(op, "clear") == 0) {
            front = rear = -1;
        }

        else if (strcmp(op, "reverse") == 0) {
            reverseDeque();
        }

        else if (strcmp(op, "sort") == 0) {
            sortDeque();
        }

        else if (strcmp(op, "display") == 0) {
            display();
        }
    }

    return 0;
}