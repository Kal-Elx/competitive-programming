#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

long long unsigned palindrom(long long unsigned x) {
    string str = to_string(x);
    reverse(str.begin(), str.end());
    return stoi(str);
}

bool isPalindrom(long long unsigned x) {
    string str = to_string(x);
    for (int i = 0, j = str.length() - 1; i < str.length()/2; ++i, --j)
        if (str[i] != str[j])
            return false;
    return true;
}

int main() {
    int N;
    long long unsigned P;
    scanf("%d", &N);

    for (int i = 0; i < N; ++i) {
        scanf("%lld", &P);
        int iterations = 0;
        do {
            P = P + palindrom(P);
            ++iterations;
        } while (!isPalindrom(P));
        printf("%d %lld\n", iterations, P);
    }

    return 0;
}