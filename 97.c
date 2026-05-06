#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Meeting;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyDown(int heap[], int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;

    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(heap, size, smallest);
    }
}

void heapifyUp(int heap[], int i) {
    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void insertHeap(int heap[], int *size, int value) {
    heap[*size] = value;
    (*size)++;
    heapifyUp(heap, *size - 1);
}

void removeMin(int heap[], int *size) {
    heap[0] = heap[*size - 1];
    (*size)--;
    heapifyDown(heap, *size, 0);
}

int compareMeetings(const void *a, const void *b) {
    Meeting *m1 = (Meeting *)a;
    Meeting *m2 = (Meeting *)b;
    return m1->start - m2->start;
}

int minMeetingRooms(Meeting meetings[], int n) {
    qsort(meetings, n, sizeof(Meeting), compareMeetings);

    int heap[n];
    int heapSize = 0;

    insertHeap(heap, &heapSize, meetings[0].end);

    for (int i = 1; i < n; i++) {
        if (meetings[i].start >= heap[0]) {
            removeMin(heap, &heapSize);
        }

        insertHeap(heap, &heapSize, meetings[i].end);
    }

    return heapSize;
}

int main() {
    int n;
    scanf("%d", &n);

    Meeting meetings[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &meetings[i].start, &meetings[i].end);
    }

    printf("%d", minMeetingRooms(meetings, n));

    return 0;
}