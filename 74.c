#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char name[50];
    int count;
} Candidate;

int main() {
    int n;
    scanf("%d", &n);

    char vote[50];
    Candidate candidates[MAX];
    int size = 0;

    for (int i = 0; i < n; i++) {
        scanf("%s", vote);

        int found = 0;

        for (int j = 0; j < size; j++) {
            if (strcmp(candidates[j].name, vote) == 0) {
                candidates[j].count++;
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(candidates[size].name, vote);
            candidates[size].count = 1;
            size++;
        }
    }

    char winner[50];
    int maxVotes = 0;

    strcpy(winner, candidates[0].name);
    maxVotes = candidates[0].count;

    for (int i = 1; i < size; i++) {
        if (candidates[i].count > maxVotes) {
            maxVotes = candidates[i].count;
            strcpy(winner, candidates[i].name);
        }
        else if (candidates[i].count == maxVotes) {
            if (strcmp(candidates[i].name, winner) < 0) {
                strcpy(winner, candidates[i].name);
            }
        }
    }

    printf("%s %d", winner, maxVotes);

    return 0;
}