#include <stdio.h>

int canPaint(int boards[], int n, int k, int maxTime) {
    int painters = 1;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        if (sum + boards[i] > maxTime) {
            painters++;
            sum = boards[i];

            if (painters > k)
                return 0;
        } else {
            sum += boards[i];
        }
    }

    return 1;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int boards[n];
    int low = 0, high = 0, ans = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);

        if (boards[i] > low)
            low = boards[i];

        high += boards[i];
    }

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canPaint(boards, n, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    printf("%d", ans);

    return 0;
}