#include <stdio.h>

int main() {
    int n;
    while (scanf("%d", &n)) {
        if (n == 0)
            break;
        if (n%2 == 1 || n == 2) {
            printf("Impossible\n");
            continue;
        }
        printf("%d\n", n+n/2);
        for (int i = 1, j = 2; i <= n; ++i, j = j%n+1)
            printf("%d %d\n", i, j);
        for (int i = 1, j = n/2+1; i <= n/2; ++i, j = j%n+1)
            printf("%d %d\n", i, j);
    }
    return 0;
}