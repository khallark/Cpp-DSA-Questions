#include <iostream>
#include "AAAnode.h"
using namespace std;
pair<bool, int> solve(Node *root) {
    if(root == nullptr) {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    
    pair<bool, int> left = solve(root->left);
    pair<bool, int> right = solve(root->right);

    pair<bool, int> p;
    p.first = left.first && right.first && abs(left.second - right.second) <= 1;
    p.second = max(left.second, right.second) + 1;
    return p;
}
bool isBalanced(Node *root) {
    solve(root).first;
}
int main() {
    Node *root;
    root = build_from_level_order(root);
    // 10 20 -1 40 60 -1 -1 -1 -1
    cout << endl;
    cout << isBalanced(root) << endl;
    return 0;
}