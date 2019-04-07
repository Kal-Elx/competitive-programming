//https://en.m.wikipedia.org/wiki/Kruskal%27s_algorithm

#include <stdio.h>
#include <vector>
#include <algorithm>

#define edge pair<pair<int, int>, int>

using namespace std;

int sites[10000001];

int find(int a) {
    while (sites[a] != -1)
        a = sites[a];
    return a;
}

bool uni(int a, int b) {
    int r1 = find(a);
    int r2 = find(b);
    if (r1 != r2) {
        sites[r1] = r2;
        return true;
    }
    return false; 
}

bool comp (edge a, edge b) {
    return a.second < b.second;
}

int main() {
    int N, K, M, a, b, c, res1, res2, tc = 0;
    while (scanf("%d", &N) != EOF) {
        if (++tc != 1)
            printf("\n");

        for (int i = 1; i < N+1; ++i)
            sites[i] = -1;

        vector<edge> edges;
        res1 = 0;
        res2 = 0;

        for (int i = 0; i < N-1; ++i) {
            scanf("%d %d %d", &a, &b, &c);
            res1 += c;
        }

        scanf("%d", &K);
        for (int i = 0; i < K; ++i) {
            scanf("%d %d %d", &a, &b, &c);
            edges.push_back(make_pair(make_pair(a, b), c));
        }

        scanf("%d", &M);
        for (int i = 0; i < M; ++i) {
            scanf("%d %d %d", &a, &b, &c);
            edges.push_back(make_pair(make_pair(a, b), c));
        }

        sort(edges.begin(), edges.end(), comp);
        int cnt = 0;
        for (edge e : edges) {
            if (uni(e.first.first, e.first.second)) {
                res2 += e.second;
                ++cnt;
            }
            if (cnt == N-1)
                break;
        }
        printf("%d\n%d\n", res1, res2);
    }
    return 0;
}