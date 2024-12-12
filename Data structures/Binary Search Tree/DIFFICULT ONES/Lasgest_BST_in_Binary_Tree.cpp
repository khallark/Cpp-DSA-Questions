#include "C:\Users\ABC\Documents\C++\Data structures\Binary Tree\AAAnode.h"
int solve(Node *root) {
    if(root == nullptr) {
        return 0;
    }

    int left = solve(root->left);
    int right = solve(root->right);

    bool check = (left % 10 == 0) && 
                 (right % 10 == 0) && 
                 (root->left == nullptr || root->left->d < root->d) && 
                 (root->right == nullptr || root->right->d > root->d);

    left /= 10;
    right /= 10;

    if(check) {
        return (left + right + 1) * 10;
    }
    else {
        return (max(left, right) * 10) + 1;
    }
}
int largestBst(Node *root) {
    return solve(root) / 10;
}
int main() {
    Node *root = build_from_level_order(root);
    // 6 6 3 -1 2 9 -1 -1 8 8 2 -1 -1 -1 -1 -1 -1
    // 14 50 20 60 -1 16 25 -1 40 15 -1 24 26 -1 -1 -1 -1 -1 -1 -1 -1
    // 11 16 12 12 18 7 15 -1 -1 17 21 -1 -1 13 20 -1 -1 20 -1 -1 -1 -1 -1 -1 -1
    cout << endl << largestBst(root) << endl;
    return 0;
}