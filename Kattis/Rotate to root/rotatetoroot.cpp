#include <stdio.h>
#include <algorithm>

using namespace std;

struct Node {
    int index, height = 0;
    Node *left = nullptr, *right = nullptr;
};

Node nodes[100000];
Node *root;
int output[100000];

int calcHeight(Node* node) {
    if (node == nullptr)
        return 0;
    if (node->height == 0)
        node->height = 1 + max(calcHeight(node->left), calcHeight(node->right));
    if (node->height > root->height)
        root = node;
    return node->height;
}

int height(Node* node) {
    return node != nullptr ? node->height : 0;
}

int largest(int a, int b, int c, int d) {
    return max(max(a, b), max(c, d));
}

void preorder(Node* node, int leftHeight = 0, int rightHeight = 0, int leftRotations = 0, int rightRotations = 0) {
    if (node == nullptr)
        return;
    output[node->index] = 1 + largest(leftHeight, rightHeight, height(node->left) + leftRotations, height(node->right) + rightRotations);
    preorder(node->left, leftHeight, max(rightHeight, height(node->right) + rightRotations + 1), leftRotations, rightRotations + 1);
    preorder(node->right, max(leftHeight, height(node->left) + leftRotations + 1), rightHeight, leftRotations + 1, rightRotations);
}

int main() {
    int n, l, r;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &l, &r);
        Node& curr = nodes[i];
        curr.index = i;
        if (l != 0) curr.left = &nodes[l-1];
        if (r != 0) curr.right = &nodes[r-1];
    }

    root = &nodes[0]; // Changed by calcHeight()

    for (int i = 0; i < n; ++i)
        calcHeight(&nodes[i]);

    preorder(root);

    for (int i = 0; i < n; ++i)
        printf("%d\n", output[i]);
    
    return 0;
}