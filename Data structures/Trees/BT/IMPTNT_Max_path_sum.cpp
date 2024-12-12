#include <iostream>
#include <climits>
#include "AAAnode.cpp"
using namespace std;

pair<int, int> solve(Node *root) {
    if(root->left == nullptr && root->right == nullptr)
        return {root->d, root->d};
    
    pair<int, int> left;
    pair<int, int> right;
    pair<int, int> ans;

    if(root->left != nullptr && root->right == nullptr) {
        left = solve(root->left);
        ans.first = max(root->d, left.first + root->d);
        ans.second = max(root->d, max(left.second, left.first + root->d));
    }
    else if(root->left == nullptr && root->right != nullptr) {
        right = solve(root->right);
        ans.first = max(root->d, right.first + root->d);
        ans.second = max(root->d, max(right.second, right.first + root->d));
    }
    else {
        left = solve(root->left);
        right = solve(root->right);
        ans.first = max(root->d, max(left.first, right.first) + root->d);
        ans.second = max(max(root->d, root->d + left.first + right.first), max(max(left.second, right.second), root->d + max(left.first, right.first)));
    }
    
    return ans;
}

int maxPathSum(Node *root) {
    return solve(root).second;
}

int main() {
    Node *root = nullptr;
    cout << "INPUT - ";
    root = build_from_level_order(root);
    // 3 4 6 5 8 8 7 -1 -1 10 -1 -1 -1 -1 -1 -1 -1
    cout << maxPathSum(root) << endl;
    return 0;
}