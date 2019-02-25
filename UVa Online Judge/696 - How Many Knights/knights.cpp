#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
    int M, N, res;
    while (scanf("%d %d", &M, &N)) {
        if (M == 0 && N == 0)
            break;
        else if (M == 0 || N == 0)
            res = 0;
        else if (M == 1 || N == 1)
            res = max(M, N);
        else if (M == 2 || N == 2) {
            res = (max(M, N)/4)*4;
            if (max(M, N)%4 == 3)
                res += 4;
            else
                res += (max(M, N)%4)*2;
        }
        else
            res = M*N/2 + (M*N)%2;
            
        printf("%d knights may be placed on a %d row %d column board.\n", res, M, N);
    }
    return 0;
}