#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, m, x, c = 0;

    while (cin >> n) {
        ++c;
        cout << "Case " << c << ':' << '\n';

        vector<int> num(n);
        for (int i = 0; i < n; ++i) {
            cin >> x;
            num[i] = x;
        }
        sort(num.begin(), num.end());

        cin >> m;
        for (int i = 0; i < m; ++i) {
            cin >> x;
            int champion = -1;
            for (int j = 0; j < n - 1; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    int sum = num[j] + num[k];
                    champion = (abs(x - sum) < abs(x - champion) || champion < 0 ? sum : champion);
                    if (sum >= x)
                        break;
                }
                if (champion == x)
                    break;
            }
            cout << "Closest sum to " << x << " is " << champion << ".\n";
        }
    }

    return 0;
}