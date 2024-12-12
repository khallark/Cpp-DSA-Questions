#include "AAAnode.cpp"
int f(Node* root, int cur) {
    if(!root) return 0;
    cur = cur * 10 + root->d;
    if(!root->left && !root->right) return cur;
    return f(root->left, cur) + 
            f(root->right, cur);
}
int sumNumbers(Node* root) {
    return f(root, 0); 
}
int main() {
    Node *root = nullptr;
    root = build_from_level_order(root);
    // 4 9 0 5 1 -1 -1 -1 -1 -1 -1
    cout << sumNumbers(root);
    return 0;
}