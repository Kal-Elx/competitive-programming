#include <stdio.h>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int main() {
    int N, M, s, d, res;

    while (scanf("%d %d", &N, &M) != EOF) {
        if (N == 0 && M == 0)
            break;

        vector<pair<int, int>> calls;

        for (int i = 0; i < N; ++i) {
            scanf("%*d %*d %d %d", &s, &d);
            calls.push_back(make_pair(s, s+d));
        }

        for (int i = 0; i < M; ++i) {
            scanf("%d %d", &s, &d);
            res = 0;
            
            for (pair<int, int> c : calls)
                if ((s <= c.first && s+d > c.first) || (s < c.second && s+d >= c.second) || (s > c.first && s+d < c.second))
                    ++res;

            printf("%d\n", res);
        }
    }
    

    return 0;
}