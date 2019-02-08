#include <stdio.h>
#include <utility>

using namespace std;

bool region[100][100];
int m, n;

const pair<int, int> adjacent[8] = {make_pair(0, -1), make_pair(-1, -1),
                                    make_pair(-1, 0), make_pair(-1, 1),
                                    make_pair(0, 1), make_pair(1, 1),
                                    make_pair(1, 0), make_pair(1, -1)};

bool inRegion(int r, int c) {
    return r >= 0 && c >= 0 && r < m && c < n;
}

void analyze(int r, int c) {
    region[r][c] = false;
    for (pair<int, int> plot : adjacent) {
        int row = r + plot.first, col = c + plot.second;
        if (inRegion(row, col) && region[row][col])
            analyze(row, col);
    }
}

int main() {
    char plot;
    while (true) {
        scanf("%d %d\n", &m, &n);
        if (m == 0)
            break;

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                scanf(" %c", &plot);
                region[r][c] = plot == '@';
            }
        }

        int deposits = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (region[r][c]) {
                    ++deposits;
                    analyze(r, c);
                }
            }
        }
        printf("%d\n", deposits);
    }

    return 0;
}