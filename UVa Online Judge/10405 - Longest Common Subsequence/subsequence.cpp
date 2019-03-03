//https://en.wikipedia.org/wiki/Longest_common_subsequence_problem

#include <iostream>
#include <string>

using namespace std;

int main() {
    string X, Y;
    while (getline(cin, X)) {
        getline(cin, Y);
        int m = X.length()+1, n = Y.length() + 1;
        int C[m][n];
        for (int i = 0; i < m; ++i)
            C[i][0] = 0;
        for (int i = 0; i < n; ++i)
            C[0][i] = 0;
        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
                if (X[i-1] == Y[j-1])
                    C[i][j] = C[i-1][j-1]+1;
                else
                    C[i][j] = C[i-1][j] > C[i][j-1] ? C[i-1][j] : C[i][j-1];
        cout << C[m-1][n-1] << '\n';
    }
    return 0;
}