#include <stdio.h>
#include <algorithm>

using namespace std;

int M, N, res;
bool forest[100][100];

void findRect(int r, int c) {
    int currR = r, currC, maxC = N - 1;
    while (currR < M && forest[currR][c] == 0) {
        currC = c;
        while (currC + 1 <= maxC && forest[currR][currC + 1] == 0)
            currC += 1;
        maxC = currC;
        res = max(res, (currR + 1 - r) * (currC + 1 - c));
        currR += 1;
    }
}

int main() {
    int t;
    while (scanf("%d %d", &M, &N)) {
        if (M == 0 && N == 0)
            break;
        res = 0;

        for (int r = 0; r < M; ++r)
            for (int c = 0; c < N; ++c)
                scanf("%d", &forest[r][c]);

        for (int r = 0; r < M; ++r)
            for (int c = 0; c < N; ++c)
                findRect(r, c);

        printf("%d\n", res);
    }
    return 0;
}