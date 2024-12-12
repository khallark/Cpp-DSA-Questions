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
Node *delete_node_bst(Node *root, int value) {
    if(root == nullptr) {
        return root;
    }
    if(root->data == value) {
        // 0 child case
        if(root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }

        // 1 child case
        else if(root->left != nullptr && root->right == nullptr) { // only left child exists
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else if(root->left == nullptr && root->right != nullptr) { // only right child exists
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // 2 children case
        else {
            // Delete MINIMUM from RIGHT
            root->data = min_in_bst(root->right);
            root->right = delete_node_bst(root->right, root->data);
            return root;

            // Delte MAXIMUM from LEFT
            // root->data = min_in_bst(root->left);
            // root->left = delete_node_bst(root->left, root->data);
            // return root;
        }
    }
    else if(root->data > value) {
        root->left = delete_node_bst(root->left, value);
    }
    else {
        root->right = delete_node_bst(root->right, value);
    }
    return root;
}
int main() {
    vector<int> v = {5, 4, 6, 3, 7, 2, 8, 1, 9};
    Node *root = nullptr;
    root = build_bst(root, v);
    delete_node_bst(root, 5);
    return 0;
}
