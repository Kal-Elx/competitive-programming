#include <stdio.h>
#include <vector>

int main() {
    int n, h, c = 0;
    while (scanf("%d", &n)) {
        if (n == 0)
            break;

        std::vector<int> stacks(n);
        int sum = 0, k = 0;

        for (int i = 0; i < n; ++i) {
            scanf("%d", &h);
            sum += h;
            stacks[i] = h;
        }
        
        int average = sum / n;
        for (int stack : stacks)
            if (stack > average)
                k += (stack-average);

        printf("Set #%d\nThe minimum number of moves is %d.\n\n", ++c, k);
    }
    
    return 0;
}