#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main() {
int n, cmd, x = 0;

    while (cin >> n) {
        queue<int> q;
        priority_queue<int> p;
        stack<int> s;
        bool isQ = true;
        bool isP = true;
        bool isS = true;

        for (int i = 0; i < n; ++i) {
            cin >> cmd >> x;
            if (cmd == 1) {
                if (isQ) q.push(x);
                if (isP) p.push(x);
                if (isS) s.push(x);
            } else {
                if (isQ) {
                    if (!q.empty()) {
                        isQ = (x == q.front());
                        q.pop();
                    } else
                        isQ = false;
                }
                if (isP) {
                    if (!p.empty()) {
                        isP = (x == p.top());
                        p.pop();
                    } else
                        isP = false;
                }
                if (isS) {           
                    if (!s.empty()) {
                        isS = (x == s.top());
                        s.pop();
                    } else
                        isS = false;
                }
            }
        }
        switch (isQ + isP + isS) {
            case 0:
                cout << "impossible" << endl;
                break;
            case 1:
                if (isQ) cout << "queue" << endl;
                else if (isP) cout << "priority queue" << endl;
                else cout << "stack" << endl;
                break;
            case 2:
            case 3:
                cout << "not sure" << endl;
                break;
        }
    }
    return 0;
}
