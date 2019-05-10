#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int N, D;
    string in, out;
    while (cin >> N >> D) {
        if (N == 0 && D == 0)
            break;
        out.clear();
        cin >> in;
        for (int i = 0, j = N-D-1; i < N && j >= 0; ++i, --j) {
            int l = i;
            for (int k = i; k < N-j; ++k)
                l = in[k] > in[l] ? k : l;
            out.push_back(in[l]);
            i = l;
        }
        cout << out << '\n';
    }
    
    return 0;
}