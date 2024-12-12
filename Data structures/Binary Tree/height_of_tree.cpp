#include <iostream>
#include "AAAnode.h"
using namespace std;

int maxDepth(Node *root) {
    if(root == nullptr) {
        return 0;
    }
    int val1 = maxDepth(root->left);
    int val2 = maxDepth(root->right);

    return max(val1, val2) + 1;
}
int main() {
    Node *root;
    root = build_from_level_order(root);
    // 1 4 6 2 3 9 -1 -1 -1 8 -1 -1 -1 -1 -1
    cout << endl;
    cout << maxDepth(root) << endl;
    return 0;
}