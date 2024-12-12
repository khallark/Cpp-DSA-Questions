#include "AAABuild_Bst.h"
using namespace std;
int min_in_bst(Node *root) {
    while(root->left) root = root->left;
    return root->data;
}
int max_in_bst(Node *root) {
    while(root->right) root = root->right;
    return root->data;
}
int main() {
    vector<int> v = {5, 4, 6, 3, 7, 2, 8, 1, 9};
    Node *root = nullptr;
    root = build_bst(root, v);
    cout << max_in_bst(root) << endl;
    return 0;
}