#include <iostream>
#include "AAAnode.cpp"
using namespace std;
void changeTree(Node *root) {
    if(root == nullptr) return;

    int childrenSum = 0;
    if(root->left) childrenSum += root->left->d;
    if(root->right) childrenSum += root->right->d;
    if(childrenSum >= root->d) root->d = childrenSum;
    else {
        if(root->left) root->left->d = root->d;
        if(root->right) root->right->d = root->d;
    }

    changeTree(root->left), changeTree(root->right);

    int tot = 0;
    if(root->left) tot += root->left->d;
    if(root->right) tot += root->right->d;
    if(root->left || root->right) root->d = tot;
}
int main() {
    Node *root = nullptr;
    root = build_from_level_order(root);
    // 40 10 20 2 5 30 40
    changeTree(root);
    return 0;
}