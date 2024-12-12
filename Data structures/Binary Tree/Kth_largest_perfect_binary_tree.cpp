#include <iostream>
#include <queue>
#include <vector>
#include "AAAnode.h"
using namespace std;


priority_queue<int, vector<int>, greater<int>> minH;

vector<int> solve(Node* root, int k) {
    if(!root) return {0, 0};
    if(!root->left && !root->right) {
        minH.push(1);
        if(minH.size() > k) minH.pop();
        return {1, 1};
    }
    vector<int> left = solve(root->left, k);
    vector<int> right = solve(root->right, k);
    if(left[0] && right[0]) {
        if(left[1] == right[1]) {
            minH.push(2 * left[1] + 1);
            if(minH.size() > k) minH.pop();
            return {1, 2 * left[1] + 1};
        }
    }
    return {0, 0};
}
int kthLargestPerfectSubtree(Node* root, int k) {
    solve(root, k);
    return (minH.size() < k) ? -1 : minH.top();
}


int main() {
    Node* root = nullptr;
    root = build_from_level_order(root);
    // 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    cout << kthLargestPerfectSubtree(root, 1);
    return 0;
}