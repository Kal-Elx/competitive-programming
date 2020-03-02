#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    bool winningPos[1000001];
    int moves[10];

    while (scanf("%d%d",&n, &m)!=EOF) {
        fill(winningPos, winningPos + n + 1, false);

        for (int i = 0; i < m; ++i) 
            scanf("%d", &moves[i]);
        
        for (int i = 1; i <= n; ++i)
            for (int j = 0; j < m; ++j)
                if (i >= moves[j] && !winningPos[i - moves[j]]) {
                    winningPos[i] = true;
                    break;
                }

        winningPos[n] ? printf("Stan wins\n") : printf("Ollie wins\n");
    }

    return 0;
}