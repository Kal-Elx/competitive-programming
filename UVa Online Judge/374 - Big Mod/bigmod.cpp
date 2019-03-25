//https://en.wikibooks.org/wiki/Algorithm_Implementation/Mathematics/Modular_Exponentiation

#include <stdio.h>

int main() {
    int P, M;
    long long B, R;
    while (scanf("%lld %d %d", &B, &P, &M) != EOF) {
        R = 1;
        while (P != 0) {
            if (P % 2 == 1)
                R = (R * B) % M;
            P /= 2;
            B = (B*B) % M;
        }
        printf("%lld\n", R);
    }
    return 0;
}