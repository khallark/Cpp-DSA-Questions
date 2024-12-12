#include <iostream>
#include "AAAnode.h"
using namespace std;
pair<int, bool> solve(Node *root) {
    if(root == nullptr) {
        pair<int, bool> p = make_pair(0, true);
        return p;
    }
    if(root->left == nullptr && root->right == nullptr) {
        pair<int, bool> p = make_pair(1, true);
        return p;
    }

    pair<int, bool> left = solve(root->left);
    pair<int, bool> right = solve(root->right);

    int height = max(left.first, right.first) + 1;
    
    bool check;
    if(root->left == nullptr && root->right != nullptr) {
        check = right.first;
    }
    else if(root->left != nullptr && root->right == nullptr) {
        check = left.first;
    }
    else {
        check = left.second && right.second && (left.first == right.first);
    }

    pair<int, bool> ret;
    ret.first = height;
    ret.second = check;

    return ret;
}
bool check(Node *root) {
    return solve(root).second;
}
int main() {
    Node *root = build_from_level_order(root);
    // 13 13 -1 19 8 0 8 -1 -1 -1 -1 1 14 13 -1 -1 -1 -1 -1
    cout << endl << check(root) << endl;
    return 0;
}