// Kahn's algorithm.
// https://en.wikipedia.org/wiki/Topological_sorting#Kahn's_algorithm

#include <stdio.h>
#include <set>
#include <queue>

#define MAX 100001

using namespace std;

class Node {
    public:
    set<int> children;
    set<int> parents;

    void addChild(int c) {
        children.insert(c);
    }

    void addParent(int p) {
        parents.insert(p);
    }

    bool hasParents() {
        return !parents.empty();
    }
};

int main() {
    int n, m, a, b;

    while (scanf("%d %d", &n, &m)) {
        if (n == 0 && m == 0)
            break;

        Node nodes[MAX];
        bool hasIncoming[MAX] = { false };

        for (int i = 0; i < m; ++i) {
            scanf("%d %d", &a, &b);
            nodes[a].addChild(b);
            nodes[b].addParent(a);
            hasIncoming[b] = true;
        }
        queue<int> s;
        queue<int> l;

        for (int i = 1; i <= n; ++i) {
            if (!hasIncoming[i]) {
                s.push(i);
            }
        }

        while (!s.empty()) {
            int n = s.front();
            s.pop();
            l.push(n);
            for (int m : nodes[n].children) {
                nodes[m].parents.erase(n);
                if (!nodes[m].hasParents()) {
                    s.push(m);
                }
            }
        }

        if (l.size() != n) {
            printf("IMPOSSIBLE\n");
        } else {
            while (!l.empty()) {
                int c = l.front();
                l.pop();
                printf("%d\n", c);
            }
        }
    }

    return 0;
}