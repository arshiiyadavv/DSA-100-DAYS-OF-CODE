#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int left, right, palindrome = 1;

    scanf("%s", str);

    left = 0;
    right = strlen(str) - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            palindrome = 0;
            break;
        }
        left++;
        right--;
    }

    if (palindrome)
        printf("YES");
    else
        printf("NO");

    return 0;
}