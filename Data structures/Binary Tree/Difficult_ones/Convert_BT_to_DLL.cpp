#include <iostream>
#include "C:\Users\ABC\Documents\C++\Data structures\Binary Tree\AAAnode.h"
using namespace std;
pair<Node*, Node*> solve(Node *root) {
    // Base case
    if(root == nullptr) {
        pair<Node*, Node*> p = make_pair(nullptr, nullptr);
        return p;
    }

    // Collects the head and tail of the left and right DLLs.
    pair<Node*, Node*> left = solve(root->left);
    pair<Node*, Node*> right = solve(root->right);

    // Joins the current node with left and right DLLs.
    root->left = left.second;
    if(left.second) left.second->right = root;

    root->right = right.first;
    if(right.second) right.first->left = root;

    // Returns the head and tail of the combined DLL.
    pair<Node*, Node*> ret_pair;
    ret_pair.first = left.first ? left.first : root;
    ret_pair.second = right.second ? right.second : root;

    return ret_pair;
}
Node *bToDLL(Node *root) {
    return solve(root).first; // Returns the head of the DLL.
}
int main() {
    Node *root = build_from_level_order(root);
    // 1 2 3 4 5 6 7 -1 -1 8 -1 -1 -1 -1 -1 -1 -1
    root = bToDLL(root);
    cout << endl;
    while(root) {
        cout << root->d << " ";
        root = root->right;
    }
    return 0;
}