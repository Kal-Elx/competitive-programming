#include <iostream>
#include <string>

using namespace std;

int main() {
    string in;
    while(getline(cin, in)) {
        string ISBN;
        bool valid = true;
        int s1 = 0, s2 = 0, cnt = 0, i, j;

        for (i = 0; i < in.length() && in[i] == ' '; ++i);
        for (j = in.length()-1; j > i && in[j] == ' '; --j);

        for (char c : in.substr(i, j-i+1)) {
            if (c >= '0' && c <= '9') {
                s1 += c - '0';
                s2 += s1;
                ++cnt;
            } else if (c == 'X' && cnt == 9) {
                s1 += 10;
                s2 += s1;
                ++cnt;
            } else if (c != '-' && c != ' ')
                valid = false;
            ISBN.push_back(c);
        }
        
        if (valid && cnt == 10 && s2 % 11 == 0)
            cout << ISBN << " is correct.\n";
        else
            cout << ISBN << " is incorrect.\n";
    }
    return 0;
}