#include "AAABuild_Bst.h"
using namespace std;
int main() {
    Node *root = nullptr;
    vector<int> values = {7, 4, 9, 2, 5, 3, 8, 1, 6, 0};
    root = build_bst(root, values);
    cout << "Level Order : ";
    levelOrderTraversal(root);
    cout << endl << "InOrder     : ";
    inorder_recursive(root);
    cout << endl << "PreOrder    : ";
    PreOrder_recursive(root);
    cout << endl << "PostOrder   : ";
    PostOrder_recursive(root);
    return 0;
}