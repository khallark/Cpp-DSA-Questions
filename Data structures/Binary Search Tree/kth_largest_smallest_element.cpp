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
pair<int, int> kth_smallest_largest_elements(Node *root, int k) {
    vector<int> v;
    inorder(root, v);
    return make_pair(v[k - 1], v[v.size() - (k - 1) - 1]);
}
int main() {
    vector<int> v = {50, 27, 60, 15, 35, 80, 10, 30, 40, 70, 29, 32};
    Node *root = nullptr;
    root = build_bst(root, v);
    pair<int, int> p = kth_smallest_largest_elements(root, 12);
    cout << p.first << ", " << p.second << endl;
    return 0;
}