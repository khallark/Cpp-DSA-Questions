#include <iostream>
#include <cmath>
#include "AAAnode.cpp"
using namespace std;
pair<int, bool> solve(Node *root) {
    if(root == nullptr) return {0, true};

    pair<int, int> left = solve(root->left);
    pair<int, int> right = solve(root->right);

    pair<int, int> ans;
    ans.first = max(left.first, right.first) + 1;
    ans.second = abs(left.first - right.first) <= 1 && left.second && right.second;

    return ans;
}
bool isBalanced(Node* root) {
    return solve(root).second;
}
int main() {
    Node *root = nullptr;
    root = build_from_level_order(root);
    cout << endl;
    cout << isBalanced(root);
    // 1 2 3 4 5 8 9 -1 -1 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    return 0;
}