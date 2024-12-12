#include "AAAnode.cpp"
#include <climits>
using namespace std;

Node * InorderSuccesor(Node *root, int node) {
    Node *ans = nullptr;
    while(root->d != node) {
        if(root->d > node) ans = root, root = root->left;
        else root = root->right;
    }
    if(root->right) {
        root = root->right;
        while(root->left) root = root->left;
        ans = root;
    }
    return ans;
}

int main() {
    Node *root = nullptr;
    root = build_from_level_order(root);
    // 5 3 7 2 4 6 9 1 -1 -1 -1 -1 -1 8 10 -1 -1 -1 -1 -1 -1
    root = InorderSuccesor(root, 1);
    if(root) cout << root->d;
    else cout << -1;
    return 0;
}