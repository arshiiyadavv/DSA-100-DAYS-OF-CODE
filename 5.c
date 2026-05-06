#include <stdio.h>

int main() {
    int p, q, i, j, k;

    // Input size of first array
    scanf("%d", &p);

    int arr1[p];

    // Input elements of first array
    for(i = 0; i < p; i++) {
        scanf("%d", &arr1[i]);
    }

    // Input size of second array
    scanf("%d", &q);

    int arr2[q];

    // Input elements of second array
    for(i = 0; i < q; i++) {
        scanf("%d", &arr2[i]);
    }

    int merged[p + q];

    i = 0;
    j = 0;
    k = 0;

    // Merge two sorted arrays
    while(i < p && j < q) {
        if(arr1[i] < arr2[j]) {
            merged[k] = arr1[i];
            i++;
        } else {
            merged[k] = arr2[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of arr1
    while(i < p) {
        merged[k] = arr1[i];
        i++;
        k++;
    }

    // Copy remaining elements of arr2
    while(j < q) {
        merged[k] = arr2[j];
        j++;
        k++;
    }

    // Print merged array
    for(i = 0; i < p + q; i++) {
        printf("%d ", merged[i]);
    }

    return 0;
}