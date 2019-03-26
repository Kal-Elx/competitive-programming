#include <stdio.h>

const int MAX_LENGTH = 50;
long long saved[MAX_LENGTH+1];

long long patterns(int l) {
    if (saved[l] != -1)
        return saved[l];
    long long res = 0;
    if (l >= 1) {
        res += patterns(l-1);
    }
    if (l >= 2) {
        res += patterns(l-2);
    }
    saved[l] = res;
    return res;    
}

int main() {
    int l;
    saved[0] = 1;
    for (int i = 1; i <= MAX_LENGTH; ++i)
        saved[i] = -1;
    
    while (scanf("%d", &l)) {
        if (l == 0)
            break;
        printf("%lld\n", patterns(l));
    }
    return 0;
}