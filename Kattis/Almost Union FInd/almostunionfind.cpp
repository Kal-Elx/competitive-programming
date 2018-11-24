/*
 * Inspiration from
 * https://www.ida.liu.se/opendsa/OpenDSA/Books/TDDD86F18/html/UnionFind.html
 */

#include <iostream>

unsigned size = 0;
unsigned nodes[200001];
unsigned long long sum[100001]; // Need to hold max 5000050000

void initNodes() {
    for (unsigned i = 1, j = size + 1; i <= size; ++i, ++j) {
        nodes[i] = j; // Nodes are initialized with a parent
        nodes[j] = 1; // Node count is stored in parent
        sum[i] = i; // Sum of nodes stored in sum[root - size]
    }
}

unsigned find(unsigned p) {
    if (p > size && nodes[p] <= size) // If root and containing count
        return p;
    while (p <= size || nodes[p] > size) {
        p = nodes[p];
    }
    return p;
}

void unionTrees(unsigned p, unsigned q) {
    unsigned root1 = find(p);
    unsigned root2 = find(q);
    if (root1 != root2) {
        nodes[root2] += nodes[root1]; // Update count
        sum[root2-size] += sum[root1-size]; // Update sum
        nodes[root1] = root2; // Union trees
    }
}

void move(unsigned p, unsigned q) {
    unsigned root1 = find(p);
    unsigned root2 = find(q);
    if (root1 != root2) {
        --nodes[root1]; // Update count
        ++nodes[root2]; // Update count
        sum[root2 - size] += p; // Update sum
        sum[root1 - size] -= p; // Update sum
        nodes[p] = root2; // Move p
    }
}

void output(unsigned p) {
    unsigned root = find(p);
    std::cout << nodes[root] << ' ' << sum[root-size] << '\n';
}

int main()
{
    unsigned commands, operation, p, q;

    while (std::cin >> size >> commands) {

        initNodes();

        for (unsigned i = 0; i < commands; ++i) {
            std::cin >> operation;

            if (operation != 3) {
                std::cin >> p >> q;
                if (operation == 1)
                    unionTrees(p, q);
                else
                    move(p, q);
            } else {
                std::cin >> p;
                output(p);
            }
        }
    }
    return 0;
}