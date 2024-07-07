#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    cin.ignore(); // Consume the newline character

    int res = 0;
    for (int i = 0; i < n; ++i) {
        string row;
        getline(cin, row);
        for (int j = 0; j < m; ++j) {
            switch (row[j]) {
                case '.':
                    res += 20;
                    break;
                case 'O':
                    res += 10;
                    break;
                case '\\':
                case '/':
                    res += 25;
                    break;
                case 'A':
                    res += 35;
                    break;
                case '^':
                    res += 5;
                    break;
                case 'v':
                    res += 22;
                    break;
                default:
                    res += 0;
                    break;
            }
        }
    }

    cout << res << endl;

    return 0;
}
