#include <stdio.h>

typedef struct {
    int value;
    int index;
} Pair;

void merge(Pair arr[], Pair temp[], int ans[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;
    int rightCount = 0;

    while (i <= mid && j <= right) {
        if (arr[i].value <= arr[j].value) {
            ans[arr[i].index] += rightCount;
            temp[k++] = arr[i++];
        } else {
            rightCount++;
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        ans[arr[i].index] += rightCount;
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}

void mergeSort(Pair arr[], Pair temp[], int ans[], int left, int right) {
    if (left >= right) return;

    int mid = (left + right) / 2;

    mergeSort(arr, temp, ans, left, mid);
    mergeSort(arr, temp, ans, mid + 1, right);

    merge(arr, temp, ans, left, mid, right);
}

int main() {
    int n;
    scanf("%d", &n);

    Pair arr[n], temp[n];
    int ans[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].value);
        arr[i].index = i;
        ans[i] = 0;
    }

    mergeSort(arr, temp, ans, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }

    return 0;
}