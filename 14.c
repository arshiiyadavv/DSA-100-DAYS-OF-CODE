#include <stdio.h>

int main() {
    int n, i, j;
    int identity = 1;

    scanf("%d", &n);

    int a[n][n];

    // Input matrix
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Check identity matrix condition
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {

            // Diagonal elements should be 1
            if(i == j && a[i][j] != 1) {
                identity = 0;
                break;
            }

            // Non-diagonal elements should be 0
            if(i != j && a[i][j] != 0) {
                identity = 0;
                break;
            }
        }

        if(identity == 0)
            break;
    }

    if(identity)
        printf("Identity Matrix");
    else
        printf("Not an Identity Matrix");

    return 0;
}
