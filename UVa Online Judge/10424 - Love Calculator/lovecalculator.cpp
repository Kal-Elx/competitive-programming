#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int sumDigits(int x) {
    while (x > 9) {
        string str = to_string(x);
        x = 0;
        for (char c : str)
            x += (c-'0');
    }
    return x;
}

int calc(const string& name) {
    int res = 0;
    for (char c : name) {
        if (c >= 65 && c <= 90)
            res += c - 64;
        else if (c >= 97 && c <= 122)
            res += c - 96;
    }
    return sumDigits(res);
}

int main() {
    string s1, s2;
    while (getline(cin, s1)) {
        getline(cin, s2);
        int sum1 = calc(s1);
        int sum2 = calc(s2);
        double res = 0;
        if (sum1 < sum2)
            res = (double) sum1 / sum2;
        else
            res = (double) sum2 / sum1;
        res *= 100;
        cout << setprecision(2) << fixed << res << " %" << endl;
    }
    return 0;
}