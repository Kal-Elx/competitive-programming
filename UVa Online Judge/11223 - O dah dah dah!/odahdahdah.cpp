#include <iostream>
#include <sstream>
#include <string>
#include <map>

using namespace std;

map<string, char> table;

void init() {
    string translateInstructions("A .- J .--- S ... 1 .---- . .-.-.- : ---... B -... K -.- T - 2 ..--- , --..-- ; -.-.-. C -.-. L .-.. U ..- 3 ...-- ? ..--.. = -...- D -.. M -- V ...- 4 ....- ' .----. + .-.-. E . N -. W .-- 5 ..... ! -.-.-- - -....- F ..-. O --- X -..- 6 -.... / -..-. _ ..--.- G --. P .--. Y -.-- 7 --... ( -.--. H .... \" .-..-. Q --.- Z --.. 8 ---.. ) -.--.- @ .--.-. I .. R .-. 0 ----- 9 ----. & .-...");
    stringstream ss(translateInstructions);
    string key;
    char value;
    while (ss >> value >> key)
        table[key] = value;
}

int main() {
    init();
    int T;
    cin >> T;
    cin.ignore();

    for (int i = 1; i <= T; ++i) {
        if (i != 1)
            cout << '\n';
        cout << "Message #" << i << '\n';

        string in, out, buf, res;
        getline(cin, in);
        for (char c : in) {
            if (c == ' ') {
                if (buf.length() == 0)
                    out.push_back(' ');
                else {
                    out.push_back(table[buf]);
                    buf.clear();
                }
            } else
                buf.push_back(c);
        }
        if (buf.length() != 0)
            out.push_back(table[buf]);
        
        bool prevSpace = true;
        for (char c : out) {
            if (c == ' ') {
                if (!prevSpace)
                    res.push_back(c);
                prevSpace = true;
            } else {
                res.push_back(c);
                prevSpace = false;
            }
        }
        cout << res << '\n';
    }
    return 0;
}