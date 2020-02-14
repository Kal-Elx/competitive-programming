#include <stdio.h>
#include <utility>
#include <algorithm>

#define MAX_SIZE 12

using namespace std;

int N, M, R, C, res = 0;
bool board[MAX_SIZE][MAX_SIZE];
bool row[MAX_SIZE];
bool diagonalL[2*MAX_SIZE - 1];
bool diagonalR[2*MAX_SIZE - 1];

pair<int, int> getDiagonals(int r, int c) {
    int dl = r + c;
    int dr = N - 1 - r + c;
    return make_pair(dl, dr);
}

bool canPlace(int r, int c, int dl, int dr) {
    return !(board[r][c] || row[r] || diagonalL[dl] || diagonalR[dr]);
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
            row[r] = true;
            diagonalL[d.first] = true;
            diagonalR[d.second] = true;
            foundSolution = foundSolution | solve(c+1);
            board[r][c] = false;
            row[r] = false;
            diagonalL[d.first] = false;
            diagonalR[d.second] = false;
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

        for (int i = 0; i < N; ++i)
            fill(board[i], board[i] + MAX_SIZE, false);
        fill(row, row + MAX_SIZE, false);
        fill(diagonalL, diagonalL + 2*MAX_SIZE - 1, false);
        fill(diagonalR, diagonalR + 2*MAX_SIZE - 1, false);
        res = 0;

        for (int i = 0; i < M; ++i) {
            scanf("%d %d", &R, &C);
            board[R][C] = true;
        }

        solve(0);

        printf("%d", res);
    }

    return 0;
}