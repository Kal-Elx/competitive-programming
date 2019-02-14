#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
    int N, X, Y, Z;
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        scanf("%d %d %d", &X, &Y, &Z);
        int max = min(X, min(Y, Z));
        int min = ceil((X + Y + Z - 100.0)/2);
        min = min >= 0 ? min : 0;
        max >= min ? printf("Case #%d: Between %d and %d times.\n", i, min, max) : printf("Case #%d: The records are faulty.\n", i);
    }
    return 0;
}