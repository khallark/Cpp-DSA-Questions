#include <iostream>
#include "AAAnode.h"
using namespace std;
pair<bool, int> solve(Node *root) {
    if(root == nullptr) {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    if(root->left == nullptr && root->right == nullptr) {
        pair<bool, int> p = make_pair(true, root->d);
        return p;
    }
    pair<bool, int> left = solve(root->left);
    pair<bool, int> right = solve(root->right);

    pair<bool, int> ans;
    ans.first = (left.first) && (right.first) && (left.second + right.second == root->d);
    ans.second = left.second + right.second + root->d;
    
    return ans;
}
bool isSumTree(Node* root) {
    return solve(root).first; 
}
int main() {
    Node *root;
    root = build_from_level_order(root);
    cout << endl << isSumTree(root) << endl;
    return 0;
}