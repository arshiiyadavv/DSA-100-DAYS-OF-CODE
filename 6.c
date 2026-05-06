#include <stdio.h>

int main() {
    int n, i, j = 0;

    // Input size of array
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Remove duplicates
    for(i = 1; i < n; i++) {
        if(arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }

    // Print unique elements
    for(i = 0; i <= j; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}