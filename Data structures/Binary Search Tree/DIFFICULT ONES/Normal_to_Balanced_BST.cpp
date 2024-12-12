#include "AAABuild_Bst.h"
using namespace std;
void inorder(Node *root, vector<int>& v) {
    if(root == nullptr) {
        return;
    }
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}
Node *build_BST_from_inorder(vector<int> v, int s, int e) {
    if(s > e) {
        return nullptr;
    }

    int mid = s + (e - s) / 2;
    Node *temp = new Node(v[mid]);

    temp->left = build_BST_from_inorder(v, s, mid - 1);
    temp->right = build_BST_from_inorder(v, mid + 1, e);

    return temp;
}
Node* buildBalancedTree(Node* root) {
    vector<int> v;
    inorder(root, v);
    root = build_BST_from_inorder(v, 0, v.size() - 1);
    return root;
}
int main() {
    Node *root = nullptr;
    vector<int> v = {10, 8, 12, 4, 16, 2, 20};
    root = build_bst(root, v);
    levelOrderTraversal(root);
    root = buildBalancedTree(root);
    cout << endl;
    levelOrderTraversal(root);
    cout << endl;
    return 0;
}