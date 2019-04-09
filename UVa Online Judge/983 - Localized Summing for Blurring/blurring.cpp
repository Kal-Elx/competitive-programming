#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
    int N, M, X, T = 0;
    while(scanf("%d %d", &N, &M) != EOF) {
        if (++T != 1)
            printf("\n");

        unsigned long res[N-M+1][N-M+1];
        for (int R = 0; R < N-M+1; ++R)
            for (int C = 0; C < N-M+1; ++C)
                res[R][C] = 0;


        for (int R = 0; R < N; ++R)
            for (int C = 0; C < N; ++C) {
                scanf("%d", &X);
                for (int r = max(R-M+1,0); r <= min(R,N-M); ++r)
                    for (int c = max(C-M+1,0); c <= min(C,N-M) ; ++c)
                        res[r][c] += X;
            }

        unsigned long sum = 0;
        for (int R = 0; R < N-M+1; ++R)
            for (int C = 0; C < N-M+1; ++C) {
                sum += res[R][C];
                printf("%ld\n", res[R][C]);
            }
        printf("%ld\n", sum);
    }

    return 0;
}