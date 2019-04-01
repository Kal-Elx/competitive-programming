#include <stdio.h>
#include <vector>

using namespace std;

struct soldier {
    int left, right;
};

int main() {
    int S, B, L, R;
    while (scanf("%d %d", &S, &B)) {
        if (S == 0 && B == 0)
            break;

        vector<soldier> soldiers(S+1);
        for (int i = 1; i < S+1; ++i) {
            soldiers[i].left = i-1;
            soldiers[i].right = i+1;
        }
        soldiers[0].left = 0;
        soldiers[0].right = 0;
        soldiers[1].left = 0;
        soldiers[S].right = 0;

        for (int i = 0; i < B; ++i) {
            scanf("%d %d", &L, &R);
            soldiers[soldiers[L].left].right = soldiers[R].right;
            soldiers[soldiers[R].right].left = soldiers[L].left;
            if (soldiers[L].left != 0)
                printf("%d ", soldiers[L].left);
            else
                printf("* ");
            if (soldiers[R].right != 0)
                printf("%d\n", soldiers[R].right);
            else
                printf("*\n");
        }
        printf("-\n");
    }
    return 0;
}