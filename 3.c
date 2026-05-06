#include <stdio.h>

int main() {
    int n, k, i, found = 0, comparisons = 0;

    // Input size of array
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input key to search
    scanf("%d", &k);

    // Linear Search
    for(i = 0; i < n; i++) {
        comparisons++;

        if(arr[i] == k) {
            found = 1;
            break;
        }
    }

    // Output result
    if(found)
        printf("Found at index %d\n", i);
    else
        printf("Not Found\n");

    printf("Comparisons = %d", comparisons);

    return 0;
}