#include <stdio.h>

int canAllocate(int pages[], int n, int m, int maxPages) {
    int students = 1;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        if (sum + pages[i] > maxPages) {
            students++;
            sum = pages[i];

            if (students > m)
                return 0;
        } else {
            sum += pages[i];
        }
    }

    return 1;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int pages[n];
    int low = 0, high = 0, ans = -1;

    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);

        if (pages[i] > low)
            low = pages[i];

        high += pages[i];
    }

    if (m > n) {
        printf("-1");
        return 0;
    }

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canAllocate(pages, n, m, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    printf("%d", ans);

    return 0;
}