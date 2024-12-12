#include <iostream>
#include "AAAnode.cpp"
using namespace std;
Node *searchInBST(Node *root, int val) {
    while(root) {
        if(root->d == val) break;
        else if(root->d > val) root = root->left;
        else root = root->right;
    }
    return root;
}
int main() {
    Node *root = nullptr;
    cout << "- "; root = build_from_level_order(root);
    // 8 5 12 4 7 11 14 -1 -1 6 -1 -1 -1 13 -1 -1 -1 -1 -1
    Node *node = searchInBST(root, 10);
    if(node) cout << node->d;
    else cout << "NULL";
    return 0;
}