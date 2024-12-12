#include "C:\Users\ABC\Documents\C++\Data structures\Binary Search Tree\AAABuild_Bst.h"
#include <limits.h>
using namespace std;
Node *solve(vector<int> pre, int &index, int min, int max) {
    int value = pre[index];
    if(!(value >= min && value <= max)) {
        return nullptr;
    }
    Node *temp = new Node(value);
    index++;
    temp->left = solve(pre, index, min, value);
    temp->right = solve(pre, index, value, max);
    return temp;
}
Node* preorderToBST(vector<int> &preorder) {
    int index = 0;
    Node *root = solve(preorder, index, INT_MIN, INT_MAX);
    return root;
}
int main() {
    vector<int> pre = {20, 10, 5, 15, 13, 35, 30, 42};
    Node *root = preorderToBST(pre);
    levelOrderTraversal(root);
    return 0;
}