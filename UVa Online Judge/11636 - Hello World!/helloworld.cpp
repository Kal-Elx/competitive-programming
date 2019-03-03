#include <stdio.h>
#include <math.h>

int main() {
    int N, X = 0, Y;
    while (scanf("%d", &N)) {
        if (N < 0)
            break;
        for (Y = 0; N > pow(2, Y); ++Y) {};
        printf("Case %d: %d\n", ++X, Y);
    }
    return 0;
}