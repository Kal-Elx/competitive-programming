#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct vertex {
    bool inQueue = false;
    bool color;
    vector<int> neighbours;
};

int main() {
    int n, l, a, b;
    while (cin >> n) {
        if (n == 0)
            break;

        vector<vertex> v(n);
        cin >> l;
        
        for (int i = 0; i < l; ++i) {
            cin >> a >> b;
            v[a].neighbours.push_back(b);
            v[b].neighbours.push_back(a);
        }
        
        bool bicolorable = true;
        queue<int> q;
        q.push(0);
        v[0].inQueue = true;
        v[0].color = true;
        
        while (!q.empty()) {
            vertex& curr = v[q.front()];
            q.pop();
            for (int n : curr.neighbours) {
                if (v[n].inQueue) {
                    if (v[n].color == curr.color) {
                        bicolorable = false;
                        break;
                    }
                } else {
                    v[n].color = !curr.color;
                    q.push(n);
                    v[n].inQueue = true;
                }
            }
        }
        if (bicolorable)
            printf("BICOLORABLE.\n");
        else
            printf("NOT BICOLORABLE.\n");
    }
    return 0;
}