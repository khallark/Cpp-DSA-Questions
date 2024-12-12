#include <iostream>
#include <climits>
#include "AAAnode.cpp"
using namespace std;

// This is what I thought
bool solve1(Node *root, int &nodeVal) {
    if(root == nullptr) return true;

    bool left = solve1(root->left, nodeVal);
    bool node = nodeVal < root->d;
    nodeVal = root->d;
    bool right = solve1(root->right, nodeVal);

    return left && node && right;
}
bool ValidBST1(Node *root) {
    int nodeVal = INT_MIN;
    return solve1(root, nodeVal);
}


// Suggested {Range-Based} Solution
bool solve2(Node *root, pair<int, int> nodeVal) {
    if(root == nullptr) return true;

    bool left = solve2(root->left, {nodeVal.first, root->d});
    bool right = solve2(root->right, {root->d, nodeVal.second});

    bool node = (root->d > nodeVal.first && root->d < nodeVal.second);

    return left && node && right;
}
bool ValidBST2(Node *root) {
    pair<int, int> nodeVal = {INT_MIN, INT_MAX};
    return solve2(root, nodeVal);
}


int main() {
    Node *root = nullptr;
    root = build_from_level_order(root);
    // 5 1 6 -1 -1 4 8 -1 -1 -1 -1
    // 5 1 7 -1 -1 6 9 -1 -1 -1 -1
    // 7 2 9 1 5 8 10 -1 -1 3 6 -1 -1 -1 -1 -1 4 -1 -1 -1 -1
    cout << ValidBST1(root) << endl;
    cout << ValidBST2(root);
    return 0;
}