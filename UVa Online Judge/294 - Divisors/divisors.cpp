//https://www.geeksforgeeks.org/count-divisors-n-on13/

#include <stdio.h>
#include <math.h>

using namespace std;

int divisors(int n) 
{ 
    int res = 0; 
    for (int i = 1; i <= sqrt(n); ++i) { 
        if (n % i == 0) { 
            if (n / i == i) 
                ++res; 
            else
                res += 2; 
        } 
    } 
    return res;
} 

int main() { 
    int N, L, U, D, P;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d %d", &L, &U);
        D = 0;
        P = L;
        for (int j = L; j <= U; ++j) {
            int curr = divisors(j);
            if (D < curr) {
                P = j;
                D = curr;
            }
        }
        printf("Between %d and %d, %d has a maximum of %d divisors.\n", L, U, P, D);
    }
    return 0; 
} 