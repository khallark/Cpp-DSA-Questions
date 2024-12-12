#include <iostream>
#include <cmath>
#include "AAAnode.cpp"
using namespace std;
typedef Node TreeNode;
int getLeftHeight(TreeNode *root) {
    int ans = 0;
    while(root) {
        root = root->left;
        ans++;
    }
    return ans;
}
int getRightHeight(TreeNode *root) {
    int ans = 0;
    while(root) {
        root = root->right;
        ans++;
    }
    return ans;
}
int countNodes(TreeNode* root) {
    if(root == nullptr) return 0;
    int leftH = getLeftHeight(root->left);
    int rightH = getRightHeight(root->right);
    if(leftH == rightH) {
        return 1 + (pow(2, leftH) - 1) * 2;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}
int main() {
    Node *root = nullptr;
    cout << "INPUT :- ";
    root = build_from_level_order(root);
    // 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
    cout << "ANS :- " << countNodes(root);
    return 0;
}