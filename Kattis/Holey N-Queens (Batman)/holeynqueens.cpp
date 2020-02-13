#include <stdio.h>
#include <set>
#include <unordered_set>
#include <utility>
#include <vector>
#include <algorithm>

#define MAX_SIZE 12

using namespace std;

int N, M, R, C, res = 0;
set<pair<int, int>> holes;
bool board[MAX_SIZE][MAX_SIZE];
unordered_set<int> row;
unordered_set<int> diagonalL;
unordered_set<int> diagonalR;

pair<int, int> getDiagonals(int r, int c) {
    int dl = r + c;
    int dr = N - 1 - r + c;
    return make_pair(dl, dr);
}

bool canPlace(int r, int c, int dl, int dr) {
    return row.find(r) == row.end() && diagonalL.find(dl) == diagonalL.end() && diagonalR.find(dr) == diagonalR.end() && holes.find(make_pair(r, c)) == holes.end();
}

bool solve(int c) {
    if (c >= N) {
        ++res;
        return true;
    }

    bool foundSolution = false;
    for (int r = 0; r < N; ++r) {
        pair<int, int> d = getDiagonals(r, c);
        if (canPlace(r, c, d.first, d.second)) {
            board[r][c] = true;
            row.insert(r);
            diagonalL.insert(d.first);
            diagonalR.insert(d.second);
            foundSolution = foundSolution | solve(c+1);
            board[r][c] = false;
            row.erase(r);
            diagonalL.erase(d.first);
            diagonalR.erase(d.second);
        }
    }

    return foundSolution;
}

int main() {
    bool first = true;
    while (scanf("%d %d", &N, &M) != EOF) {
        if (N == 0 && M == 0)
            break;

        if (first)
            first = false;
        else
            printf("\n");
        
        holes.clear();
        row.clear();
        diagonalR.clear();
        diagonalL.clear();
        res = 0;

        for (int i = 0; i < N; ++i) {
            fill(board[i], board[i] + MAX_SIZE, false);
        }

        for (int i = 0; i < M; ++i) {
            scanf("%d %d", &R, &C);
            holes.insert(make_pair(R, C));
        }

        solve(0);

        printf("%d", res);
    }

    return 0;
}