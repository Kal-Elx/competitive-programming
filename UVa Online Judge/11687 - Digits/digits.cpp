#include <iostream>
#include <string>

using namespace std;

int main() {
    string x;
    while (cin >> x) {
        if (x == "END")
            break;

        if (x == "1") {
            cout << 1 << '\n';
            continue;
        }

        int i;
        for (i = 2; x.length() > 1; ++i) {
            x = to_string(x.length());
        }

        cout << i << '\n';
    }
    return 0;
}