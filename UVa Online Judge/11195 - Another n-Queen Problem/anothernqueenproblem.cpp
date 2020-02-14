#include <stdio.h>
#include <utility>
#include <algorithm>

#define MAX_SIZE 15

using namespace std;

int n, res = 0;
char t;
bool board[MAX_SIZE][MAX_SIZE];
bool row[MAX_SIZE];
bool diagonalL[2*MAX_SIZE - 1];
bool diagonalR[2*MAX_SIZE - 1];

pair<int, int> getDiagonals(int r, int c) {
    int dl = r + c;
    int dr = n - 1 - r + c;
    return make_pair(dl, dr);
}

bool canPlace(int r, int c, int dl, int dr) {
    return !(board[r][c] || row[r] || diagonalL[dl] || diagonalR[dr]);
}

bool solve(int c) {
    if (c >= n) {
        ++res;
        return true;
    }

    bool foundSolution = false;
    for (int r = 0; r < n; ++r) {
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
    int tc = 0;
    while (scanf("%d", &n) != EOF) {
        if (n == 0)
            break;

        for (int i = 0; i < n; ++i)
            fill(board[i], board[i] + n, false);
        fill(row, row + n, false);
        fill(diagonalL, diagonalL + 2*n - 1, false);
        fill(diagonalR, diagonalR + 2*n - 1, false);
        res = 0;

        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                scanf(" %c", &t);
                if (t == '*')
                    board[r][c] = true;
            }
        }

        solve(0);

        printf("Case %d: %d\n", ++tc, res);
    }

    return 0;
}