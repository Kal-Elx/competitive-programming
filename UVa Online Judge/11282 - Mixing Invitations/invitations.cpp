#include <stdio.h>

long long derangements[21] = {1, 0, 1, 2, 9, 44, 265, 1854, 14833, 133496,
                              1334961, 14684570, 176214841, 2290792932,
                              32071101049, 481066515734, 7697064251745, 
                              130850092279664, 2355301661033953, 
                              44750731559645106, 895014631192902121};

long long combinations(int n, int r) {
    if (n == r || r == 0)
        return 1;

    if (r * 2 > n)
        r = n - r;
    
    long long res = n;
    for(int i = 2; i <= r; ++i) {
        res *= (n-i+1);
        res /= i;
    }

    return res;
}

int main() {
    int N, M;

    while (scanf("%d %d", &N, &M) != EOF) {
        long long res = 0;
        for (int i = M; i >= 0; --i)
            res += combinations(N, i) * derangements[N-i];;
        printf("%lld\n", res);
    }
    
    return 0;
}