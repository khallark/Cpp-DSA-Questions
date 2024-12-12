#include <iostream>
#include "AAAnode.cpp"
using namespace std;


void solve1(Node *root, int &k, int &ans) {
    if(root == nullptr || k == 0) return;
    solve1(root->left, k, ans);
    if(--k == 0) ans = root->d;
    solve1(root->right, k, ans);
}
int kthSmallestElement(Node *root, int k) {
    int ans = -1;
    solve1(root, k, ans);
    return ans;
}


void solve2(Node *root, int &k, int &ans) {
    if(root == nullptr || k == 0) return;
    solve2(root->right, k, ans);
    if(--k == 0) ans = root->d;
    solve2(root->left, k, ans);
}
int kthLargestElement(Node *root, int k) {
    int ans = -1;
    solve2(root, k, ans);
    return ans;
}

int main() {
    Node *root = nullptr;
    cout << "- "; root = build_from_level_order(root);
    // 5 3 7 1 4 6 8 -1 2 -1 -1 -1 -1 -1 -1 -1 -1
    cout << kthSmallestElement(root, 6) << endl;
    cout << kthLargestElement(root, 3);
    return 0;
}