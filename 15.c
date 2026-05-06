#include <stdio.h>

int main() {
    int m, n, i, j;
    int sum = 0;

    scanf("%d %d", &m, &n);

    int a[m][n];

    // Input matrix
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Calculate primary diagonal sum
    for(i = 0; i < m && i < n; i++) {
        sum = sum + a[i][i];
    }

    printf("%d", sum);

    return 0;
}
