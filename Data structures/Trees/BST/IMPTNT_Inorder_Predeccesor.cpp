#include "AAAnode.cpp"
#include <climits>
using namespace std;

Node * InorderSuccesor(Node *root, int node) {
    Node *ans = nullptr;
    while(root->d != node) {
        if(root->d > node) root = root->left;
        else ans = root, root = root->right;
    }
    if(root->left) {
        root = root->left;
        while(root->right) root = root->right;
        ans = root;
    }
    return ans;
}

int main() {
    Node *root = nullptr;
    root = build_from_level_order(root);
    // 5 3 7 2 4 6 9 1 -1 -1 -1 -1 -1 8 10 -1 -1 -1 -1 -1 -1
    root = InorderSuccesor(root, 10);
    if(root) cout << root->d;
    else cout << -1;
    return 0;
}