#include <stdio.h>

int main() {
    int m, n, i, j;
    int symmetric = 1;

    scanf("%d %d", &m, &n);

    int a[m][n];

    // Input matrix
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Check if matrix is square
    if(m != n) {
        symmetric = 0;
    }
    else {
        // Check symmetry
        for(i = 0; i < m; i++) {
            for(j = 0; j < n; j++) {
                if(a[i][j] != a[j][i]) {
                    symmetric = 0;
                    break;
                }
            }
            if(symmetric == 0)
                break;
        }
    }

    if(symmetric)
        printf("Symmetric Matrix");
    else
        printf("Not a Symmetric Matrix");

    return 0;
}