#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int position;
    int speed;
} Car;

int compare(const void *a, const void *b) {
    Car *c1 = (Car *)a;
    Car *c2 = (Car *)b;

    return c2->position - c1->position;  // descending order
}

int carFleet(int target, int position[], int speed[], int n) {
    Car cars[n];

    for (int i = 0; i < n; i++) {
        cars[i].position = position[i];
        cars[i].speed = speed[i];
    }

    qsort(cars, n, sizeof(Car), compare);

    int fleets = 0;
    double maxTime = 0.0;

    for (int i = 0; i < n; i++) {
        double time = (double)(target - cars[i].position) / cars[i].speed;

        if (time > maxTime) {
            fleets++;
            maxTime = time;
        }
    }

    return fleets;
}

int main() {
    int n, target;

    scanf("%d", &target);
    scanf("%d", &n);

    int position[n], speed[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &position[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &speed[i]);
    }

    printf("%d", carFleet(target, position, speed, n));

    return 0;
}