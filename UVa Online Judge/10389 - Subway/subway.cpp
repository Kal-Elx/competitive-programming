#include <iostream>
#include <sstream>
#include <math.h>
#include <vector>
#include <limits>

using namespace std;

struct node;
double dist(node* a, node* b);

struct edge {
    node* to;
    double cost;

    edge(node* n, double c) {
        to = n;
        cost = c;
    }
};

struct node {
    int x, y;
    double cost = numeric_limits<double>::infinity();
    vector<edge> edges;

    node(int a, int b) {
        x = a;
        y = b;
    }
};

void addEdge(node* from, node* to, bool subway = false) {
    double cost = subway ? dist(from, to)/4 : dist(from, to);
    edge e1(to, cost);
    from->edges.push_back(e1);
    edge e2(from, cost);
    to->edges.push_back(e2);
}

double dist(node* a, node* b) {
    return sqrt(pow((a->x - b->x), 2.0) + pow((a->y - b->y), 2.0));
}

// Dijkstra's algorithm
void dijkstra(node* from, node* to, const vector<node*>& nodes) {
    from->cost = 0;
    vector<node*> q;

    for (node* n : nodes)
        q.push_back(n);
    
    while (!q.empty()) {
        node* u = q.front();
        int i, r = 0;
        for (i = 1; i < q.size(); ++i)
            if (q[i]->cost < u->cost) {
                u = q[i];
                r = i;
            }

        q.erase(q.begin() + r);
        
        if (u == to) // Found optimal path
            return;

        for (edge e : u->edges) {
            node* v = e.to;
            double alt = u->cost + e.cost;
            if (alt < v->cost)
                v->cost = alt;
        }
    }
}

int main() {
    int testCases, a, b;
    cin >> testCases;
    cin.ignore(); // Blank line

    for (int i = 0; i < testCases; ++i) {
        if (i != 0)
            cout << '\n';

        vector<node*> nodes;

        cin >> a >> b;
        node *home = new node(a, b);
        nodes.push_back(home);

        cin >> a >> b;
        node *school = new node(a, b);
        nodes.push_back(school);

        string input;
        cin.ignore(); // Next line

        while(getline(cin, input)) {
            if (input.empty())
                break;

            istringstream tmp(input);
            bool first = true;

            while (tmp >> a >> b) {
                if (a == -1 && b == -1)
                    break;

                node* n = new node(a, b);
                if (!first)
                    addEdge(n, nodes.back(), true);
                
                nodes.push_back(n);
                first = false;
            }
        }

        for (int i = 0; i < nodes.size(); ++i)
            for (int j = i +1; j < nodes.size(); ++j)
                addEdge(nodes[i], nodes[j]);

        dijkstra(home, school, nodes);
        cout << round(3*(school->cost)/500) << '\n'; // Convert cost to minutes

        for (node* n : nodes)
            delete n;
    }

    return 0;
}