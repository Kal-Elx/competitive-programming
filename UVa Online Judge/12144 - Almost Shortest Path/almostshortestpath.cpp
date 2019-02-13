#include <iostream>
#include <vector>
#include <limits>
#include <utility>

using namespace std;

struct node;

struct edge {
    node *to;
    int dist;
    bool inShortestPath = false;

    edge(node *n, int d) {
        to = n;
        dist = d;
    }
};

struct node {
    int cost;
    vector<edge> edges;
    vector<pair<node*, edge*>> prev; // Optimal paths to node
};

int dijkstra(node *from, node *to, const vector<node*>& graph) {
    vector<node*> q;
    bool foundPath = false;

    for (node *n : graph) {
        n->cost = numeric_limits<int>::max();
        n->prev.clear();
        q.push_back(n);
    }

    from->cost = 0;

    while (!q.empty()) {
        node *u = q.front();

        int i, r = 0;
        for (i = 1; i < q.size(); ++i)
            if (q[i]->cost < u->cost) {
                u = q[i];
                r = i;
            }
        q.erase(q.begin() + r);

        // No path exists
        if (u->cost == numeric_limits<int>::max())
            break;

        if (u == to) {
            foundPath = true;
            break;
        }

        for (edge &e : u->edges) {
            if (e.inShortestPath)
                continue;

            node *v = e.to;

            int alt = u->cost + e.dist;
            if (alt < v->cost) {
                v->cost = alt;
                v->prev.clear();
                v->prev.push_back(make_pair(u, &e));
            } else if (alt == v->cost) {
                v->prev.push_back(make_pair(u, &e));
            }
        }
    }
    return foundPath ? to->cost : -1;
}

void markForbiddenNodes(node *from, node *to) {
    if (to != from) {
        for (pair<node*, edge*> p : to->prev) {
            if (p.second->inShortestPath)
                break;
            p.second->inShortestPath = true;
            markForbiddenNodes(from, p.first);
        }
    }
}

int main() {
    int N, M, S, D, U, V, P;
    while (cin >> N >> M) {
        if (N == 0 && M == 0)
            break;
        cin >> S >> D;

        vector<node*> nodes(N);
        for (int i = 0; i < N; ++i)
            nodes[i] = new node;
            
        for (int i = 0; i < M; ++i) {
            cin >> U >> V >> P;
            edge e(nodes[V], P);
            nodes[U]->edges.push_back(e);
        }

        node *from = nodes[S], *to = nodes[D];
        
        int shortest = dijkstra(from, to, nodes);
        int ret = shortest;

        if (shortest != -1) {
            markForbiddenNodes(from, to);
            ret = dijkstra(from, to, nodes);
        }
        
        cout << ret << endl;

        for (node *n : nodes)
            delete n;
    }
    return 0;
}