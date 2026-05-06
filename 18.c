#include <stdio.h>

int main() {
    int n, k, i;
    
    scanf("%d", &n);
    
    int arr[n], rotated[n];
    
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    scanf("%d", &k);
    
    k = k % n;

    for(i = 0; i < n; i++) {
        rotated[(i + k) % n] = arr[i];
    }

    for(i = 0; i < n; i++) {
        printf("%d ", rotated[i]);
    }

    return 0;
}