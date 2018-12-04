#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>

using namespace std;

struct Vertex {
    Vertex* parent = nullptr;
    vector<Vertex*> children;
    int marbles;
    bool complete = false; // all children have exactly one marble
};

int main() {

    int n, v, m, d, c;

    while (cin >> n) {
        if (n == 0)
            break;
        vector<Vertex> boxes(n);
        queue<Vertex*> queue;

        for (int i = 0; i < n; ++i) {
            cin >> v >> m >> d;
            Vertex& box = boxes[i];
            box.marbles = m;
            if (d == 0) // is leaf
                queue.push(&box);
            for (int j = 0; j < d; ++j) {
                cin >> c;
                boxes[c-1].parent = &box;
                box.children.push_back(&boxes[c-1]);
            }
        }
        int counter = 0;
        while (!queue.empty()) { 
            Vertex* curr = queue.front();

            int diff = curr->marbles - 1;
            curr->marbles = 1;
            curr->complete = true;
            curr->parent->marbles += diff;
            counter += abs(diff);

            bool subtreeComplete = true;
            for (Vertex* sibling : curr->parent->children)
                if (!sibling->complete) {
                    subtreeComplete = false;
                    break;
                }
            if (subtreeComplete && curr->parent->parent != nullptr) {
                queue.push(curr->parent);
            }
            queue.pop();
        }
        cout << counter << '\n';
    }

    return 0;
}