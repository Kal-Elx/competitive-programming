#include <stdio.h>

int main() {
    int n, f, s, a, e, res;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        res = 0;
        scanf("%d", &f);
        for (int j = 0; j < f; ++j) {
            scanf("%d %d %d", &s, &a, &e);
            res += s*e;
        }
        printf("%d\n", res);
    }
    return 0;
}