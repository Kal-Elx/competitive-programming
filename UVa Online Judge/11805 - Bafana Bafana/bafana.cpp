#include <stdio.h>

int main()
{
    int T, N, K, P;
    scanf("%d", &T);

    for (int i = 1; i <= T; ++i) {
        scanf("%d %d %d", &N, &K, &P);
        int R = (P + K) % N;
        printf("Case %d: %d\n", i, R != 0 ? R : N);
    }

    return 0;
}
