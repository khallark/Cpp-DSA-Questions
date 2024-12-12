#include <iostream>
#include "AAAnode.h"
using namespace std;

pair<int, int> solve(Node *root) {
    if(root == nullptr) {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = solve(root->left);
    pair<int, int> right = solve(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    pair<int, int> ans;
    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second, right.second) + 1;
    return ans;
}
int diameter(Node* root) {
    return solve(root).first;
}

int main() {
    Node *root;
    root = build_from_level_order(root);
    // 1 4 6 2 3 9 10 -1 -1 8 -1 -1 -1 -1 -1 -1 -1
    cout << endl;
    cout << diameter(root) << endl;
    return 0;
}