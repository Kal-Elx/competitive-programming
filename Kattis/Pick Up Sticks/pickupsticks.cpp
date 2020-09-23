// Kahn's algorithm.
// https://en.wikipedia.org/wiki/Topological_sorting#Kahn's_algorithm

#include <stdio.h>
#include <set>
#include <queue>

#define MAX 1000001

using namespace std;

class Node {
    public:
    set<int> children;
    set<int> parents;

    bool hasParents() {
        return !parents.empty();
    }
};

int n, m;
Node nodes[MAX];
bool hasIncoming[MAX] = { false };

void add(int to, int from) {
    nodes[to].children.insert(from);
    nodes[from].parents.insert(to);
}

void khans() {
    queue<int> s;

    for (int i = 1; i <= n; ++i) {
        if (!hasIncoming[i]) {
            s.push(i);
        }
    }

    while (!s.empty()) {
        int n = s.front();
        s.pop();
        printf("%d\n", n);
        for (int m : nodes[n].children) {
            nodes[m].parents.erase(n);
            if (!nodes[m].hasParents()) {
                s.push(m);
            }
        }
    }
}

int main() {
    int a, b;
    scanf("%d %d", &n, &m);

    int top = n;

    for (int i = 0; i < m && top > 0; ++i) {
        scanf("%d %d", &a, &b);
        add(a, b);
        top -= !hasIncoming[b];
        hasIncoming[b] = true;
    }

    if (top == 0) {
        printf("IMPOSSIBLE\n");
    } else {
        khans();
    }

    return 0;
}