#include <iostream>
#include "AAAnode.h"
using namespace std;
void mirror(Node* node) {
    if(node == nullptr) {
        return;
    }

    Node *temp = node->left;
    node->left = node->right;
    node->right = temp;

    mirror(node->left);
    mirror(node->right);
}
void inorder_recursive(Node *root) { // Print in order (Left-Current-Right)
    if(root == nullptr) return;
    inorder_recursive(root->left); //left
    cout << root->d << " "; // node
    inorder_recursive(root->right); // right
}
int main() {
    Node *root;
    root = build_from_level_order(root);
    // 2 5 4 6 1 7 -1 -1 -1 -1 -1 -1 -1
    // 1 -1 2 -1 3 -1 4 -1 -1
    cout << endl << "Original     : ";
    inorder_recursive(root);
    mirror(root);
    cout << endl << "Mirror Image : ";
    inorder_recursive(root);
    return 0;
}