#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, end;
} Interval;

int compare(const void *a, const void *b) {
    Interval *x = (Interval *)a;
    Interval *y = (Interval *)b;
    return x->start - y->start;
}

int main() {
    int n;
    scanf("%d", &n);

    Interval arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    qsort(arr, n, sizeof(Interval), compare);

    Interval merged[n];
    int k = 0;

    merged[k] = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i].start <= merged[k].end) {
            if (arr[i].end > merged[k].end) {
                merged[k].end = arr[i].end;
            }
        } else {
            k++;
            merged[k] = arr[i];
        }
    }

    for (int i = 0; i <= k; i++) {
        printf("%d %d\n", merged[i].start, merged[i].end);
    }

    return 0;
}