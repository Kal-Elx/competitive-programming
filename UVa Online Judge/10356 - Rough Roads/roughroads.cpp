//https://stackoverflow.com/questions/32722448/shortest-path-with-even-number-of-edges

#include <stdio.h>
#include <vector>
#include <limits>

using namespace std;

struct edge {
    int dest;
    int cost;
    edge(int d, int c) {
        dest = d;
        cost = c;
    }
};

struct node {
    int dist = numeric_limits<int>::max();
    vector<edge> edges;
};

void dijkstra(int dest, node* nodes) {
    int res = -1;
    vector<int> q;
    q.push_back(0);
    nodes[0].dist = 0;

    while(!q.empty()) {
        int u = q.front();
        
        int i, r = 0;
        for (i = 1; i < q.size(); ++i)
            if (nodes[q[i]].dist < nodes[u].dist) {
                u = q[i];
                r = i;
            }
        q.erase(q.begin() + r);

        if (u == dest)
            break;

        for (edge e : nodes[u].edges) {
            int alt = nodes[u].dist + e.cost;
            if (alt < nodes[e.dest].dist) {
                nodes[e.dest].dist = alt;
                q.push_back(e.dest);
            }
        }
    }
}

int main() {
    int n, r, a, b, c, t = 0;
    while(scanf("%d %d", &n, &r) != EOF) {
        node nodes[2*n];
        for (int i = 0; i < r; ++i) {
            scanf("%d %d %d", &a, &b, &c);
            nodes[a].edges.push_back(edge(b+n,c));
            nodes[a+n].edges.push_back(edge(b,c));
            nodes[b].edges.push_back(edge(a+n,c));
            nodes[b+n].edges.push_back(edge(a,c));
        }
        dijkstra(n-1, nodes);
        printf("Set #%d\n", ++t);
        if (nodes[n-1].dist != numeric_limits<int>::max())
            printf("%d\n", nodes[n-1].dist);
        else
            printf("?\n");
    }
    return 0;
}