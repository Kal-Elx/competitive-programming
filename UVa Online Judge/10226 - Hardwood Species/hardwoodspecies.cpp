#include <iostream>
#include <iomanip>
#include <string>
#include <map>

using namespace std;

int main() {
    string s;
    int u;

    cin >> u;
    cin.ignore();
    cin.ignore();

    for (int i = 0; i < u; ++i) {
        int t = 0;
        map<string, int> c;

        if (i != 0)
            cout << '\n';

        while (getline(cin, s)) {
            if (s.empty())
                break;

            ++c[s];
            ++t;
        }

        cout << setprecision(4) << fixed;
        for (auto it = c.begin(); it != c.end(); ++it) {
            double p = (100.0 * it->second) / t;
            cout << it->first << " " << p << endl;
        }
    }

    return 0;
}