#include "AAABuild_Bst.h"
#include <limits.h>
using namespace std;
bool isBSTutil(Node *root, int min, int max) {
    if(root == nullptr) {
        return true;
    }
    if(root->data < min || root->data > max) {
        return false;
    }
    return isBSTutil(root->left, min, root->data - 1) && isBSTutil(root->right, root->data - 1, max);
}
bool validate_bst(Node *root) {
    return isBSTutil(root, INT_MIN, INT_MAX);
}
int main() {
    Node *root = build_from_level_order(root);
    // 10 5 18 2 9 15 19 -1 4 8 -1 8 -1 -1 -1 -1 -1 -1 -1 -1 -1
    inorder_recursive(root);
    cout << endl << validate_bst(root) << endl;
    return 0;
}