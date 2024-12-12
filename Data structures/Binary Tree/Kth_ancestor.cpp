#include <iostream>
#include "AAAnode.h"
using namespace std;
bool solve(Node *root, int &k, int node, int& ans) {
    if(root == nullptr) {
        return false;
    }
    if(root->d == node) {
        return true;
    }

    bool check1 = solve(root->left, k, node, ans);
    bool check2 = solve(root->right, k, node, ans);

    if((check1 || check2) && k != 0) {
        ans = root->d;
        k--;
    }

    return check1 || check2;
}
int kthAncestor(Node *root, int k, int node) {
    int ans;
    solve(root, k, node, ans);
    return k != 0 ? -1 : ans;
}
int main() {
    Node *root = build_from_level_order(root);
    // 1 2 3 4 5 -1 6 -1 -1 7 -1 8 9 -1 10 11 -1 -1 -1 -1 -1 -1 -1
    cout << endl << kthAncestor(root, 3, 10) << endl;
    return 0;
}