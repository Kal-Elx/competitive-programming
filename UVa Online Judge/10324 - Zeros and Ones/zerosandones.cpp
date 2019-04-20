#include <iostream>
#include <string>

using namespace std;

int table[1000000];

int main() {
    int a, b, n, t = 0;
    string in;

    while(cin >> in) {
        cout << "Case " << ++t << ":\n"; 
        
        table[0] = 0;
        for (int i = 1; i < in.length(); ++i)
            table[i] = in[i] == in[i-1] ? table[i-1] : i;
        
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a >> b;
            if (table[a] == table[b])
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }

    return 0;
}