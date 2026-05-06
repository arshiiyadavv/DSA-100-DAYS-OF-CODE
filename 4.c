#include <stdio.h>

int main() {
    int n, i, temp;

    // Input size of array
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Reverse array using two-pointer approach
    int start = 0;
    int end = n - 1;

    while(start < end) {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }

    // Print reversed array
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}