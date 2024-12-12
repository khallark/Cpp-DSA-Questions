#include <iostream>
#include "AAAnode.cpp"
using namespace std;
int FloorInBST(Node *root, int val) {
    int ans = -1;
    while(root) {
        if(root->d == val) {
            ans = val;
            break;
        }
        else if(root->d > val) root = root->left;
        else ans = root->d, root = root->right;
    }
    return ans;
}
int main() {
    Node *root = nullptr;
    cout << "- "; root = build_from_level_order(root);
    // 10 5 13 3 6 11 14 2 4 -1 9 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
    int node = FloorInBST(root, 12);
    cout << node;
    return 0;
}