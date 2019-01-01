#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<int, string> a, pair<int, string> b) {
    return a.first < b.first;
}

int getInversions(const string& str) {
    int res = 0;
    for (int i = 0; i < str.length() - 1; ++i)
        for (int j = i + 1; j < str.length(); ++j)
            if (str[i] > str[j])
                ++res;
    return res;
}

int main() {
    int M, m, n;
    string str;
    cin >> M;

    for (int i = 0; i < M; ++i) {
        if (i > 0)
            cout << '\n';
        cin >> m >> n;

        vector<pair<int, string>> set(n);
        for (int j = 0; j < n; ++j) {
            cin >> str;
            set[j] = make_pair(getInversions(str), str);
        }

        stable_sort(set.begin(), set.end(), comp);

        for (pair<int, string> elem : set)
            cout << elem.second << '\n';
    }

    return 0;
}