#include <iostream>
#include "AAAnode.cpp"
using namespace std;

pair<int, int> solve(Node *root) {
    if(root == nullptr) return {0, 0};

    pair<int, int> left = solve(root->left);
    pair<int, int> right = solve(root->right);

    pair<int, int> ans;
    ans.first = max(left.first, right.first) + 1;
    int diameter = left.first + right.first + 1;
    ans.second = max(diameter, max(left.second, right.second));

    return ans;
}

int maxDiameter(Node *root) {
    return solve(root).second;
}

int main() {
    Node *root = nullptr;
    cout << "INPUT - ";
    root = build_from_level_order(root);
    // 1 2 3 -1 -1 4 5 6 -1 7 -1 8 9 10 11 -1 -1 -1 -1 -1 -1 -1 -1
    // 1 2 3 4 -1 -1 5 6 -1 -1 7 8 -1 -1 9 10 -1 -1 11 12 -1 -1 13 14 -1 -1 15 -1 -1 -1 -1
    cout << maxDiameter(root) << endl;
    return 0;
}