#include <iostream>
#include "AAAnode.cpp"
using namespace std;
bool solve(Node *root, int n1, int n2, int &ans) {
    if(root == nullptr) {
        return false;
    }
    if(root->d == n1 || root->d == n2) {
        ans = root->d;
        return true;
    }

    int left = solve(root->left, n1, n2, ans);
    int right = solve(root->right, n1, n2, ans);

    if(left && right) {
        ans = root->d;
    }

    return left || right;
}
int LCA(Node *root, int n1, int n2) {
    int ans = 0;
    solve(root, n1, n2, ans);
    return ans;
}
int main() {
    Node *root = nullptr;
    root = build_from_level_order(root);
    cout << endl;
    cout << LCA(root, 4, 9);
    // 1 2 3 4 5 8 9 -1 -1 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    return 0;
}