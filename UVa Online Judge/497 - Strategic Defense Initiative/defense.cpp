#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct node {
    int val;
    node* parent;
    vector<node*> children;
};

bool add(node* curr, int val) {
    if (curr->val < val) {
        bool added = false;
        for (node* child : curr->children)
            if (add(child, val))
                added = true;
        if (!added) {
            node* n = new node;
            n->val = val;
            n->parent = curr;
            curr->children.push_back(n);
        }
        return true;
    }
    return false;
}

node* lowest;
int max_depth = 0;

void dfs (node* tree, int depth = 0) {
    for (node* child : tree->children)
        dfs(child, depth+1);
    if (tree->children.empty()) { // is leaf
        if (depth > max_depth) {
            max_depth = depth;
            lowest = tree;
        }
    }
}

void reset(node* tree) {
    for (node* child : tree->children)
        reset(child);
    delete tree;
}

int main() {
    int testCases;
    cin >> testCases;
    cin.ignore();
    cin.ignore(); // Blank line

    for (int i = 0; i < testCases; ++i) {
        if (i != 0)
            cout << '\n';

        node* tree = new node;
        tree->val = -1;
        string input;

        while (getline(cin, input)) {
            if (input.empty())
                break;
            add(tree, stoi(input));
        }
        dfs(tree);

        vector<int> heights;
        node* curr = lowest;
        while (curr != tree) {
            heights.push_back(curr->val);
            curr = curr->parent;
        }

        cout << "Max hits: " << max_depth << endl;
        for (vector<int>::reverse_iterator i = heights.rbegin(); i != heights.rend(); ++i)
            cout << *i << endl;

        reset(tree);
        max_depth = 0;
        lowest = nullptr;
    }

    return 0;
}