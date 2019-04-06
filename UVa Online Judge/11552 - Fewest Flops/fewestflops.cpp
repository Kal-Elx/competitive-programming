#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

struct part {
    int cnt;
    set<char> chunks;
};

int main() {
    int t, k;
    string S;

    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> k >> S;
        vector<part> parts;

        for (int j = 0, l = 0; j < S.length(); j += k, ++l) {
            part c;
            for (int m = j; m < j+k; ++m)
                c.chunks.insert(S[m]);
            c.cnt = c.chunks.size();
            parts.push_back(c);
        }

        int res = 0;
        for (int j = 0; j < parts.size()-1; ++j) {
            set<char> u;
            u.insert(parts[j].chunks.begin(), parts[j].chunks.end());
            u.insert(parts[j+1].chunks.begin(), parts[j+1].chunks.end());
            int diff = parts[j].chunks.size() + parts[j+1].chunks.size() - u.size();

            if (diff == 0) {
                res += parts[j].cnt;
            } else if (diff == 1 && parts[j+1].cnt != 1) {
                set<char> new_letters;
                set_difference(parts[j+1].chunks.begin(), parts[j+1].chunks.end(), parts[j].chunks.begin(), parts[j].chunks.end(), inserter(new_letters, new_letters.end()));
                parts[j+1].chunks = new_letters;
                res += parts[j].cnt-1;
            } else {
                res += parts[j].cnt-1;
            }
        }
        res += parts[parts.size()-1].cnt;
        cout << res << endl;
    }
    
    return 0;
}