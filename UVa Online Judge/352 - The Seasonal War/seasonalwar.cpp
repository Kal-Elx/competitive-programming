#include <stdio.h>
#include <utility>

using namespace std;

bool image[25][25];
int D;

const pair<int, int> adjacent[8] = {make_pair(0, -1), make_pair(-1, -1),
                                    make_pair(-1, 0), make_pair(-1, 1),
                                    make_pair(0, 1), make_pair(1, 1),
                                    make_pair(1, 0), make_pair(1, -1)};

bool inImage(int r, int c) {
    return r >= 0 && r < D && c >= 0 && c < D;
}

bool explore(int r, int c) {
    if (inImage(r, c) && image[r][c]) {
        image[r][c] = 0;
        for (pair<int, int> pixel : adjacent)
            explore(r + pixel.first, c + pixel.second);
        return true;
    }
    return false;
}

int main() {
    char x, i = 0;
    while (scanf("%d", &D) != EOF) {
        int res = 0;
        for (int r = 0; r < D; ++r)
            for (int c = 0; c < D; ++c) {
                scanf(" %c", &x);
                image[r][c] = x == '1';
            }
        for (int r = 0; r < D; ++r)
            for (int c = 0; c < D; ++c)
                res += explore(r, c);
        printf("Image number %d contains %d war eagles.\n", ++i, res);
    }
    return 0;
}