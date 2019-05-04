#include <stdio.h>

int main() {
    int M, N;
    while(scanf("%d %d", &M, &N) != EOF)
        printf("%d\n", N-1 + N*(M-1));
    return 0;
}