#include <matrix.h>
#include "AAAnode.cpp"
using namespace std;
vector<int> morrisInorderTraversal(Node *root) {
    vector<int> inorder;
    Node *curr = root;

    while(curr != nullptr) {
        if(curr->left == nullptr) {
            inorder.push_back(curr->d);
            curr = curr->right;
        }
        else {
            Node *prev = curr->left;
            while(prev->right != nullptr && prev->right != curr) {
                prev = prev->right;
            }

            if(prev->right == nullptr) {
                prev->right = curr;
                curr = curr->left;
            }
            else {
                prev->right = nullptr;
                inorder.push_back(curr->d);
                curr = curr->right;
            }
        }
    }
    
    return inorder;
}
vector<int> morrisPreorderTraversal(Node *root) {
    vector<int> inorder;
    Node *curr = root;

    while(curr != nullptr) {
        if(curr->left == nullptr) {
            inorder.push_back(curr->d);
            curr = curr->right;
        }
        else {
            Node *prev = curr->left;
            while(prev->right != nullptr && prev->right != curr) {
                prev = prev->right;
            }

            if(prev->right == nullptr) {
                prev->right = curr;
                inorder.push_back(curr->d);
                curr = curr->left;
            }
            else {
                prev->right = nullptr;
                curr = curr->right;
            }
        }
    }
    
    return inorder;
}
int main() {
    Node *root = nullptr;
    root = build_from_level_order(root);
    // 1 4 2 8 12 10 5 -1 6 3 13 7 14 9 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 11 -1 -1 -1 -1
    // 2 5 11 6 1 4 13 -1 -1 7 9 -1 -1 3 -1 -1 -1 8 10 12 -1 -1 -1 -1 14 -1 -1 -1 -1
    cout << morrisInorderTraversal(root) << morrisPreorderTraversal(root);
    return 0;
}
