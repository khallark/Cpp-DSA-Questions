#include <iostream>
#include <climits>
#include "AAAnode.cpp"
using namespace std;

int LCA_in_BST(Node *root, int n1, int n2) {
    int LCA;
    int smaller = n1 < n2 ? n1 : n2;
    int bigger = n1 > n2 ? n1 : n2;
    
    while(root) {
        if(root->d >= smaller && root->d <= bigger) {
            LCA = root->d;
            break;
        }
        else if(root->d > bigger) root = root->left;
        else root = root->right;
    }

    return LCA;
}


int main() {
    Node *root = nullptr;
    root = build_from_level_order(root);
    // 6 2 8 0 4 7 9 -1 -1 3 5 -1 -1 -1 -1 -1 -1 -1 -1
    // 10 4 13 3 8 11 15 1 -1 6 9 -1 -1 -1 -1 -1 2 5 7 -1 -1 -1 -1 -1 -1 -1 -1
    cout << LCA_in_BST(root, 9, 5);
    return 0;
}