#include <stdio.h>

int main() {
    unsigned long long a, b;

    while (scanf("%lld%lld", &a, &b)!=EOF)
        a > b ? printf("%lld\n", a - b) : printf("%lld\n", b - a);

    return 0;
}