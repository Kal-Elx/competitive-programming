#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map<int, int> fibonacci;

int main() {
    // Build Fibonacci Sequence
    int a = 0, b = 1;
    for (int i = 0; i < 45; ++i) {
        int sum = a+b;
        fibonacci[sum] = i;
        a = b;
        b = sum;
    }

    int T, N, F, maxF = 0;
    string in;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> N;
        vector<int> num(N);
        for (int j = 0; j < N; ++j) {
            cin >> F;
            maxF = max(maxF, F);
            num[j] = F;
        }
        string out(fibonacci[maxF] + 1, ' ');
        cin.ignore();
        getline(cin, in);
        for (int j = 0, k = 0; j < in.length() && k < N; ++j)
            if (in[j] >= 65 && in[j] <= 90) {
                out[fibonacci[num[k]]] = in[j];
                ++k;
            }
        for (int j = out.length() - 1; j >= 0; --j)
            if (out[j] == ' ')
                out.pop_back();
            else
                break;
        cout << out << '\n';
    }
    return 0;
}