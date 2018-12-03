/*
 * Using UNION/FIND
 */

#include <iostream>

using namespace std;

int nodes[10000];
long debt[10000]; // Need to hold 500000000 (50000 * 10000)

int find(int x) {
    while (nodes[x] != -1)
        x = nodes[x];
    return x;
}

void unionTrees(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        nodes[rootX] = rootY;
        debt[rootY] += debt[rootX];
        debt[rootX] = 0;
    }
}

int main() {
    int n, m, x, y;
    
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> debt[i];
        nodes[i] = -1;
    }
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        unionTrees(x, y);
    }

    bool possible = true;
    for (int i = 0; i < n; ++i) {
        if (debt[i] != 0) {
            possible = false;
            break;
        }
    }

    if (possible)
        cout << "POSSIBLE" << endl;
    else
        cout << "IMPOSSIBLE" << endl;

    return 0;
}