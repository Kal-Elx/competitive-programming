#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    string s;
    int t = 0;
    map<string, int> c;

    while (getline(cin, s)) {
        ++c[s];
        ++t;
    }

    for (auto it = c.begin(); it != c.end(); ++it) {
        double p = (100.0 * it->second) / t;
        cout << it->first << " " << p << endl;
    }

    return 0;
}